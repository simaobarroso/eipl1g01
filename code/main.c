/**
 * @file Ficheiro que contêm a função principal do programa
 */
#include "operations/operations.h"
#include "parser/parser.h"
#include "stack.h"
#include "types.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Tamanho máximo da linha a ser lida
 */
#define SIZE 8192

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) { // TODO(Mota): mudar para o debugger

    Stack s = initialize_stack();
    char line[SIZE];
    assert(fgets(line,SIZE,stdin) != NULL);
    OperatorFunction* hash = hashmap();
    Container* vars = variables();
    parser(s,line,hash,vars);
    printstack(s);
    free(s->arr);
    return 0;
}