#include "parser.h"
#include "../operations/operations.h"
#include "../types.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

// ALGUEM QUE AVISE SE SOUBER UMA MELHOR MANEIRA QUE ESTAS CONDIÇÕES
void parser(Stack stack, char* line, OperatorFunction* hashmap, Container* vars) {
    while (*line) { // o meu linter dá um erro aqui que não sei porque acontece --Mota
        // para nums
        if (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(*(line+1))))
            number_parse(stack,line);
        
        // para char
        else if (*line == '\'')
            char_parse(stack,line);

        // para var
        else if (*line == ':')
            var_control(stack,line,vars);

        // para string/array/bloco
        else if (*line == '"' || *line == '[' || *line == '{')
            structure_parse(stack,line,hashmap,vars);

        else 
            parse_hash(stack,line,hashmap);

        line+=2; // passa o espaço ou o que for à frente
    }
}

void number_parse(Stack stack,char* line) {
    Container res;
    int isfloat = 0;
    char num[20] = "";

    while (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(*(line+1)))) {
        if (*line == '.') isfloat = 1;
        strncat(num,line,1);
        line++;
    }
    if (*(line+=2) == 's') {
        res.label = String;
        res.STRING = strndup(num,80);
    } else {
        if (isfloat) {  // verifica se é float
            initialize_container(&res,Double);
            res.DOUBLE = strtof(num,&line);
        } else {  // acontece se for long
            initialize_container(&res,Long);
            res.LONG = strtol(num,&line,10);
        }
    }
    push(res,stack);
}

void char_parse(Stack stack, char* line) {
    Container res;
    res.CHAR = *(++line);
    push(res,stack);
    line++;
}

void var_control(Stack s,char* line,Container* vars) {
    vars[*(++line) - 'A'] = pop(s);
}

void structure_parse(Stack stack,char* line,OperatorFunction* hashmap,Container* vars) {
    switch(*line) {
        case '[':
            line+=2;
            char array[SIZE];
            while(*(line+2) != ']') {
                strncat(array,line,1);
                line++;
            }
            Stack s = malloc(sizeof(Stack_plain));
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
}

int hashkey(Stack s,char* line) {
    Container x = s->arr[s->sizeofstack - 1];
    Container y = s->arr[s->sizeofstack - 2];
    Container cmp = (y.label > x.label) ? y : x;
    if (*line != 'e') return 128*(2 - (2*isNum(cmp)) + isFoldable(cmp));
    else {
        line++;
        return 256;
    }
}

void parse_hash(Stack s,char* line,OperatorFunction* hashtable) {
    int index = (*line)*hashkey(s,line);
    Container x, y, z;
    switch(hashtable[index].arg) {
        case args_s:
            hashtable[index].f.args_s(s);
            break;
        case args_1: 
            x = pop(s);
            hashtable[index].f.args_1(&x,s);
            break;
        case args_2:
            x = pop(s), y = pop(s);
            hashtable[index].f.args_2(&x,&y,s);
            break;
        case args_3:
            x = pop(s), y = pop(s), z = pop(s);
            hashtable[index].f.args_3(&x,&y,&z,s);
            break;
        default: // deve acontecer se receber um \s \t \n - verificar
            fputs("Wrong input, try to verify if identation is correct\n", stderr);
            exit(EXIT_FAILURE);
    }
}