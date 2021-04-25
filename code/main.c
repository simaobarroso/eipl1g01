/**
 * @file Ficheiro que contêm a função principal do programa
 */
#include "stack.h"
#include "parser/parser.h"
#include "operations/operations.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Variável estática
 */
#define SIZE 8192

void* initialize_hashmap(void);

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) { // TODO(Mota): mudar para o debugger

    Stack s;
    initialize(&s);
    Container* vars = initialize_vars();
    char line[SIZE];
    assert(fgets(line,SIZE,stdin) != NULL);
    void* hashmap = initialize_hashmap();
    parser(&s,line,hashmap,vars);
    printstack(&s);
    free(s.arr);
    return 0;
}

void* initialize_hashmap(void) {
    static void (*hashmap[128])(Stack*,char*,int*) = {      // TODO(Mota): sim, todos os tipos das funções abaixo têm que ser estes...
        [NewLine] = newline,                                // TODO(Mota): copiar esta parte do parser para uma função
        [Either] = either,                                  // TODO(Mota): criar esta função para selecionar que tipo de 'e' vai ser feito
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
        [MudaVariavel] = muda_variavel,
        [Igual] = igual,
        [Maior] = maior,
        [Menor] = menor,
        [Nao] = nao,
        [Ifthenelse] = ifthenelse

        // acrescentar os próximos operadores aqui (próximos guiões)
    };
    return hashmap;
}