#include "operations.h"
#include <assert.h>

void troca3(Stack *stack) {
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

void inverte2(Stack *stack) {
    int size = 2;
    Container guarda2[size--];

    while (size >= 0) {
        guarda2[size] = pop(stack);
        size--;
    }
    push(guarda2[1], stack);
    push(guarda2[0], stack);
}

void duplica(Stack *stack) {
    push(stack->arr[stack->sizeofstack - 1], stack);
}

void copiaN(Stack *stack) {
    Container copy = pop(stack); // vai buscar o indice a tirar da stack
    long n;
    if (copy.label == Long) {
        n = copy.content.l; // o indice tem que ser long
        push(stack->arr[stack->sizeofstack - n - 1], stack); // dá push do elemento no indice no topo
    }
    else
        assert(0 || "Error: wrong type");
}