/**
 * @file Ficheiro que define o que é a Stack
 */
#include "stack.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 20

Stack initialize_stack(void) {
    Stack s = malloc(sizeof(Stack_plain));
    s->arr = malloc(SIZE * sizeof(Container));
    s->sizeofstack = 0;
    s->alloc = SIZE;
    return s;
}

void initialize_container(Container* contains, Label l) {
    contains->label = l;
    contains->LONG = 0;
}

int isEmpty(Stack stack) {
    return !stack->sizeofstack;
}

int isFull(Stack stack) {
    return (stack->sizeofstack == stack->alloc);
}

void push(Container x, Stack stack) {
    if (isFull(stack)) {
        stack->alloc *= 2;
        Container* tmp = realloc(stack->arr, stack->alloc * sizeof(Container));
        assert(tmp != NULL);
        stack->arr = tmp;
    }
    stack->arr[stack->sizeofstack++] = x;
}

Container pop(Stack stack) {
    if (isEmpty(stack)) {
        putchar('\n');
        exit(EXIT_SUCCESS);
    }
    return stack->arr[--stack->sizeofstack];
}

void void_pop(Stack stack) {
    pop(stack);
}

void printstack(Stack stack) {
    for (int i = 0; i < stack->sizeofstack; i++) {
        switch (stack->arr[i].label) {
            case Long: printf("%ld", stack->arr[i].LONG); break;
            case Double: printf("%g", stack->arr[i].DOUBLE); break;
            case Char: printf("%c", stack->arr[i].CHAR); break;
            case String: printf("%s", stack->arr[i].STRING); break;
            case Array: printstack(stack->arr[i].ARRAY); break;
            default: return;
        }
    }
    putchar('\n');
}

// debugging
/*
void printcontainer(Container* container) {
    switch (container->label) {
        case Long: printf("DEBUG: %ld\n", container->content.l); break;
        case Double: printf("DEBUG: %g\n", container->content.f); break;
        case Char: printf("DEBUG: %c\n", container->content.c); break;
        case String: printf("DEBUG: %s\n", container->content.s); break;
        case Array: break;
        default: return;
    }
}
*/