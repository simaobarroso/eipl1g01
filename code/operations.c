/**
 * @file Ficheiro com as várias possibilidades de operações a serem executadas
 */
#include "operations.h"

#include <assert.h>

void operation(char op, Stack* stack) {
    Container res;
    Container op1 = pop(stack);
    switch (op) {
        case Soma:
            res = soma(pop(stack), op1);
            break;
        case Subtrai:
            res = subtrai(pop(stack), op1);
            break;
        case Multiplica:
            res = multiplica(pop(stack), op1);
            break;
        case Divide:
            res = divide(pop(stack), op1);
            break;
        case Modulo:
            res = modulo(pop(stack), op1);
            break;
        case Potencia:
            res = potencia(pop(stack), op1);
            break;
        case Bitwiseand:
            res = bitwiseand(pop(stack), op1);
            break;
        case Bitwiseor:
            res = bitwiseor(pop(stack), op1);
            break;
        case Bitwisexor:
            res = bitwisexor(pop(stack), op1);
            break;
        case Incrementa:
            res = incrementa(op1);
            break;
        case Decrementa:
            res = decrementa(op1);
            break;
        case Bitwisenot:
            res = bitwisenot(op1);
            break;
        case ToChar:
            res = toChar(op1);
            break;
        default:
            return;
    }
    push(res, stack);
}

#define MATH_OPERATION(func, op)                           \
    Container func(Container x, Container y) {             \
        Container res;                                     \
        res.label = Double;                                \
        if (x.label == Double && y.label == Double) {      \
            res.content.f = op(x.content.f, y.content.f);  \
        } else if (x.label == Double && y.label == Long) { \
            res.content.f = op(x.content.f, y.content.l);  \
        } else if (x.label == Long && y.label == Double) { \
            res.content.f = op(x.content.l, y.content.f);  \
        } else if (x.label == Long && y.label == Long) {   \
            res.content.l = op(x.content.l, y.content.l);  \
            res.label = Long;                              \
        } else                                             \
            assert(0 || "Error: wrong type");              \
        return res;                                        \
    }
#define SOMA(x, y) x + y
#define SUBTRAI(x, y) x - y
#define MULTIPLICA(x, y) x* y
#define DIVIDE(x, y) x / y
#define INTEGER_OPERATION(func, op)                     \
    Container func(Container x, Container y) {          \
        Container res;                                  \
        res.label = Long;                               \
        if (x.label == Long && y.label == Long) {       \
            res.content.l = x.content.l op y.content.l; \
        } else                                          \
            assert(0 || "Error: wrong type");           \
        return res;                                     \
    }

MATH_OPERATION(soma, SOMA)
MATH_OPERATION(subtrai, SUBTRAI)
MATH_OPERATION(multiplica, MULTIPLICA)
MATH_OPERATION(divide, DIVIDE)
MATH_OPERATION(potencia, pow)
INTEGER_OPERATION(bitwiseand, &)
INTEGER_OPERATION(bitwiseor, |)
INTEGER_OPERATION(bitwisexor, ^)

Container incrementa(Container x) {
    switch (x.label) {
        case Double:
            ++x.content.f;
            break;
        case Long:
            ++x.content.l;
            break;
        case Char:
            ++x.content.c;
    }
    return x;
}

Container decrementa(Container x) {
    switch (x.label) {
        case Double:
            --x.content.f;
            break;
        case Long:
            --x.content.l;
            break;
        case Char:
            --x.content.c;
    }
    return x;
}

Container bitwisenot(Container x) {
    if (x.label == Long) x.content.l = ~x.content.l;
    return x;
}

Container toChar(Container x) {
    if (x.label == Long) {
        x.content.c = x.content.l;
        x.label = Char;
    }
    return x;
}