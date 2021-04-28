#include "operations.h"
#include "../types.h"
#include <assert.h>

/**
 * \brief Operacao com dois numeros, independentemente do tipo
 *
 * @param Funcao e operador
 * 
 * @returns Retorna uma funcao que faz operacao com dois numeros 
 */
#define MATH_OPERATION(func, op)                                    \
    void func(Container* x,Container* y,Stack s) {                  \
        Container res;                                              \
        res.label = numReturn(x->label,y->label);                   \
        res.DOUBLE = op(toDouble(*x).DOUBLE,toDouble(*y).DOUBLE);   \
        to_num_type(res.label,&res);                                \
        push(res,s);                                                \
    }

/**
 * \brief Soma dois numeros 
 */
#define SOMA(x, y) x + y
/**
 * \brief Subtrai dois numeros 
 */
#define SUBTRAI(x, y) x - y
/**
 * \brief Multiplica dois numeros 
 */
#define MULTIPLICA(x, y) x* y
/**
 * \brief Divisao dois numeros 
 */
#define DIVIDE(x, y) x / y

/**
 * \brief Operacao com dois inteiros
 *
 * @param Funcao e operador
 * 
 * @returns Retorna uma funcao que faz operacao com dois inteiros
 */
#define INTEGER_OPERATION(func, op)                         \
    void func(Container* x, Container* y, Stack s) {        \
        Container res;                                      \
        if (!(x->label || y->label))                        \
            res.LONG = (*x).LONG op (*y).LONG;              \
        else                                                \
            assert(0 || "Error: wrong type");               \
        res.label = Long;                                   \
        push(res,s);                                        \
    }

MATH_OPERATION(soma, SOMA)
MATH_OPERATION(subtrai, SUBTRAI)
MATH_OPERATION(multiplica, MULTIPLICA)
MATH_OPERATION(divide, DIVIDE)
MATH_OPERATION(potencia, pow)
INTEGER_OPERATION(modulo, %)
INTEGER_OPERATION(bitwiseand, &)
INTEGER_OPERATION(bitwiseor, |)
INTEGER_OPERATION(bitwisexor, ^)

#define _CREMENTOS(func,op)                         \
    void func(Container* x) {                       \
        switch (x->label) {                         \
            case Double:                            \
                op(*x).DOUBLE;                      \
                break;                              \
            case Long:                              \
                op(*x).LONG;                        \
                break;                              \
            case Char:                              \
                op(*x).CHAR;                        \
                break;                              \
            default:                                \
                assert(0 || "Error: wrong type");   \
        }                                           \
    }                                               

_CREMENTOS(decrementa,--)
_CREMENTOS(incrementa,++)

void bitwisenot(Container* x) {
    if (x->label == Long) (*x).LONG = ~(*x).LONG;
}