#include "../control_types.h"

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
Stack initialize_stack(void);
/**
 * \brief Liberta a Stack
 *
 * @param Stack
 */
void free_stack(Stack);
/**
 * \brief Inicializa um conteiner com a label indicada
 *
 * @param Container
 * @param Label
 */
void initialize_container(Container*,Label);
/**
 * \brief Verifica se a stack a stack está vazia
 *
 * @param Stack
 *
 * @returns Se está vazia retorna 1, caso contrário retorna 0
 */
int isEmpty(Stack);
/**
 * \brief Verifica se uma stack está cheia
 *
 * @param Stack
 *
 * @returns Se está cheia retorna 1, caso contrário retorna 0
 */
int isFull(Stack);

/**
 * \brief Coloca um valor no último índicie do array (topo da stack)
 *
 * @param Stack e um Int
 */
void push(Container, Stack);
/**
 * \brief Retira um valor no último índicie do array (topo da stack)
 *
 * @param Stack
 *
 * @returns Devolve o conteúdo desse índice
 */
Container pop(Stack);
/**
 * \brief Mesmo que a pop, mas para ser usada no array de funções
 *
 * @param Stack
 */
void void_pop(Stack);
/**
 * \brief Imprime a stack para o stdout.
 *
 * @param Stack
 */
void printstack(Stack);

//void printcontainer(Container*);

#endif /* STACK_H */