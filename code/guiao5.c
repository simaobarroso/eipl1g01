#include "control_types.h"
#include "operations.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void aplicarbloco(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    push(x,s);
    parser(s,y.LAMBDA,hashtable,vars);
}

void map(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    if (x.label == String) x = string_to_array(x);
    Stack map = initialize_stack();
    Container res = { .label = x.label, .ARRAY = map };
    
    for(int i = 0; i < x.ARRAY->sizeofstack; i++) {
        push(x.ARRAY->arr[i],map);
        parser(map,fx.LAMBDA,hashtable,vars);
    }
    
    if (all_char(res)) res = array_to_string(res);
    if (res.label == Array) free(x.ARRAY);
    push(res,s);
}

void fold(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    Stack fold = initialize_stack();
    for(int i = x.ARRAY->sizeofstack - 1;i >= 0; i--) {
        push(x.ARRAY->arr[i],fold);
    }
    free(x.ARRAY);
    while(fold->sizeofstack > 1) parser(fold,fx.STRING,hashtable,vars);
    Container res = { .label = Array, .ARRAY = fold };
    push(res,s);
}

void filter(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    if (x.label == String) x = string_to_array(x);

    Stack filter = initialize_stack();
    Container res = { .label = Array, .ARRAY = filter };

    for(int i = 0; i < x.ARRAY->sizeofstack; i++) {
        push(x.ARRAY->arr[i],filter);
        parser(filter,fx.LAMBDA,hashtable,vars);
        if (pop(filter).LONG) {
            push(x.ARRAY->arr[i],filter);
        }
    }

    free(x.ARRAY);
    if (all_char(res)) res = array_to_string(res);
    push(res,s);
}

void while_bloco(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    Stack while_b = initialize_stack();
    push(x,while_b);
    while(IF_CONDITION(while_b->arr[while_b->sizeofstack - 1])) {
        parser(while_b,fx.LAMBDA,hashtable,vars);
        pop(while_b);
    }
    push(pop(while_b),s);
    free(while_b);
}

// void ordenar(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
//     Stack sort = initialize_stack();
//     if (x.label == String) string_to_array(x);
// }