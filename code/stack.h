#include "types.h"

#ifndef STACK_H
#define STACK_H

/**
 * @file Ficheiro com as várias invocações às funções da Stack
 */
/* expression.h */

/**
 * \brief Inicializa a Stack
 *
 * @param Stack
 */
void initialize(Stack*);
/**
 * \brief Inicializa um conteiner com a label indicada
 *
 * @param Container
 * @param Label
 */
void relable_container(Container*,Label);
/**
 * \brief Verifica se a stack a stack está vazia
 *
 * @param Stack
 *
 * @returns Se está vazia retorna 1, caso contrário retorna 0
 */
int isEmpty(Stack* list);
/**
 * \brief Verifica se uma stack está cheia
 *
 * @param Stack
 *
 * @returns Se está cheia retorna 1, caso contrário retorna 0
 */
int isFull(Stack* list);

/**
 * \brief Coloca um valor no último índicie do array (topo da stack)
 *
 * @param Stack e um Int
 */
void push(Container, Stack*);
/**
 * \brief Retira um valor no último índicie do array (topo da stack)
 *
 * @param Container
 * @param Stack
 *
 * @returns Devolve o conteúdo desse índice
 */
Container pop(Stack*);
/**
 * \brief Imprime a stack para o stdout.
 *
 * @param Stack
 */
void printstack(Stack*);

//void printcontainer(Container*);

#endif /* STACK_H */