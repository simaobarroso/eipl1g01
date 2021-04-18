/**
 * @file Ficheiro que contêm a função principal do programa
 */

#include "parser.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

void initialize_vars(Container*);

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) { // TODO(Mota): mudar para o debugger
    static int hashmap[256] = {
        ['l'] = 1,
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
        [Pop] = 1,
        [CopiaTopo] = 1

        // acrescentar os próximos operadores aqui (próximos guiões)
    };
    static Container vars[26];
    initialize_vars(vars);
    Stack s;
    initialize(&s);
    char line[SIZE];
    assert(fgets(line,SIZE,stdin) != NULL);

    parser(&s,line,hashmap,vars);
    printstack(&s);
    putchar('\n');
    free(s.arr);
    return 0;
}

void initialize_vars(Container* vars) {
    for(int i = 0, j= 10; i <= F; i++, j++) {
        vars[i].label = Long;
        vars[i].content.l = j;
    }
    vars[N].label = Char;
    vars[N].content.c = '\n';
    vars[S].label = Char;
    vars[S].content.c = ' ';
    for(int i2 = X, j2 = 0; i2 <= Z; i2++, j2++) {
        vars[i2].label = Long;
        vars[i2].content.l = j2;
    }
}