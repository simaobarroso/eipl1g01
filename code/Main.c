/**
 * @file Ficheiro que contêm a função principal do programa
 */

#include "parser.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CALC 8192

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) {
    static int hashmap[256] = {
        [Either] = 1,
        [Soma] = 1,
        [Subtrai] = 1,
        [Multiplica] = 1,
        [Divide] = 1,
        [Modulo] = 1,
        [Potencia] = 1,
        [Bitwiseand] = 1,
        [Bitwiseor] = 1,
        [Bitwisexor] = 1,
        [Incrementa] = 1,
        [Decrementa] = 1,
        [Bitwisenot] = 1,
        [ToChar] = 1,
        [ToInt] = 1,
        [ToString] = 1,
        [ToDouble] = 1,
        [Troca3] = 1,
        [Inverte2] = 1,
        [Duplica] = 1,
        [CopiaN] = 1,
        [Pop] = 1

        // acrescentar os próximos operadores aqui (próximos guiões)
    };
    Stack s;
    initialize(&s);
    char calc[CALC];
    assert(fgets(calc, CALC, stdin) != NULL);

    parser(&s, calc,hashmap);
    printstack(&s);
    putchar('\n');
    free(s.arr);
    return 0;
}