#include "operations.h"
#include "../stack.h"
#include "../parser/parser.h"

#include <assert.h>
#include <stdlib.h>
#include "operations.h"
#include "../stack.h"
#include "../parser/parser.h"

#include <assert.h>
#include <stdlib.h>
/*
void parser_block() {
    MOTA POR FAVOR TRATA DISTO :(
}
*/

void aplicarbloco(){

}

void map(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    Stack map = initialize_stack();
    if (x.label == String) string_to_array(x);
    Label res_label = x.label;
    int i = 0;
    while (x.ARRAY->sizeofstack) {
        push(x.ARRAY->arr[i],map);
        parser(map,y.STRING,hashtable,vars);
        x.ARRAY->sizeofstack--;
        i++;
    }
    free(x.ARRAY);
    Container res = { .label = res_label, .ARRAY = map };
    push(res,s);
}

void fold(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    while (x.ARRAY->sizeofstack != 1) {
        parser(x.ARRAY,y.STRING,hashtable,vars);
    }
    Container res = pop(x.ARRAY);
    push(res,s);
}

void filter(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    Stack filter = initialize_stack();
    if (x.label == String) string_to_array(x);
    Label res_label = x.label;
    int i = 0;
    while (x.ARRAY->sizeofstack) {
        push(x.ARRAY->arr[i],filter);
        parser(x.ARRAY,y.STRING,hashtable,vars);
        Container check = toDouble(filter->arr[filter->sizeofstack - 1]);
        if (check.DOUBLE == 0) pop(filter);
        x.ARRAY->sizeofstack--;
        i++;
    }
    free(x.ARRAY);
    Container res = { .label = res_label, .ARRAY = filter };
    push(res,s);
}

void ordenar(Stack s, Container x, Container y, OperatorFunction* hashtable, Container* vars) {
    Stack sort = initialize_stack();
    if (x.label == String) string_to_array(x);
}