/**
 * @file Ficheiro que contêm a função principal do programa
 */
#include "control_types.h"
#include "parser.h"
#include "operations.h"
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * \brief Tamanho máximo da linha a ser lida
 */
#define SIZE 10240

/**
 * \brief Função main (função principal do programa)
 *
 * @returns int
 */
int main(void) { // TODO(Mota): mudar para o debugger

    Stack s = initialize_stack();
    char* line = (char*) malloc(sizeof(char) * SIZE);
    line = fgets(line,SIZE,stdin);
    OperatorFunction* hashtable = hash();
    Container* vars = variables();
    parser(s,line,hashtable,vars);
    free(line);
    printstack(s);
    putchar('\n');
    free_stack(s);
    return 0;
}