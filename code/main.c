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
    fgets(line,SIZE,stdin);
    assert(line != NULL);
    OperatorFunction* hashtable = hash();
    Container* vars = variables();
    parser(s,line,hashtable,vars);
    printstack(s);
    free(s->arr);
    return 0;
}