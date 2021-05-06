#include "operations.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * \brief Variável global para tamanho
 */
#define SIZE 10240

/*
ISTO PRECISA DOS CASOS PARA STRING EM QUASE TUDO PORQUE USAR A FUNÇÃO string_to_array DEVIA SER EVITADO!

Also, definam isto no .h pls... mesmo para a documentação
*/


void ler_input(Stack s) {
    char string[SIZE], *c;
    assert(fgets(string,SIZE,stdin) != NULL);
    c = strchr(string,'\0');
    while (*(c - 1) == '\n') {
        fgets(c,SIZE,stdin);
        c = strchr(string,'\0');
    }
    Container res = { .label = String, .STRING = strdup(string) };
    push(res,s);
}


void colocar_stack(Stack stack, Container array) {
    for(int n= 0;n < array.ARRAY->sizeofstack;n++) push(array.ARRAY->arr[n], stack);
    free(array.ARRAY);
}

void concatenarVezes (Stack stack, Container sa, Container x){
        for (int i = 0; i < x.LONG; i++)
        {
            concatenar_sa(stack,sa,sa);
        }
}

char* concatenarVezes_string (char* sa, long x){

}

void concatenar_sa(Stack stack, Container x, Container y) { 
    Container res;
    if(x.label == Array && y.label == Array){
        for (int i= 0; i < y.ARRAY->sizeofstack;i++) push(y.ARRAY->arr[i], x.ARRAY);
        return x;
    }
    else if(x.label == String && y.label == String){
        res.label = String;
        res.STRING = better_strcat(x.STRING, y.STRING);
        free(y.STRING);
    }
    
    else if((x.label == String || (IS_NUM(x))) && y.label == Array) prepend(x,y);
    else if((x.label == Array && y.label == String) || (x.label == Array && IS_NUM(y))) append(x,y);
    else if(x.label == String && IS_NUM(y)) {
            res.label = String;
            res.STRING = better_strcat(x.STRING ,toString(y).STRING);
            free(y.STRING);
        }
    else if(IS_NUM(x) && y.label == String){
            res.label = String;
            res.STRING = better_strcat(toString(x).STRING,y.STRING);
            free(x.STRING);
    }
    push(res,stack);
}

void range(Stack s,Container x) {
    Container res = { .label = Long };
    for (int i = 0; i < x.LONG; i++) {
        res.LONG = i;
        push(res,s);
    }
}


void length(Stack s,Container x) {
    Container n = { .label = Long, .LONG = (x.label != String) ? (long) x.ARRAY->sizeofstack : (long) strlen(x.STRING) };
    push(n, s);
}


void indice(Stack s, Container array, Container indice) {
    Container res;
    switch (array.label) {
        case Array: push(array.ARRAY->arr[indice.LONG],s); break;
        case String: 
            res.label = Char;
            res.CHAR = array.STRING[indice.LONG];
            push(res,s);
            break;
        default: ERROR_1
    }
}


void buscarXINICIO(Stack s, Container x, Container y) {
    Container res;
    switch (x.label) {
        case String:
            res.label = String;
            char* buffer = buscarXINICIO_string(x,y);
            res.STRING = strdup(buffer);
            free(buffer);
            break;
        case Array:
            x.ARRAY->sizeofstack = y.LONG;
            break;
        default: ERROR_1
    }
    push(res,s);
}


char* buscarXINICIO_string(Container string, Container index) {
    char* buffer = malloc(sizeof(char) * (strlen(string.STRING)));
    for(int i = 0; i < index.LONG; i++) buffer[i] = string.STRING[i];
    return buffer;
}


void buscarXFIM(Container x, Stack s, Container stack){
    Label ofres = stack.label;
    Stack new = initialize_stack();

    for (int i = s->sizeofstack - x.LONG; i < s->sizeofstack; i++)
    {
        push(s->arr[i],new);
    }

    Container res = { .label = stack.label, .ARRAY = new };
    free(stack.ARRAY);
    push(res,s);
}

char* buscarXFIM_string(Container string, Container index){
    char* buffer = malloc(sizeof(char) * (strlen(string.STRING)));
    int j = strlen(string.STRING) - index.LONG;
    for(int i = j+1; i <= index.LONG; i++) buffer[i] = string.STRING[i];
    return buffer;
}


void removerINICIO(Stack s, Container stack) {
    Label ofres = stack.label;
    Stack new = initialize_stack();
    for (int i = 1; i < s->sizeofstack; i++)
    {
        push(s->arr[i],new);
    }

    Container res = { .label = stack.label, .ARRAY = new };
    free(stack.ARRAY);
    push(res,s);
}

void removerFIM(Stack s, Container stack) {
    Container res;
    switch (stack.label) {
        case Array:
            res = pop(stack.ARRAY);
            push(stack,s);
            push(res,s);
            break;
        case String:
            res.label = String;
            res.STRING = removerFIM_string(s,stack.STRING);
            push(res,s);
            break;
        default: ERROR_1
    }
}

char* removerFIM_string(Stack s, char* string) {
    Container res = { .label = Char, .CHAR = *(strchr(string,'\0') - 1) };
    push(res,s);
    *(strchr(string,'\0') - 1) = '\0';
    return string;
}


void substring(Stack s, Container str, Container substr) { // VERIFICAR SE É MESMO ISTO!

    long a = strspn(str.STRING,substr.STRING);
    Container res = { .label = Long, .LONG = a };
    push(res,s);
}


void separar_sub(Stack s, Container str, Container substr) {
    
    int n;
    Container buffer = { .label = String };
    Container res = { .label = Array, .ARRAY = initialize_stack() };
   
    while (str.STRING != NULL)
    {
        n = strspn(str.STRING,substr.STRING);
        buffer.STRING = n ? strndup(str.STRING,n) : str.STRING;

        push(buffer,res.ARRAY);

        str.STRING += n ? n + 1 : strlen(str.STRING);

    }
    
    push(res,s);
    
}


void separar_which_space(Stack s, Container x, Container format) {
    (format.CHAR == '\n') ? separar_lines(s,x) : separar_space(s,x);
}


void separar_space(Stack s, Container x) {

    Stack of_res = initialize_stack();
    Container res = { .label = Array, .ARRAY = of_res };
    Container buffer = { .label = String };
    char* to_push;
    int i = 0, o = 0;
    while (x.STRING != NULL)
    {
        if (isspace(x.STRING[i]) != 0) o++;
        else {
            buffer.STRING = strndup(x.STRING,o);
            x.STRING += o + 1;
            push(buffer,res.ARRAY);
        }
        i++;
    }
    push(res,s);
}


void separar_lines(Stack s, Container x) {
    Stack of_res = initialize_stack();
    Container res = { .label = Array, .ARRAY = of_res };
    Container buffer = { .label = String };
    char* to_push;
    int i = 0, o = 0;
    while (x.STRING != NULL)
    {
        if ((x.STRING[i]) != '\n') o++;
        else {
            buffer.STRING = strndup(x.STRING,o);
            x.STRING += o + 1;
            push(buffer,res.ARRAY);
        }
        i++;
    }
    push(res,s);
}
 
//----------FUNÇÕES AUXILIARES----------
 

Container prepend(Container x, Container y) { 
    push(y.ARRAY->arr[y.ARRAY->sizeofstack],y.ARRAY);
    for(int i = y.ARRAY->sizeofstack; i ; i--) {
        y.ARRAY->arr[i] = y.ARRAY->arr[i-1];
    }
    y.ARRAY->arr[0] = x;
    return y;
}


Container append(Container x, Container y) { 
    push(y,x.ARRAY);
    return x;
}

