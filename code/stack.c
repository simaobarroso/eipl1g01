#include <assert.h>
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *error1 = "Not enough memory to perform operation";
char *error2 = "Underflow\nProgram Terminated";

void initialize(Stack *list) {
    list->sizeofnums = 0;
    list->current = -1;
    // a stack inicializa com o push
}

int *peek(Stack *list) {
    return &list->nums[list->current];
}

void changesizeofnums(Stack *list, int sizeofnums) {
    list->sizeofnums = sizeofnums;
}

int isEmpty (Stack *list) {
	return (list->current == -1);
}

void push(int x, Stack *list) {
    int *tmp = (isEmpty(list)) 
        ? realloc(list->nums, (list->sizeofnums)+sizeof(int))
        : malloc(sizeof(int));
    if(tmp != NULL) list->nums = tmp;
    else {
        fputs(error1, stderr);
        exit (EXIT_FAILURE);
    }
    list->nums[++list->current] = x;
    (list->sizeofnums)++;
}

int pop(Stack *list) {
	if (isEmpty(list)) {
		fputs(error2, stderr);
		exit (EXIT_FAILURE);
	}
    int *tmp = realloc(list->nums, (list->sizeofnums)-sizeof(int));
    if(tmp != NULL) list->nums = tmp;
    else {
        fputs(error1, stderr);
        exit (EXIT_FAILURE);
    }
	return list->nums[--list->current];
}

void freelast(Stack *list) {
    if(isEmpty(list)) {
        int *tmp = realloc(list->nums, (list->sizeofnums)-sizeof(int));
        if(tmp != NULL) list->nums = tmp;
        else {
            fputs(error1, stderr);
            exit (EXIT_FAILURE);
        }
    }
}

void freeall(Stack *list, char *calc) {
    if(isEmpty(list)) free(list->nums);
    if(strlen(calc)) free(calc);
}
