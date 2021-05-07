#include "operations.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void aplicarbloco(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    push(x,s);
    parser(s,y.LAMBDA,hashtable,vars);
}

void map(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    if (x.label == String) x = string_to_array(x);
    Stack map = initialize_stack();
    
    for(int i = 0; i < x.ARRAY->sizeofstack; i++) {
        push(x.ARRAY->arr[i],map);
        parser(map,y.LAMBDA,hashtable,vars);
        x.ARRAY->sizeofstack++;
    }
    if (x.label == String_A) x = array_to_string(x);
    free(x.ARRAY);
    push(x,s);
}

void fold(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    while(x.ARRAY->sizeofstack != 1) {
        parser(x.ARRAY,y.LAMBDA,hashtable,vars);
    }
    Container res = pop(x.ARRAY);
    free(x.ARRAY);
    push(res,s);
}

void filter(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    if (x.label == String) x = string_to_array(x);

    Stack filter = initialize_stack();
    Container res = { .label = x.label };

    for(int i = 0; i < x.ARRAY->sizeofstack; i++) {
        parser(filter,y.LAMBDA,hashtable,vars);
        long check = toInt(pop(filter)).LONG;
        if (check) push(x.ARRAY->arr[i],filter);
    }

    free(x.ARRAY);
    if (res.label == String_A) res = array_to_string(x);
    push(res,s);
}

void while_bloco(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    if (x.label == String)
        x = string_to_array(x);

    parser(s,y.LAMBDA,hashtable,vars);
    long check = toInt(pop(s)).LONG;

    for(int i = 0; x.ARRAY->sizeofstack && check; i++) {
        x.ARRAY->sizeofstack--;
        parser(s,y.LAMBDA,hashtable,vars);
        check = toInt(pop(s)).LONG;
    }

    if (x.label == String_A) x = array_to_string(x);
    push(x,s);
}

// void ordenar(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
//     Stack sort = initialize_stack();
//     if (x.label == String) string_to_array(x);
// }