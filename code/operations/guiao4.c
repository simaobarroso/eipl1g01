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


Container concatenar(Container x, Container y) { 
    Container res = { .label = Array };
    if(x.label == Array && y.label == Array) {
        for (int i= 0; i < y.ARRAY->sizeofstack; i++) push(y.ARRAY->arr[i], x.ARRAY);
        res = x;
        free(y.ARRAY);
    }
    else if(x.label == String && y.label == String) {
        res.label = String;
        res.STRING = better_strcat(x.STRING, y.STRING);
        free(y.STRING);
    }
    else if((x.label == String || (IS_NUM(x))) && y.label == Array) res = prepend(x,y);
    else if((x.label == Array && y.label == String) || (x.label == Array && IS_NUM(y))) res = append(x,y);
    else if(x.label == String && IS_NUM(y)) {
        res.label = String;
        res.STRING = better_strcat(x.STRING ,toString(y).STRING);
    }
    else if(IS_NUM(x) && y.label == String){
        res.label = String;
        res.STRING = better_strcat(toString(x).STRING,y.STRING);
    }
    return res;
}

/*
void concatenarVezes (Stack stack, Container sa, Container x) { // well, esta dá treta, como eu temia, se tentarmos fazer isto com o mesmo array também vai dar, nem preciso de ver
        Container res;
        res.label = (sa.label != String) ? Array : String;
        res = concatenar(sa,sa);
        for (int i = 1; i < x.LONG; i++)
        {
            res = concatenar(res,sa);
        }
        push(res,stack);
}
*/

char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); 
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void concatenarVezes (Stack stack, Container sa, Container x) {
        Container res;
        switch(sa.label){
        case String:
            char* aux = sa.STRING;
            char* saa = sa.STRING;
            Container res;
                for (int i = 1; i < x.LONG; i++)
                {
                    res.STRING = concat(aux,saa);
                    aux = res.STRING;
                    free(res.STRING);
                }
            push(res,stack);
          break;
        case Array:
                 Container aux2 = sa;
                 Container res;
                 res.ARRAY->sizeofstack = x.LONG * sa.ARRAY->sizeofstack;
                        for(int i= 0; i < (res.ARRAY->sizeofstack);i++){
                                res.ARRAY->arr[i] = aux2.ARRAY->arr[i % x.LONG];
                                
                        }
            push(res,stack);
          break;
  }
}

void concatenar_sa(Stack stack, Container x, Container y) { 
    Container res = concatenar(x,y);
    push(res,stack);
}

void range(Stack s,Container x) {
    Stack new = initialize_stack();
    Container range = { .label = Long };
    for (int i = 0; i < x.LONG; i++) {
        range.LONG = i;
        push(range,new);
    }
    Container res = { .label = Array, .ARRAY = new };
    push(res,s);
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
            if (y.LONG) x.ARRAY->sizeofstack = y.LONG; // ver isto amanhã
            res = x;
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

void buscarXFIM(Stack s, Container gt, Container x) {
    Container res = { .label = gt.label };
    Stack new;
    switch (gt.label) {
        case Array:
            new = initialize_stack();
            for (int i = gt.ARRAY->sizeofstack - x.LONG; i < gt.ARRAY->sizeofstack; i++)
            {
                push(gt.ARRAY->arr[i],new);
            }

            res.ARRAY = new;
            free(gt.ARRAY);
            break;
        case String:
            res.STRING = buscarXFIM_string(gt,x);
            break;
        default: ERROR_1
    }
    push(res,s);
}   

char* buscarXFIM_string(Container string, Container index) {
    char* buffer = strchr(string.STRING, '\0') - index.LONG;
    buffer = strdup(buffer);
    free(string.STRING);
    return buffer;
}

void removerINICIO(Stack s, Container gt) {
    Stack new;
    Container res = { .label = gt.label };
    Container to_push;
    switch(res.label) {
        case Array:  
            new = initialize_stack();
            res.ARRAY = new;
            to_push = gt.ARRAY->arr[0];
            for (int i = 1; i < gt.ARRAY->sizeofstack; i++)
            {
                push(gt.ARRAY->arr[i],new);
            }
            free(gt.ARRAY);
            break;
        case String:
            res.STRING = removerINICIO_string(gt.STRING,&to_push);
            break;
        default: ERROR_1
    }
    push(res,s);
    push(to_push,s);
}

char* removerINICIO_string(char* string, Container* to_push) {
    char* save = string;
    char* to_dup = string;
    to_push->label = Char; 
    to_push->CHAR = *to_dup;
    string = strdup(string+1);
    free(save);
    return string;
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

void substring(Stack s, Container str, Container substr) {
    
    char* a = strstr(str.STRING,substr.STRING);
    Container res = { .label = Long, .LONG = a - str.STRING  };
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

        str.STRING += n ? n + 1 : (int)strlen(str.STRING);
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
    char* save = x.STRING, *buf = x.STRING;
    int i = 0;
    while (x.STRING[i])
    {
        if (isspace(x.STRING[i])) {
            buffer.STRING = strndup(buf,&x.STRING[i] - buf);
            buf = &x.STRING[i+1];
            push(buffer,res.ARRAY);
        }
        else if (!x.STRING[i+1]) {
            buffer.STRING = strndup(buf,&x.STRING[i+1] - buf);
            push(buffer,res.ARRAY);
        }
        i++;
    }
    free(save);
    push(res,s);
}

void separar_lines(Stack s, Container x) {
    Stack of_res = initialize_stack();
    Container res = { .label = Array, .ARRAY = of_res };
    Container buffer = { .label = String };
    char* save = x.STRING, *buf = x.STRING;
    int i = 0;
    while (x.STRING[i])
    {
        if (x.STRING[i] == '\n') {
            buffer.STRING = strndup(buf,&x.STRING[i] - buf);
            buf = &x.STRING[i+1];
            push(buffer,res.ARRAY);
        }
        else if (!x.STRING[i+1]) {
            buffer.STRING = strndup(buf,&x.STRING[i+1] - buf);
            push(buffer,res.ARRAY);
        }
        i++;
    }
    free(save);
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