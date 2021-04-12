/**
 * @file Ficheiro que define o que é a Stack
 */
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void initializeContainer(Container* contains, Label l) {
    contains->label = l;
    contains->content.l = 0;
}


void initialize(Stack* list) {
    list->sizeofstack = 0;
    list->arr = malloc(SIZE * sizeof(Container));
    list->alloc = SIZE;
}


int isEmpty(Stack* list) {
    return !list->sizeofstack;
}

int isFull(Stack* list) {
    return (list->sizeofstack == list->alloc);
}

void push(Container x, Stack* list) {
    if (isFull(list)) {
        list->alloc *= 2;
        Container* tmp = realloc(list->arr, list->alloc * sizeof(Container));
        assert(tmp != NULL);
        list->arr = tmp;
    }
    list->arr[list->sizeofstack++] = x;
}

Container pop(Stack* list) {
    if (isEmpty(list)) {
        putchar('\n');
        exit(EXIT_SUCCESS);
    }
    return list->arr[--list->sizeofstack];
}

void printstack(Stack* stack) {
    for (int i = 0; i < stack->sizeofstack; i++) {
        if (stack->arr[i].label == Long)
            printf("%ld", stack->arr[i].content.l);
        else if (stack->arr[i].label == Double)
            printf("%g", stack->arr[i].content.f);
        else if (stack->arr[i].label == Char)
            printf("%c", stack->arr[i].content.c);
        else {
            printf("%s", stack->arr[i].content.s);
        }
    }
}