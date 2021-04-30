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

// ALGUEM QUE AVISE SE SOUBER UMA MELHOR MANEIRA QUE ESTAS CONDIÇÕES --Mota
void parser(Stack stack, char* line, OperatorFunction* hashtable, Container* vars) {
    while (*line) { // o meu linter dá um erro aqui que não sei porque acontece --Mota
        // para nums
        if (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(line[1])))
            line = number_parse(stack,line);
        
        // para char
        else if (*line == '\'')
            line = char_parse(stack,line);

        // para var
        else if (*line == ':')
            line = var_control(stack,line,vars);

        // para string/array/bloco
        else if (*line == '"' || *line == '[' || *line == '{')
            line = structure_parse(stack,line,hashtable,vars);

        else 
            line = parse_hash(stack,line,hashtable);

        line += (line[1] == '\n' || line[1] == '\t' || line[1] == ' ') + 1;
    }
}

char* number_parse(Stack stack,char* line) {
    Container res;
    int isfloat = 0;
    char num[20] = "";
    char* aux;
    while (*line != ' ' && *line != '\n' && *line != '\t') {
        isfloat = (*line == '.');
        strncat(num,line,1);
        aux = line;
        line++;
    }
    if (line[1] == 's') {
        res.label = String;
        res.STRING = strdup(num);
        line++;     // em line[1] é s, logo *line é \s, pelo que passa para o s
    } else {
        if (isfloat) {  // verifica se é float
            initialize_container(&res,Double);
            res.DOUBLE = strtof(num,&aux);
        } else {  // acontece se for long
            initialize_container(&res,Long);
            res.LONG = strtol(num,&aux,10);
        }
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

char* structure_parse(Stack stack,char* line,OperatorFunction* hashmap,Container* vars) { // I don't like this --Mota
    switch(*line) {
        case '[':
            line+=2;
            char array[SIZE];
            while(*(line+2) != ']') {
                strncat(array,line,1);
                line++;
            }
            Stack s = malloc(sizeof(Stack_plain));
            assert(s != NULL);
            parser(s,array,hashmap,vars);
            Container res = { .label = Array, .ARRAY = s };
            push(res,stack);
            line+=2;
            break;
        case '{':
            line+=2;
            while(*(line+2) != '}') {
                strncat(array,line,1);
                line++;
            }
            push(res,stack);
            break;
        case '"':
            line++;
            while(*line != '"') {
                strncat(array,line,1);
                line++;
            }
            push(res,stack);
            break;
        default: assert(0 || "Error: wrong type");
    }
    return line;
}

/**
 * \brief Parâmetro que define o índice do array de funções em função do tipo de container
 */
#define HASHKEY(container) 128*(2 - (2*isNum(container)) + isFoldable(container)) + **line

int hashkey(Stack s,char** line,OperatorFunction* hashtable) {
    Container x = s->arr[s->sizeofstack - 1];
    Container y = s->arr[s->sizeofstack - 2];
    int res = HASHKEY(x);
    if (hashtable[res].arg > 1 && x.label < y.label) res = HASHKEY(y);
    return (**line != 'e') ? res : 256 + *(*++line);
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