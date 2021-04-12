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
    Container op1;
    switch (op) {
        case Soma:
            op1 = pop(stack);
            res = soma(pop(stack), op1);
            push(res, stack);
            break;
        case Subtrai:
            op1 = pop(stack);
            res = subtrai(pop(stack), op1);
            push(res, stack);
            break;
        case Multiplica:
            op1 = pop(stack);
            res = multiplica(pop(stack), op1);
            push(res, stack);
            break;
        case Divide:
            op1 = pop(stack);
            res = divide(pop(stack), op1);
            push(res, stack);
            break;
        case Modulo:
            op1 = pop(stack);
            res = modulo(pop(stack), op1);
            push(res, stack);
            break;
        case Potencia:
            op1 = pop(stack);
            res = potencia(pop(stack), op1);
            push(res, stack);
            break;
        case Bitwiseand:
            op1 = pop(stack);
            res = bitwiseand(pop(stack), op1);
            push(res, stack);
            break;
        case Bitwiseor:
            op1 = pop(stack);
            res = bitwiseor(pop(stack), op1);
            push(res, stack);
            break;
        case Bitwisexor:
            op1 = pop(stack);
            res = bitwisexor(pop(stack), op1);
            push(res, stack);
            break;
        case Incrementa:
            op1 = pop(stack);
            res = incrementa(op1);
            push(res, stack);
            break;
        case Decrementa:
            op1 = pop(stack);
            res = decrementa(op1);
            push(res, stack);
            break;
        case Bitwisenot:
            op1 = pop(stack);
            res = bitwisenot(op1);
            push(res, stack);
            break;
        case ToChar:
            op1 = pop(stack);
            res = toChar(op1);
            push(res, stack);
            break;
        case ToDouble:
            op1 = pop(stack);
            res = toDouble(op1);
            push(res, stack);
            break;
        case ToInt:
            op1 = pop(stack);
            res = toInt(op1);
            push(res, stack);
            break;
        case ToString:
            op1 = pop(stack);
            res = toString(op1);
            push(res, stack);
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
        case Pop:
            pop(stack);
            break;
        default:
            return;
    }
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