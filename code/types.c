#include "types.h"
#include "operations/operations.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100

int isFoldable(Container c) {
    return (c.label >= String && !Lambda);
}

int isNum(Container c) {
    return (c.label <= Char);
}

Label foldType(Container c) {
    return (c.label == Array) ? Array : String;
}

Label numReturn(Label x, Label y) {
    return (x > y) ? x : y;
}

void to_num_type(Label l, Container* x) {
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
            x.CHAR = x.LONG;
            x.label = Char;
        } else if (x.label == Double) {
            x.CHAR = toInt(x).LONG;
        }
        else
            assert(0 || "Error: wrong type");
        x.label = Char;
    }
    return x;
}

Container toInt(Container x) {
    switch (x.label) {
        case Long: break;
        case Char: x.LONG = x.CHAR; break;
        case Double: x.LONG = x.DOUBLE; break;
        case String: x.LONG = strtol(x.STRING,&x.STRING+strlen(x.STRING),10); break;
        default: assert(0 || "Error: wrong type");
    }
    x.label = Long;
    return x;
}

Container toDouble(Container x) {
    switch (x.label) {
        case Long: x.DOUBLE = x.LONG; break;
        case Char: x.DOUBLE = x.CHAR; break;
        case Double: break;
        case String: x.LONG = strtod(x.STRING,&x.STRING+strlen(x.STRING)); break;
        default: assert(0 || "Error: wrong type");
    }
    x.label = Long;
    return x;
}

Container toString(Container x) { // tentar implementar apenas quando aparece o "l"
    char str[SIZE];
    if (x.label != String) {
        if (x.label == Long) {
            sprintf(str,"%ld",x.LONG);
            x.STRING = strdup(str);
        } else if (x.label == Char) {
            sprintf(str,"%c",x.CHAR);
            x.STRING = strdup(str);
        }
        else if (x.label == Double) {
            sprintf(str,"%g",x.DOUBLE);
            x.STRING = strdup(str);
        } else 
            assert(0 || "Error: wrong type");
        x.label = String;
    }
    return x;
}
