#include "control_types.h"
#include "operations.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * \brief Variável global para tamanho
 */
#define SIZE 8192

void ler_input(Stack s) {
    char* string = malloc(sizeof(char) * SIZE);
    char* save = string;
    string = fgets(string,SIZE,stdin);
    char* c = strchr(string,'\0');
    
    while (string) {
        string = fgets(c,SIZE,stdin);
        if (string) c = strchr(string,'\0');
    }
    Container res = { .label = String, .STRING = strdup(save) };
    free(save);
    push(res,s);
}

void colocar_stack(Stack stack, Container array) {
    for(int n= 0;n < array.ARRAY->sizeofstack;n++) push(array.ARRAY->arr[n], stack);
    free(array.ARRAY);
}

void concatenar_sa(Stack s, Container x, Container y) { 
    Container res = { .label = Array };
    if(x.label == Array && y.label == Array) {
        for (int i= 0; i < y.ARRAY->sizeofstack; i++) 
            push(y.ARRAY->arr[i], x.ARRAY);
        res = x;
        free(y.ARRAY);
    }
    else if(x.label == String && y.label == String) {
        res.label = String;
        res.STRING = better_strcat(x.STRING, y.STRING);
        free(y.STRING);
    }
    else
        res = concatenar_num_array(x,y);
    push(res,s);
}

Container concatenar_num_array(Container x, Container y) {
    Container res;
    if (x.label <= String && y.label == Array)
        res = prepend(x,y);
    else if (x.label == Array && y.label <= String)
        res = append(x,y);
    else
        res = concatenar_num_string(x,y);
    return res;
}

Container concatenar_num_string(Container x, Container y) {
    Container res = { .label = String };
    if (x.label == String && IS_NUM(y))
        res.STRING = better_strcat(x.STRING ,toString(y).STRING);
    else if (IS_NUM(x) && y.label == String)
        res.STRING = better_strcat(toString(x).STRING,y.STRING);
    else
        ERROR_1
    return res;
}

void concatenarVezes(Stack stack, Container sa, Container x) {
    Container res = { .label = sa.label };
    char* buffer;
    int size;
    switch(sa.label) {
        case String:
            buffer = strdup(sa.STRING);
            for(int i = 1; i < x.LONG; i++)
                sa.STRING = better_strcat(sa.STRING,buffer);
            free(buffer);
            buffer = NULL;
            res.STRING = sa.STRING;
            break;
        case Array:
            size = sa.ARRAY->sizeofstack;
            for(int i = size; i < (size * x.LONG); i++)
                push(sa.ARRAY->arr[i % size],sa.ARRAY);
            res.ARRAY = sa.ARRAY;
            break;
        default: ERROR_1
    }
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
            if (y.LONG) x.ARRAY->sizeofstack = y.LONG;
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
    Container to_push;
    switch (stack.label) {
        case Array:
            res = pop(stack.ARRAY);
            push(stack,s);
            push(res,s);
            break;
        case String:
            res.label = String;
            res.STRING = removerFIM_string(stack.STRING,&to_push);
            push(res,s);
            push(to_push,s);
            break;
        default: ERROR_1
    }
}

char* removerFIM_string(char* string, Container* to_push) {
    to_push->label = Char;
    to_push->CHAR = *(strchr(string,'\0') - 1);
    *(strchr(string,'\0') - 1) = '\0';
    return string;
}

void substring(Stack s, Container str, Container substr) {
    int free_substr = 0;
    if (str.label == Array) array_to_string(str);
    if (substr.label == Char) {
        substr = char_to_string(substr);
        free_substr = 1;
    }

    char* a = strstr(str.STRING,substr.STRING);
    Container res = { .label = Long, .LONG = (a) ? a - str.STRING : -1  };
    if (free_substr) free(substr.STRING);
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


void separar_which(Stack s, Container x, Container format) {
    switch(format.label) {
        case Char: (format.CHAR == '\n') ? separar_lines(s,x) : separar_space(s,x); break;
        case String: separar_string(s,x,format); break;
        default: ERROR_1
    }
}

void separar_string(Stack s, Container x, Container format) {
    Container res = { .label = Array, .ARRAY = initialize_stack() };
    Container buf = { .label = String };
    size_t f_length = strlen(format.STRING);
    char* buffer = x.STRING;
    if (!(*format.STRING)) {
        buf.STRING = x.STRING;
        push(buf,res.ARRAY);
    }
    else {
        while(*x.STRING) {
            buffer = (strstr(buffer,format.STRING)) ? strstr(buffer,format.STRING) : strchr(buffer,'\0');
            buf.STRING = strndup(x.STRING, buffer - x.STRING);
            push(buf,res.ARRAY);
            buffer += f_length;
            x.STRING = buffer;
        }
    }
    push(res,s);
}

void separar_space(Stack s, Container x) {
    Stack of_res = initialize_stack();
    Container res = { .label = Array, .ARRAY = of_res };
    Container buffer = { .label = String };
    // char* save = x.STRING;
    u_long n;
    while (*x.STRING)
    {
        n = strcspn(x.STRING,"\n\t\v\f\r ");
        buffer.STRING = strndup(x.STRING,n);
        x.STRING += strspn(x.STRING, "\n\t\v\f\r ") + n;
        if (n) push(buffer,res.ARRAY);
    }
    // free(save);
    push(res,s);
}

void separar_lines(Stack s, Container x) {
    Stack of_res = initialize_stack();
    Container res = { .label = Array, .ARRAY = of_res };
    Container buffer = { .label = String };
    // char* save = x.STRING;
    char* buf;
    u_long n;
    while (*x.STRING)
    {
        n = strcspn(x.STRING,"\n");
        buf = strndup(x.STRING,n);
        x.STRING += strspn(x.STRING, "\n") + n;
        buffer.STRING = buf;
        if (n) push(buffer,res.ARRAY);
    }
    // free(save);
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

/**
  * \brief Simplifciação de escrita do topo da stack
  */
#define TOP s->arr[s->sizeofstack - 1]

void print_top(Stack s) {
    switch (s->arr[s->sizeofstack - 1].label) {
        case Long: printf("%ld\n", TOP.LONG); break;
        case Double: printf("%g\n", TOP.DOUBLE); break;
        case Char: printf("%c\n", TOP.CHAR); break;
        case String: printf("%s\n", TOP.STRING); break;
        case Array: printstack(TOP.ARRAY); putchar('\n'); break;
        case Lambda: printf("%s", TOP.LAMBDA); break;
        default: ERROR_3
    }
}