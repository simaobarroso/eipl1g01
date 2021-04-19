/**
 * @file Ficheiro que define o que é a Stack
 */
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void relable_container(Container* contains, Label l) {
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
        switch (stack->arr[i].label) {
            case Long: printf("%ld", stack->arr[i].content.l); break;
            case Double: printf("%g", stack->arr[i].content.f); break;
            case Char: printf("%c", stack->arr[i].content.c); break;
            case String: printf("%s", stack->arr[i].content.s); break;
            case Array: /*I predict shit here;*/ break;
            default: return;
        }
    }
}

// debugging
/*
void printcontainer(Container* container) {
    switch (container->label) {
        case Long: printf("DEBUG: %ld\n", container->content.l); break;
        case Double: printf("DEBUG: %g\n", container->content.f); break;
        case Char: printf("DEBUG: %c\n", container->content.c); break;
        case String: printf("DEBUG: %s\n", container->content.s); break;
        case Array: /*I predict shit here;*/ break;
        default: return;
    }
}
*/