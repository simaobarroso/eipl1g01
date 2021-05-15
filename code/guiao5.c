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
    Container res = { .label = x.label };
    
    if (x.label == String) x = string_to_array(x);
    
    Stack map = map_sort_aux(x,fx,hashtable,vars);
    res.ARRAY = map;
    
    if (all_char(res)) res = array_to_string(res);
    if (res.label == Array) free(x.ARRAY);
    push(res,s);
}

Stack map_sort_aux(Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    Stack map = initialize_stack();

    for(int i = 0; i < x.ARRAY->sizeofstack; i++) {
        push(x.ARRAY->arr[i],map);
        parser(map,fx.LAMBDA,hashtable,vars);
    }
    return map;
}

void fold(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    Stack fold = initialize_stack();

    push(x.ARRAY->arr[0],fold);
    for(int i = 1; i < x.ARRAY->sizeofstack; i++) {
        push(x.ARRAY->arr[i],fold);
        parser(fold,fx.LAMBDA,hashtable,vars);
    }

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
    push(x,s);
    while(IF_CONDITION(x)) {
        parser(s,fx.LAMBDA,hashtable,vars);
        x = pop(s);
    }
}

/**
 * \brief Auxiliar de escrita e leitura para conversão em Double
 */
#define SORT_I(i) toDouble(SORT->arr[i]).DOUBLE

void swap(Container *x,Container *y) {
    Container aux = *x;
    *x = *y;
    *y = aux;
}

/**
 * \brief Auxiliar de escrita e leitura para aceder a campos dum Container Array
 */
#define SORT to_sort.ARRAY

/*
ERROS CONHECIDOS: [ 1 2 1 ] { 2 < } $ == 211 e devia ser 112
*/
void ordenar(Stack s, Container x, Container fx, OperatorFunction* hashtable, Container* vars) {
    Container to_sort = { .label = Array, .ARRAY =  arraydup(x.ARRAY) };
    to_sort.ARRAY = map_sort_aux(to_sort,fx,hashtable,vars);

    if (all_string(to_sort.ARRAY))
        ordenar_strings(x,to_sort);

    else if (all_array(to_sort.ARRAY))
        ordenar_arrays(x,to_sort);

    else
        ordenar_rest(x,to_sort);

    Container res = { .label = Array, .ARRAY = x.ARRAY };
    if (all_char(res)) array_to_string(res);
    push(res,s);
    free(SORT);
}

void ordenar_strings(Container x, Container to_sort) {
    int n = 1;

    while(n < x.ARRAY->sizeofstack) {
        for(size_t i = n; i > 0 && strcmp(SORT->arr[i].STRING,SORT->arr[i-1].STRING) < 0; i--) {
            swap(&SORT->arr[i-1],&SORT->arr[i]);
            swap(&x.ARRAY->arr[i-1],&x.ARRAY->arr[i]);
        }
    n++;
    }
}

void ordenar_arrays(Container x, Container to_sort) {
    int n = 1;

    while(n < x.ARRAY->sizeofstack) {
        for(size_t i = n; i > 0 && arraycmp(SORT->arr[i].ARRAY,SORT->arr[i-1].ARRAY) < 0; i--) {
            swap(&SORT->arr[i-1],&SORT->arr[i]);
            swap(&x.ARRAY->arr[i-1],&x.ARRAY->arr[i]);
        }
    n++;
    }
}

void ordenar_rest(Container x, Container to_sort) {
    int n = 1;

    while(n < x.ARRAY->sizeofstack) {
        for(size_t i = n; i > 0 && SORT_I(i) < SORT_I(i-1); i--) {
            swap(&SORT->arr[i-1],&SORT->arr[i]);
            swap(&x.ARRAY->arr[i-1],&x.ARRAY->arr[i]);
        }
    n++;
    }
}