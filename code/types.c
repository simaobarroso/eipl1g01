#include "types.h"
#include "operations/operations.h"

#include <assert.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 100

#define IS_FOLDABLE(c) c.label >= String && !Lambda
/*
int isFoldable(Container c) {
    return (c.label >= String && !Lambda);
}
*/

#define IS_NUM(c) c.label <= Char
/*
int isNum(Container c) {
    return (c.label <= Char);
}
*/

#define FOLD_TYPE(c) Array - (c.label == String) + (c.label == String_A)
/*
Label foldType(Container c) {
    return Array - (c.label == String) + (c.label == String_A);
}
*/

#define NUM_RETURN(x,y) x >= y ? x : y
/*
Label numReturn(Label x, Label y) {
    return (x >= y) ? x : y;
}
*/

Container to_num_type(Label l, Container* x) {
    switch (l) {
        case Long: *x = toInt(*x); break;
        case Double: *x = toDouble(*x); break;
        case Char: *x = toChar(*x); break;
        default: ERROR_1
    }
    return *x;
}

Container toChar(Container x) {
    switch (x.label) {
        case Long: x.CHAR = x.LONG; break;
        case Char: break;
        case Double: x.CHAR = toInt(x).LONG; break;
        default: ERROR_1
    }
    x.label = Char;
    return x;
}

Container toInt(Container x) {
    char* end;
    char result[20];
    switch (x.label) {
        case Long: break;
        case Char: x.LONG = x.CHAR; break;
        case Double: x.LONG = x.DOUBLE; break;
        case String: 
            number_string(x.STRING, result, &end);
            x.LONG = strtol(x.STRING,&x.STRING +strlen(x.STRING) - 1,10); break;
        default: ERROR_1
    }
    x.label = Long;
    return x;
}

Container toDouble(Container x) {
    char* end;
    char result[20];
    switch (x.label) {
        case Long: x.DOUBLE = x.LONG; break;
        case Char: x.DOUBLE = x.CHAR; break;
        case Double: break;
        case String: 
            number_string(x.STRING, result, &end);
            x.DOUBLE = strtod(result,&end); break;
        default: ERROR_1
    }
    x.label = Double;
    return x;
}

Container toString(Container x) { // tentar implementar apenas quando aparece o "l"
    char str[SIZE];
    if (x.label != String && x.label != String_A) {
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
            ERROR_1
        x.label = String;
    }
    return x;
}

// eu espero bem que isto deixe de ser necessário --Mota
Container string_to_array(Container x) {
    Container res = { .label = String_A, .ARRAY = initialize_stack() };
    Container buffer = { .label = Char };
    while(x.STRING) {
        buffer.CHAR = *x.STRING;
        push(buffer,res.ARRAY);
        x.STRING++;
    }
    return res;
}

int number_string(char* s, char* result, char** end) {
    size_t buff = strcspn(s,".-0123456789");
    result = strndup(s, buff);
    return strchr(result,'.') != NULL;
}