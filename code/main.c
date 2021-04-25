/**
 * @file Ficheiro que contêm a função principal do programa
 */

#include "parser.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Variável estática
 */
#define SIZE 8192


/**
 * \brief Função que inicializa as variáveis
 *
 * @param Container
 */
void initialize_vars(Container*);

void* initialize_hashmap(void);

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) { // TODO(Mota): mudar para o debugger

    static Container vars[26];
    initialize_vars(vars);
    Stack s;
    initialize(&s);
    char line[SIZE];
    assert(fgets(line,SIZE,stdin) != NULL);
    void* hashmap = initialize_hashmap();
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

void* initialize_hashmap(void) {
    static void (*hashmap[128])(Stack*,int*) = {    // TODO(Mota): sim, todos os tipos das funções abaixo têm que ser estes...
        [NewLine] = newline,                        // TODO(Mota): copiar esta parte do parser para uma função
        [Either] = either,                          // TODO(Mota): criar esta função para selecionar que tipo de 'e' vai ser feito
        [Soma] = soma,
        [Subtrai] = subtrai,
        [Multiplica] = multiplica,
        [Divide] = divide,
        [Modulo] = modulo,
        [Potencia] = potencia,
        [Bitwiseand] = bitwiseand,
        [Bitwiseor] = bitwiseor,
        [Bitwisexor] = bitwisexor,
        [Incrementa] = incrementa,
        [Decrementa] = decrementa,
        [Bitwisenot] = bitwisenot,
        [ToChar] = toChar,
        [ToInt] = toInt,
        [ToString] = toString,
        [ToDouble] = toDouble,
        [Troca3] = troca3,
        [Inverte2] = inverte2,
        [Duplica] = duplica,
        [CopiaN] = copiaN,
        [Pop] = pop,
        [MudaVariavel] = variavel,
        [Igual] = igual,
        [Maior] = maior,
        [Menor] = menor,
        [Nao] = nao,
        [Ifthenelse] = ifthenelse

        // acrescentar os próximos operadores aqui (próximos guiões)
    };
    return hashmap;
}
