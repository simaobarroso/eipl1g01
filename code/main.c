/**
 * @file Ficheiro que contêm a função principal do programa
 */
#include "control_types.h"
#include "parser/parser.h"
#include "operations/operations.h"
#include "stack/stack.h"

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
 * @returns int
 */
int main(void) { // TODO(Mota): mudar para o debugger

    Stack s = initialize_stack();
    char line[SIZE];
    fgets(line,SIZE,stdin);
    char* to_parse = strdup(line);
    OperatorFunction* hashtable = hash();
    Container* vars = variables();
    parser(s,to_parse,hashtable,vars);
    free(to_parse);
    printstack(s);
    putchar('\n');
    free_stack(s);
    return 0;
}