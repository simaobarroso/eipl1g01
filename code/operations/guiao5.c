#include "operations.h"
#include "../stack.h"
#include "../parser/parser.h"

#include <assert.h>
#include <stdlib.h>

// os blocos são sempre do tipo { arg arg op } { arg op } { op }?
void executar_bloco(Stack s,char* line,int* i) {
    Container bloco = pop(s);
    int b_i = 0;
    switch (line[*i]) {
        case '~': break;
        case ',': fold(s,bloco.content.b,&b_i);break;
        case '%': map(s,bloco.content.b,&b_i); break;
        case '$': break;
    }
}

void map(Stack s,char* bloco, int* b_i) {
    Container toMap = pop(s);
    Container mapped;
    switch (toMap.label) {
        case String:
            (hashmap[bloco[(*b_i)]])(toMap.content.s,bloco,b_i);
            break;
        case Array:
            (hashmap[bloco[(*b_i)]])(toMap.content.a,bloco,b_i);
            break;
        default: assert(0 || "Error: wrong type");
    }
}

void foldf(Stack s, char* bloco, int* b_i) {
    Container toFold = pop(s);
    for(int i = 0; i < toFold.content.a->sizeofstack; i++) {
        (hashmap[bloco[(*b_i)]])(toFold.content.STACK,bloco,b_i);
    }
    push(toFold.content.a->arr[0],s);
}

void filter(Stack s,void* func()) {
    Container toFilter = pop(s);
    Container filtered;
    switch (toFilter.label) {
        case String:
            break;
        case Array:
            break;
        default: assert(0 || "Error: wrong type");
    }
    push(filtered,s);
}