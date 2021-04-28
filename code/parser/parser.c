#include "parser.h"
#include "../operations/operations.h"
#include "../types.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

void parser(Stack stack, char* line, OperatorFunction* hashmap, Container* vars) {
    Container toPush;
    initialize_container(&toPush, String);
    while (*line != '\0') { // como o fgets apanha o '\n', verificamos para ambos, o '\0' 'e apenas standard verificar em C
        
        // para nums
        if (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(*(line+1))))
            number_parse(stack,line);
        
        // para char
        else if (*line == '\'')
            char_parse(stack,line);

        // para var
        else if (*line == ':')
            var_control(stack,line,vars);               // TODO(Mota): esta função ainda não existe

        // para string/array/bloco
        else if (*line == '"' || *line == '[' || *line == '{')
            structure_parse(stack,line,hashmap,vars);   // TODO(Mota): esta função ainda não existe

        else 
            parse_hashmap(stack,line,hashmap);          // TODO(Mota): esta função ainda não existe

        line+=2; // passa o espaço ou o que for à frente
    }
}

void number_parse(Stack stack,char* line) {
    Container res;
    int isfloat = 0;
    char num[20] = "";
    char* aux = num;

    while (isdigit(*line) || *line == '.' || (*line == '-' && isdigit(*(line+1)))) {
        if (*line == '.') isfloat = 1;
        strncat(num,line,1);
        line++;
    }
    if (*(line+2) == 's') {
        res.label = String;
        res.STRING = strndup(num,80);
        line += 2;
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
    ++line;
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
                ++line;
            }
            Stack s = malloc(sizeof(Stack_plain));
            parser(s,array,hashmap,vars);
            Container res = { .label = Array, .ARRAY = s };
            push(res,stack);
            line+=2;
            break;
        case '{':
            while(*(line+2) != ']') {
                strncat(array,line,1);
                ++line;
            }
            break;
        case '"':
        default: assert(0 || "Error: wrong type");
    }
}

int hashkey(Stack s) {
    Container *x = &s->arr[s->sizeofstack - 1];
    Container *y = &s->arr[s->sizeofstack - 1];
    Container cmp = (y->label > x->label) ? *y : *x;
    return 128*(2 - (2*isNum(cmp)) + isFoldable(cmp));
}

void fazer_bloco(Stack s,char* line) {
    char bloco[80] = "";
    Container res = { .label = Lambda };

    while(*(line+1) != '}') {
        strncat(bloco,line,1);
        line++;
    }
    res.content.b = strdup(bloco);
    push(res,s);
}

void either(Stack s,char* line,) {
	
}