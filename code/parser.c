#include "parser.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

void parser(Stack* stack, char* line, int* hashmap) {
    int i = 0;
    Container toPush;
    relable_container(&toPush, String);
    while (line[i] != '\n' && line[i] != '\0') { // como o fgets apanha o '\n', verificamos para ambos, o '\0' 'e apenas standard verificar em C
        
        // para nums
        if (isdigit(line[i]) || line[i] == '.' || (line[i] == '-' && isdigit(line[i+1]))) {
            toPush = number_parse(line, &i);
            push(toPush,stack);
        }
        
        // para char
        else if (line[i] == '\'') {
            relable_container(&toPush, Char);
            toPush.content.c = line[++i];
            ++i;
        }

        // para strings/arrays/blocos
        else if (line[i] == '[' || line[i] == '"' || line[i] == '{') {
            // if (line[i-1] == '\'') {
            char* string = "";
            switch (line[i]) {
                // case '[': parse_array(); break;
                case '"':
                    while(line[i] != '"' && line[i+1] == ' ') { // isto pode dar treta para depois do guião 3 --Mota
                        strncat(string,&line[i++],1);
                    }
                    toPush.content.s = strndup(string,80);
                    break;
                default: return;
            push(toPush,stack);
            }
        }

        // para ops
        else if (hashmap[(int)line[i]]) {
            // operation(line[i], stack);
            if (line[i] != 'l') operation(line, stack, &i);
            else {                  // TODO(Mota): Simão, podes copiar isto para o operations.c para o l? ´^_^
                char newline[SIZE];
                assert(fgets(newline, SIZE, stdin) != NULL);
                parser(stack,newline,hashmap);
                /*
                strncat(newline,&line[i],SIZE/2);   // TODO(Mota): isto come sempre o primeiro carater, acho que os endereços estão errados algures
                line[i-1] = '\0';                   // nope, nao estou orgulhoso disto --Mota
                strncat(line,newline,SIZE/2);
                */
            }
        }
        else assert(0 || "Error: wrong input.");
        i++;
    }
}

Container number_parse(char* line, int* i) {
    Container res;
    int isfloat = 0;
    char num[20] = "";
    char* aux = num;

    while (isdigit(line[*i]) || line[*i] == '.' || (line[*i] == '-' && isdigit(line[*i+1]))) {
        if (line[*i] == '.') isfloat = 1;
        strncat(num,&line[*i],1);
        (*i)++;
        aux++;
    }
    if (line[(*i)+=2] == 's') {
        res.label = String;
        res.content.s = strndup(num,80);
    }
    // TODO(Mota): estas condições aqui em baixo podem ser genéricas, certo era fixe se pudessemos separar isto
    else {
        if (isfloat) {  // verifica se é float
            relable_container(&res,Double);
            res.content.f = strtof(num,&aux);
        } else {  // acontece se for long
            relable_container(&res,Long);
            res.content.l = strtol(num,&aux,10);
        }
    }
    return res;
}