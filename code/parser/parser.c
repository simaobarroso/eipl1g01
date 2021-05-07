#include "../control_types.h"
#include "parser.h"
#include "../operations/operations.h"
#include "../stack/stack.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Tamanho de qualquer estrutura a que se dê parse
 */
#define SIZE 8192

/**
 * \brief Linha genérica de verificação de existência de space para avançar
 */
#define PARSE_SPACE if (isspace(*line)) line++;

void parser(Stack stack, char* line, OperatorFunction* hashtable, Container* vars) {
    while (*line) {
        // para nums
        if (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(line[1])))
            line = number_parse(stack,line);

        // para var
        else if (isupper(*line) || *line == ':')
            line = var_control(stack,line,vars);

        // para string/array/bloco
        else if (strspn(line,"[{\""))
            line = structure_parse(stack,line,hashtable,vars);

        else 
            line = parse_hash(stack,line,hashtable,vars);

        PARSE_SPACE
    }
}

char* number_parse(Stack stack,char* line) {
    Container res;
    char* num;
    char* end;
    int is_float = number_string(&line,&num,&end);
    line = end;

    if (line[1] == 's') { // converte imediatamente para string
        res.label = String;
        res.STRING = strdup(num);
        line+=2;
    
    } else if (is_float) {  // verifica se é float
        res.label = Double;
        res.DOUBLE = strtof(num,&end);

    } else {  // acontece se for long
        res.label = Long;
        res.LONG = strtol(num,&end,10);
    }
    push(res,stack);
    return line;
}

char* var_control(Stack s,char* line,Container* vars) {
    if (isupper(*line)) push(vars[*line++ - 'A'],s);
    else vars[*(++line) - 'A'] = s->arr[s->sizeofstack - 1];
    if (*line != '/') line++;
    return line;
}

char* structure_parse(Stack stack,char* line,OperatorFunction* hashtable,Container* vars) {
    switch(*line) {
        case '[': line = array_parse(stack,line,hashtable,vars); break;
        case '{': line = block_parse(stack,line); break;
        case '"': line = string_parse(stack,line); break;
        default: ERROR_1
    }
    return line;
}

char* array_parse(Stack stack, char* line, OperatorFunction* hashtable, Container* vars) {
    int arr = 1;
    char* save = line+=2;

    while(arr) {
        if (*line == '[') arr++;
        if (*line == ']') arr--;
        line++;
    }

    Container res = { .label = Array, .ARRAY = initialize_stack() };
    save = strndup(save,line - save - 2);
    parser(res.ARRAY,save,hashtable,vars);
    push(res,stack);
    free(save);
    
    PARSE_SPACE
    return line;
}

char* block_parse(Stack stack, char* line) {
    int bloco = 1;
    char* save = line+=2;

    while(bloco) {
        if (*line == '{') bloco++;
        if (*line == '}') bloco--;
        line++;
    }
    Container res = { .label = Lambda, .STRING = strndup(save,line - save - 2) };
    push(res,stack);
    
    PARSE_SPACE
    return line;
}

char* string_parse(Stack stack, char* line) {
    char* save = ++line;
    line = strchr(save,'"');
    Container res = { .label = String, .STRING = strndup(save,line - save) };
    push(res,stack);
    return ++line;
}

/**
 * \brief Parâmetro que define o índice do array de funções em função do tipo de container
 */
#define HASHKEY(container) 128 * (2 - (2 * IS_NUM(container)) - IS_FOLDABLE(container)) + **line

int hashkey(Stack s,char** line,OperatorFunction* hashtable) {
    Container x = s->arr[s->sizeofstack - 1], y;
    int res = HASHKEY(x);
    if (s->sizeofstack > 1 && x.label != Lambda) y = s->arr[s->sizeofstack - 2];
    else return res;
    if (hashtable[res].arg > 1 && IS_FOLDABLE(x) < IS_FOLDABLE(y)) res = HASHKEY(y);
    return (**line != 'e') ? res : 256 + *(++(*line));
}

char* parse_hash(Stack s,char* line,OperatorFunction* hashtable,Container* vars) {
    int index = hashkey(s,&line,hashtable);
    if (isspace(*line)) ERROR_0
    switch(hashtable[index].arg) {
        case args_b: hashtable[index].f.args_b(s,pop(s),pop(s),hashtable,vars); break;
        default: num_args(s,&hashtable[index]);
    }
    return ++line;
}

void num_args(Stack s, OperatorFunction* func) {
    switch (func->arg) {
        case args_s: func->f.args_s(s); break;
        case args_1: func->f.args_1(s,pop(s)); break;
        case args_2: func->f.args_2(s,pop(s),pop(s)); break;
        case args_3: func->f.args_3(s,pop(s),pop(s),pop(s)); break;
        default: ERROR_0
    }
}

/* FUTURE IMPLEMENTATIONS:

char* char_parse(Stack stack, char* line) {
    Container res = { .label = Char, .CHAR = *(++line) };
    push(res,stack);
    return ++line;
}
*/