/**
 * @file Ficheiro com as várias possibilidades de operações a serem executadas
 */
#include "operations.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief "Variavel global"
 */
#define SIZE 100

void to_type(Label l, Container* x) {
    switch (l) {
        case Long: *x = toInt(*x); break;
        case Double: *x = toDouble(*x); break;
        case Char: *x = toChar(*x); break;
        default: assert(0 || "Error: wrong type");
    }
}

Container toChar(Container x) {
    if (x.label != Char) {
        if (x.label == Long) {
            x.content.c = x.content.l;
            x.label = Char;
        } else if (x.label == Double) {
            x.content.c = toInt(x).content.l;
        }
        else
            assert(0 || "Error: wrong type");
        x.label = Char;
    }
    return x;
}

Container toInt(Container x) {
    if (x.label != Long) {
        if (x.label != String)
            x.content.l = (x.label == Double) ? x.content.f : x.content.c;
        else
            assert(0 || "Error: wrong type");
        x.label = Long;
    }
    return x;
}

Container toDouble(Container x) {
    if (x.label != Double) {
        if (x.label != String)
            x.content.f = (x.label == Long) ? x.content.l : x.content.c;
        else
            assert(0 || "Error: wrong type");
        x.label = Double;
    }
    return x;
}

Container toString(Container x) { // tentar implementar apenas quando aparece o "l"
    char str[SIZE];
    if (x.label != String) {
        if (x.label == Long) {
            sprintf(str,"%ld",x.content.l);
            x.content.s = strdup(str);
        } else if (x.label == Char) {
            sprintf(str,"%c",x.content.c);
            x.content.s = strdup(str);
        }
        else if (x.label == Double) {
            sprintf(str,"%g",x.content.f);
            x.content.s = strdup(str);
        } else 
            assert(0 || "Error: wrong type");
        x.label = String;
    }
    return x;
}