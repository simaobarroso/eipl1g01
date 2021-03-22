/**
 * @file Ficheiro que define o que é a Stack
 */
#include <assert.h>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10


/**
 * \brief Inicializa a Stack
 *
 * @param Stack
 */
void initialize(Stack *list) {
    list->sizeofnums = 0;
    list->nums = malloc(SIZE*sizeof(int));
    list->alloc = SIZE;
}

/*
int *peek(Stack *list) {
    return &list->nums[list->sizeofnums-1];
}
*/

/*
void changesizeofnums(Stack *list, int sizeofnums) {
    list->sizeofnums = sizeofnums;
}
 */

/**
 * \brief Verifica se a stack a stack está vazia
 *
 * @param Stack
 *
 * @returns Se está vazia retorna 1, caso contrário retorna 0 
 */
int isEmpty (Stack *list) {
	return (!list->sizeofnums);
}
/**
 * \brief Verifica se uma stack está cheia
 *
 * @param Stack
 *
 * @returns Se está cheia retorna 1, caso contrário retorna 0  
 */
int isFull(Stack *list) {
    return(list->sizeofnums == list->alloc);
}

/**
 * \brief Coloca um valor no último índicie do array (topo da stack)
 *
 * @param Stack e um Int
 */
void push(int x, Stack *list) {
    if(isFull(list)) {
        list->alloc *= 2;
        int *tmp = realloc(list->nums, list->alloc*sizeof(int));
        assert(tmp != NULL);
        list->nums = tmp;
    }
    list->nums[list->sizeofnums++] = x;
}

/**
 * \brief Retira um valor no último índicie do array (topo da stack)
 *
 * @param Stack
 *
 * @returns Devolve o conteúdo desse índice
 */
int pop(Stack *list) {
	if (isEmpty(list)) {
        putchar('\n');
        exit (EXIT_SUCCESS);
	}
	return list->nums[--list->sizeofnums];
}
