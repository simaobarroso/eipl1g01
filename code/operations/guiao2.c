#include "operations.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define SIZE 8192

void troca3(Stack stack) {
    if (stack->sizeofstack >= 3) {
        int n = 0;
        Container guarda[3];

        while (n < 3) {
            guarda[n] = pop(stack);
            n++;
        }
        push(guarda[1], stack);
        push(guarda[0], stack);
        push(guarda[2], stack);
    } else
        assert(0 || "Error: not enough elements");
}

void inverte2(Stack stack) {
    int size = 2;
    Container guarda2[size--];

    while (size >= 0) {
        guarda2[size] = pop(stack);
        size--;
    }
    push(guarda2[1], stack);
    push(guarda2[0], stack);
}

void duplica(Stack stack) {
    push(stack->arr[stack->sizeofstack - 1], stack);
}

void copiaN(Stack stack) {
    Container copy = pop(stack); // vai buscar o indice a tirar da stack
    long n;
    if (copy.label == Long) {
        n = copy.LONG; // o indice tem que ser long
        push(stack->arr[stack->sizeofstack - n - 1], stack); // dá push do elemento no indice no topo
    }
    else
        assert(0 || "Error: wrong type");
}

void newline(Stack s) {
    char* newline = NULL;
    assert (fgets(newline, SIZE, stdin) != NULL);
    Container res = { .label = String, .STRING = strndup(newline, SIZE) }; // o meu linter queixa-se, é por causa do sítio do assert --Mota
    push(res,s);
}

void to_int_op(Stack s) {
    toInt(s->arr[s->sizeofstack - 1]);
}

void to_char_op(Stack s) {
    toChar(s->arr[s->sizeofstack - 1]);
}

void to_double_op(Stack s) {
    toDouble(s->arr[s->sizeofstack - 1]);
}

void to_string_op(Stack s) {
    toString(s->arr[s->sizeofstack - 1]);
}