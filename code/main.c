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
    initialize(s);
    Container* vars = initialize_vars();
    char line[SIZE];
    assert(fgets(line,SIZE,stdin) != NULL);
    parser(s,line,vars);
    printstack(s);
    free(s->arr);
    return 0;
}