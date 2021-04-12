/**
 * @file Ficheiro que contêm a função principal do programa
 */

#include "operations.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CALC 8192

/**
 * \brief Preenche a stack e faz as várias operações na própria
 *
 * @param Stack e Input do terminal
 *
 */
void parser(Stack*, char*);

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) {
    Stack s;
    initialize(&s);
    char calc[CALC];
    assert(fgets(calc, CALC, stdin) != NULL);

    parser(&s, calc);
    printstack(&s); // advertência: isto dá free a uma string depois de a imprimir
    putchar('\n');
    free(s.arr);
    return 0;
}

/**
 * \brief Mesma função definida em cima
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Stack e Input do terminal
 *
 */
void parser(Stack* stack, char* calc) {
    int i = 0;
    Container toPush;
    while (calc[i] != '\n' && calc[i] != '\0') {
        // para nums
        char num[15] = "";
        if ((calc[i] >= '0' && calc[i] <= '9') || calc[i] == '.') { // 30 = '0' e 39 = '9'
            int sign = 1;
            int isfloat = 0;

            while ((calc[i] >= '0' && calc[i] <= '9') || calc[i] == '.') {
                if (i != 0 && calc[i - 1] == '-') sign = -1;
                if (calc[i] == '.') isfloat = 1;
                strncat(num, &calc[i], 1);
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
        else if (calc[i] != ' ' && !(calc[i] == '\'' || calc[i] == '"')) {
            // operation(calc[i], stack);
            if (calc[i] != 'l') operation(calc[i], stack);
            else {
                char newline[CALC];
                assert(fgets(newline, CALC, stdin) != NULL);
                parser(stack,newline);
            }
        }
        else
            assert(0 || "Error: wrong input.");
        i++;
    }
}