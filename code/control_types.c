#include "control_types.h"
#include "operations.h"

#include <assert.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

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
        case Long: x.CHAR = x.LONG; x.label = Char; break;
        case Char: break;
        case Double: x.CHAR = toInt(x).LONG; x.label = Char; break;
        case String: x.CHAR = *x.STRING; x.label = Char; break;
        default: ERROR_1
    }
    return x;
}

Container toInt(Container x) {
    switch (x.label) {
        case Long: break;
        case Char: x.LONG = x.CHAR; x.label = Long; break;
        case Double: x.LONG = x.DOUBLE; x.label = Long; break;
        case String: x.LONG = strtol(x.STRING,NULL,10); x.label = Long; break;
        default: ERROR_1
    }
    return x;
}

Container toDouble(Container x) {
    long n;
    char c;
    switch (x.label) {
        case Long: n = x.LONG; x.DOUBLE = n; x.label = Double; break;
        case Char: c = x.CHAR; x.DOUBLE = c; x.label = Double; break;
        case Double: break;
        case String: x.DOUBLE = strtod(x.STRING,NULL); break;
        default: ERROR_1
    }
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
            ERROR_1
        x.label = String;
    }
    return x;
}

Container string_to_array(Container x) {
    Container res = { .label = Array, .ARRAY = initialize_stack() };
    Container buffer = { .label = Char };
    while(x.STRING) {
        buffer.CHAR = *x.STRING;
        push(buffer,res.ARRAY);
        x.STRING++;
    }
    free(x.STRING);
    return res;
}

Container array_to_string(Container x) {
    char* buffer;
    if (!all_char(x)) {
        x.label = Array;    
    }
    else {
        buffer = malloc(x.ARRAY->sizeofstack * sizeof(char));
        for(int i = 0; i < x.ARRAY->sizeofstack; i++) buffer[i] = x.ARRAY->arr[i].CHAR;
        free(x.ARRAY);
        x.label = String;
        x.STRING = buffer;
    }
    return x;
}

int all_char(Container x) {
    int i = 0;
    while(i < x.ARRAY->sizeofstack && x.ARRAY->arr[i].label == Char) i++;

    return i == x.ARRAY->sizeofstack;
}

int number_string(char** line, char** num, char** end) {
    size_t buff = strspn(*line,".-0123456789");
    *end = *line + buff;
    *num = strndup(*line, buff);
    return strchr(*num,'.') != NULL;
}

/**
 * \brief Função auxiliar para concatenar uma string com algo
 *
 * @param char
 * @param char
 *
 * @returns Container
 */
char* better_strcat(char* fonte, char* join) {
    fonte = (char *) realloc(fonte, (strlen(fonte) + strlen(join)) * sizeof(char) + 1);
    int len = strlen(join);
    char* end_fonte = strchr(fonte,'\0');
    while(len) {
        *(end_fonte++) = *(join++);
        len--;
    }
    *end_fonte = '\0';
    return fonte;
}