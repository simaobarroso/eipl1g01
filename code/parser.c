#include "parser.h"
#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CALC 8192

void parser(Stack* stack, char* calc, int* hashmap) {
    int i = 0;
    Container toPush;
    while (calc[i] != '\n' && calc[i] != '\0') {
        // para nums
        char num[15] = "";
        if (isdigit(calc[i]) || calc[i] == '.') { // 30 = '0' e 39 = '9'
            int sign = 1;
            int isfloat = 0;

            while (isdigit(calc[i]) || calc[i] == '.') {
                if (i != 0 && calc[i - 1] == '-') sign = -1;
                if (calc[i] == '.') isfloat = 1;
                strncat(num, &calc[i],1);
                i++;
            }
            if (isfloat) {  // verifica se é float
                initializeContainer(&toPush,Double);
                toPush.content.f = (atof(num) * sign);
            }
            else {  // acontece se for long
                initializeContainer(&toPush,Long);
                toPush.content.l = (atol(num) * sign);
            }
            push(toPush,stack);
        }
        // para strings/chars
        else if (calc[i-1] == '\'' || calc[i-1] == '"') {
            // if (calc[i-1] == '\'') {
            initializeContainer(&toPush, Char);
            toPush.content.c = calc[i];
            push(toPush,stack);
            // }
            // else string - próximos guiões
        }
        // para ops
        else if (hashmap[(int)calc[i]]) {
            // operation(calc[i], stack);
            if (calc[i] != 'l') operation(calc[i], stack); //TODO(Mota): 
            else {
                char newline[CALC];
                assert(fgets(newline, CALC, stdin) != NULL);
                // parser(stack,newline,hashmap); // tentar meter de forma iterativa
                strncat(newline,calc+i,CALC/2);
                calc = newline;
            }
        }
        else
            assert(0 || "Error: wrong input.");
        i++;
    }
}