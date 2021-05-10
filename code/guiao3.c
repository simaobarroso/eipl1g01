#include "control_types.h"
#include "operations.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// primeiro
// segundo
/**
 * \brief Facilitador de escrita de operações lógicas que retornam "bool"
 */
#define LOGIC_OPERATION(func,op) 								    \
	void func(Stack stack, Container x, Container y) {			    \
        if (BOTH_FOLDABLE(x.label,y.label)) func##_ex(stack,x,y);   \
		else {                                                      \
            Container res = { .label = Long }; 						\
		    res.LONG = (toDouble(x).DOUBLE op toDouble(y).DOUBLE);	\
		    push(res,stack); 										\
        }                                                           \
	}

LOGIC_OPERATION(igual,==)
LOGIC_OPERATION(menor,<)
LOGIC_OPERATION(maior,>)

void nao(Stack s,Container x){
	toInt(x);
	x.LONG = !x.LONG;
	push(x,s);
}

// x primeiro
// y segundo
void elogic(Stack stack, Container x, Container y) {
	Container res = { .label = Long, .LONG = 0 }; 																		
	if (toDouble(x).DOUBLE) res = y;
	push(res,stack);
}

void oulogic(Stack stack, Container x, Container y) {
	Container res;
	Label x_l = x.label;
	Label y_l = y.label;
	x = toDouble(x);
	y = toDouble(y);
	res = (x.DOUBLE && (x.DOUBLE || y.DOUBLE) && x.DOUBLE > y.DOUBLE)
		? to_num_type(x_l,&x)
		: to_num_type(y_l,&y);
	push(res,stack);
}

// x segundo
// y primeiro
/**
 * \brief Facilitador de escrita de operações lógicas que retornam o maior/menor dos números inseridos
 */
#define EITHER_COMPARE_OPERATION(func,op) 								\
	void func(Stack stack, Container x, Container y) { 					\
        if (BOTH_FOLDABLE(x.label, y.label)) func##_ex(stack,x,y);      \
		else {                                                          \
            Container res; 												\
		    Label x_l = x.label; 										\
		    Label y_l = y.label; 										\
		    res = (toDouble(x).DOUBLE op toDouble(y).DOUBLE) 			\
		    	? to_num_type(x_l,&x) 									\
		    	: to_num_type(y_l,&y); 									\
		    push(res,stack); 											\
        }                                                               \
	}

EITHER_COMPARE_OPERATION(compmaior,>)
EITHER_COMPARE_OPERATION(compmenor,<)

void ifthenelse(Stack stack, Container x, Container y, Container z) {
	Container res;
    res = IF_CONDITION(x) ? y : z;
	push(res,stack);
}

// novos casos

void igual_ex (Stack s, Container x, Container y) {
    Container res = { .label = Long };
    switch (x.label)
    {
    case String:
        res.LONG = (strcmp(x.STRING,y.STRING) == 0);
        push(res,s);
        break;
    case Array:
        res.LONG = (arraycmp(x.ARRAY,y.ARRAY) == 0);
        push(res,s);
        break;
    default: ERROR_1
    }
}

void maior_ex(Stack s, Container x , Container y) {
  Container res = { .label = Long };
    switch (x.label)
    {
    case String:
        if (strcmp(x.STRING,y.STRING) > 0) res.LONG = 1;
        else res.LONG = 0;
        push(res,s);
        break;
    case Array:
        if (arraycmp(x.ARRAY,y.ARRAY) > 0) res.LONG = 1;
        else res.LONG = 0;
        push(res,s);
        break;
    default: ERROR_1
    }
}

void menor_ex(Stack s, Container x , Container y) {
    Container res = { .label = Long };
    switch (x.label)
    {
    case String:
        if (strcmp(x.STRING,y.STRING) < 0) res.LONG = 1;
        else res.LONG = 0;
        push(res,s);
        break;
    case Array:
        if (arraycmp(x.ARRAY,y.ARRAY) < 0) res.LONG = 1;
        else res.LONG = 0;
        push(res,s);
        break;
    default: ERROR_1
    }
}

void compmaior_ex(Stack s, Container x , Container y) {
    Container res;
    switch (x.label)
    {
    case String:
        res.label = String;
        if (strcmp(x.STRING,y.STRING) > 0) res.STRING = x.STRING;
        else res.STRING = y.STRING;
        push(res,s);
        break;
    case Array:
        res.label = Array;
        if (arraycmp(x.ARRAY,y.ARRAY) > 0) res.ARRAY = x.ARRAY;
        else res.ARRAY = y.ARRAY;
        push(res,s);
        break;
    default: ERROR_1
    }
}

void compmenor_ex(Stack s, Container x , Container y) {
    Container res;
    switch (x.label)
    {
    case String:
        res.label = String;
        if (strcmp(x.STRING,y.STRING) < 0) res.STRING = x.STRING;
        else res.STRING = y.STRING;
        push(res,s);
        break;
    case Array:
        res.label = Array;
        if (arraycmp(x.ARRAY,y.ARRAY) < 0) res.ARRAY = x.ARRAY;
        else res.ARRAY = y.ARRAY;
        push(res,s);
        break;
    default: ERROR_1
    }
}