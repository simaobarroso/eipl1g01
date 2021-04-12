/**
 * @file Ficheiro com as várias possibilidades de operações a serem executadas
 */
#include "operations.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>

#define CALC 4096

void operation(char op, Stack* stack) {
    Container res;
    initializeContainer(&res,NotAType);
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
            case ToDouble:
            res = toDouble(op1);
            break;
        case ToInt:
            res = toInt(op1);
            break;
        case ToString:
            res = toString(op1);
            break;  
        case Troca3:
            troca3(stack);
            break;
        case Inverte2:
            inverte2(stack);
            break;
        case Duplica:
            duplica(stack);
            break;
        case CopiaN:
            copiaN(stack);
            break;
        default:
            return;
    }
    push(res, stack);
}

// precisa de documentação
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
// precisa de documentação
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
INTEGER_OPERATION(modulo, %)
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
            break;
        default:
            assert(0 || "Error: wrong type");
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
        break;
        default:
            assert(0 || "Error: wrong type");
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
    } else if (x.label == Double) {
        x.content.c = toInt(x).content.l;
    }
    else
        assert(0 || "Error: wrong type");
    x.label = Char; 
    return x;
}

Container toInt(Container x) {
    if (x.label != String || x.label != NotAType)
        x.content.l = (x.label == Double) ? x.content.f : x.content.c;
    else
        assert(0 || "Error: wrong type");
    x.label = Long;
    return x;
}

Container toDouble(Container x) {
    if (x.label != String)
        x.content.f = (x.label == Long) ? x.content.l : x.content.c;
    else
        assert(0 || "Error: wrong type");
    x.label = Double;
    return x;
}

Container toString(Container x) { // eu depois quero explicar algo acerca disto
    char str[CALC];
    if (x.label == Long) {
        sprintf(str,"%ld",x.content.l);  //se o long for unsigned e %lu, senao e %ld - João
        x.content.s = str;
    } else if (x.label == Char) {
        sprintf(str,"%c",x.content.c);
        x.content.s = str;
    }
    else if (x.label == Double) {
        sprintf(str,"%g",x.content.f);
        x.content.s = str;
    } else 
        assert(0 || "Error: wrong type");
    x.label = String;
    return x;            
}

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
    push(stack->arr[stack->sizeofstack], stack);
}

void copiaN(Stack *stack) {
    Container copy = pop(stack); // vai buscar o indice a tirar da stack
    long n;
    if (copy.label == Long) {
        n = copy.content.l; // o indice tem que ser long
        push(stack->arr[stack->sizeofstack - n], stack); // dá push do elemento no indice no topo
    }
    else
        assert(0 || "Error: wrong type");
}