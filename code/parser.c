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
    while (line[i] != '\n' && line[i] != '\0') {
        // para nums
        char num[15] = "";
        if (isdigit(line[i]) || line[i] == '.') { // 30 = '0' e 39 = '9'
            int sign = 1;
            int isfloat = 0;

            while (isdigit(line[i]) || line[i] == '.') {
                if (i != 0 && line[i - 1] == '-') sign = -1;
                if (line[i] == '.') isfloat = 1;
                strncat(num,&line[i],1);
                i++;
            }
            if (isfloat) {  // verifica se é float
                initializeContainer(&toPush,Double);
                toPush.content.f = (atof(num) * sign); // TODO(Mota): MUDAR ISTO!!!
            }
            else {  // acontece se for long
                initializeContainer(&toPush,Long);
                toPush.content.l = (atol(num) * sign); // TODO(Mota): idém^^
            }
            push(toPush,stack);
        }
        // para strings/chars
        else if (line[i-1] == '\'' || line[i-1] == '"') { // será que sim? --Mota
            // if (line[i-1] == '\'') {
            initializeContainer(&toPush, Char);
            toPush.content.c = line[i];
            push(toPush,stack);
            // }
            // else string - próximos guiões
        }
        // para ops
        else if (hashmap[(int)line[i]]) {
            // operation(line[i], stack);
            if (line[i] != 'l') operation(line, stack, &i);
            else {                  // TODO(Mota): Simão, podes copiar isto para o operations.c para o l? ´^_^
                char newline[SIZE];
                assert(fgets(newline, SIZE, stdin) != NULL);
                // parser(stack,newline,hashmap); // tentar meter de forma iterativa
                assert(strncat(newline,&line[i],SIZE/2) != NULL); // não sei se isto funciona, falta testar, por isso não apagar isto^^ acima
                line = newline;
            }
        }
        else
            assert(0 || "Error: wrong input.");
        i++;
    }
}