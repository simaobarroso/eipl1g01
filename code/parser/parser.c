#include "parser.h"
#include "../operations/operations.h"
#include "../types.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Tamanho de qualquer estrutura a que se dê parse
 */
#define SIZE 8192

/**
 * \brief Linha genérica de verificação de existência de space quando avançar
 */
#define PARSE_SPACE if (isspace(*line)) line++;

// ALGUEM QUE AVISE SE SOUBER UMA MELHOR MANEIRA QUE ESTAS CONDIÇÕES --Mota
void parser(Stack stack, char* line, OperatorFunction* hashtable, Container* vars) {
    while (*line) { // o meu linter dá um erro aqui que não sei porque acontece --Mota
        // para nums
        if (strspn(line,".-0123456789"))
            line = number_parse(stack,line);
        
        // para char
        else if (*line == '\'')
            line = char_parse(stack,line);

        // para var
        else if (*line == ':')
            line = var_control(stack,line,vars);

        // para string/array/bloco
        else if (strspn(line,"[{\""))
            line = structure_parse(stack,line,hashtable,vars);

        else 
            line = parse_hash(stack,line,hashtable);

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

char* char_parse(Stack stack, char* line) {
    Container res = { .label = Char, .CHAR = *(++line) };
    push(res,stack);
    return ++line;
}

char* var_control(Stack s,char* line,Container* vars) {
    vars[*(++line) - 'A'] = s->arr[s->sizeofstack - 1];
    return line;
}

char* structure_parse(Stack stack,char* line,OperatorFunction* hashtable,Container* vars) { // I don't like this --Mota
    switch(*line) {
        case '[': line = array_parse(stack,line,hashtable,vars); break;
        case '{': line = block_parse(stack,line); break;
        case '"': line = string_parse(stack,line); break;
        default: ERROR_1
    }
    return line;
}


// VER A PARTIR DAQUI PARA AMANHÃ
char* array_parse(Stack stack, char* line, OperatorFunction* hashtable, Container* vars) {
    int arr = 1;
    char* save = line+=2;
    char *aux = line;

    while(arr) {
        line = strchr(++line,'[');
        aux = strchr(++aux,']');
        arr += (line < aux) ? 1 : -1;
    }

    Container res = { .label = Array, .ARRAY = initialize_stack() };
    save = strndup(save,aux-save-1);
    parser(res.ARRAY,save,hashtable,vars);
    push(res,stack);
    
    PARSE_SPACE;
    return line;
}

char* block_parse(Stack stack, char* line) {
    PARSE_SPACE;

    char* save = line;
    int bloco = 1;
    char *aux = line;

    while(bloco) {
        if (line < aux) aux = line;
        bloco += (strchr(line,'{') < strchr(aux,'}')) ? 1 : -1;
    }
    Container res = { .label = Lambda, .STRING = strndup(save,(line > aux ? line : aux) - save) };
    
    PARSE_SPACE;
    push(res,stack);

    return line;
}

char* string_parse(Stack stack, char* line) {
    char* aux = ++line;
    line = strchr(aux,'"');
    Container res = { .label = String, .STRING = strndup(aux,line - aux) };
    push(res,stack);
    return line;
}

/**
 * \brief Parâmetro que define o índice do array de funções em função do tipo de container
 */
#define HASHKEY(container) 128 * (2 - (2 * IS_NUM(container)) + IS_FOLDABLE(container)) + **line

int hashkey(Stack s,char** line,OperatorFunction* hashtable) {
    Container x = s->arr[s->sizeofstack - 1], y;
    int res = HASHKEY(x);
    if (s->sizeofstack > 1) y = s->arr[s->sizeofstack - 2];
    else return res;
    if (hashtable[res].arg > 1 && x.label < y.label) res = HASHKEY(y);
    return (**line != 'e') ? res : 256 + *(++(*line));
}

char* parse_hash(Stack s,char* line,OperatorFunction* hashtable) {
    int index = hashkey(s,&line,hashtable);
    switch(hashtable[index].arg) {
        case args_s:
            hashtable[index].f.args_s(s);
            break;
        case args_1:
            hashtable[index].f.args_1(s,pop(s));
            break;
        case args_2:
            hashtable[index].f.args_2(s,pop(s),pop(s));
            break;
        case args_3:
            hashtable[index].f.args_3(s,pop(s),pop(s),pop(s));
            break;
        default: // deve acontecer se receber um \s \t \n - verificar se tal é possível
           ERROR_0
    }
    return ++line;
}

/* PARA VER AMANHÃ
Container* num_args(Stack s, OperatorFunction* f) {
    static Container res[3];
    for(int i = 0; i <= f->arg; i++) {
        res[i] = pop(s);
    }
    return res;
}
*/