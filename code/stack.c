#include <assert.h>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void initialize(Stack *list) {
    list->sizeofnums = 0;
    list->nums = malloc(SIZE*sizeof(int));
    list->alloc = SIZE;
}

int *peek(Stack *list) {
    return &list->nums[list->sizeofnums-1];
}

void changesizeofnums(Stack *list, int sizeofnums) {
    list->sizeofnums = sizeofnums;
}

int isEmpty (Stack *list) {
	return (!list->sizeofnums);
}

int isFull(Stack *list) {
    return(list->sizeofnums == list->alloc);
}

void push(int x, Stack *list) {
    if(isFull(list)) {
        list->alloc *= 2;
        int *tmp = realloc(list->nums, list->alloc*sizeof(int));
        assert(tmp != NULL);
        list->nums = tmp;
    }
    list->nums[list->sizeofnums++] = x;
}

int pop(Stack *list) {
	if (isEmpty(list)) {
        putchar('\n');
        exit (EXIT_SUCCESS);
	}
	return list->nums[--list->sizeofnums];
}
