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

/**
 * \brief lê todo o input do terminal
 *
 * @param Container
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

/**
 * \brief Coloca um array numa stack
 *
 * @param Stack 
 * @param Container (O array dado) 
 *
 */
void colocar_stack(Stack stack, Container array) {
    for(int n= 0;n < array.ARRAY->sizeofstack;n++) push(array.ARRAY->arr[n], stack);
    free(array.ARRAY);
}

/**
 * \brief Concatena strings ou arrays
 *
 * @param Container (Um array, uma String ou um enum)
 * @param Container (Um array, uma String ou um enum)
 *
 */
void concatenar_sa(Stack stack, Container x, Container y) { // TODO(Mota): algo de errado não está certo
    if(x.label == Array && y.label == Array){
        for (int i= 0; i < y.ARRAY->sizeofstack;i++) push(y.ARRAY->arr[i], stack);
    }
    // este if abaixo é literalmente o caso (x.label == String && y.label == String) apenas
    if((x.label == String && y.label == String) ||(IS_NUM(x) && y.label == String) ||(x.label == String && IS_NUM(y)) ) strcat(x.STRING, y.STRING);
    // estas condições de baixo estão quase bem, mas precisam de ser revistas
    else if((x->label == String && y->label == Array) || (IS_NUM(x) && y->label == Array)) prepend(x,y); // HASHKEY much?
    else if((x->label == Array && y->label == String) || (x->label == Array && isNum(y))) append(x,y);
}

/**
 * \brief Coloca um array numa stack
 *
 * @param Container (Um array, uma String ou um enum)
 * @param Container (Um array, uma String ou um enum)
 *
 */
void range(Stack s,Container x) {
    Container res = { .label = Long };
    for (int i = 0; i < x.LONG; i++) {
        res.LONG = i;
        push(res,s);
    }
}

/**
 * \brief Devolve o tamanho de uma string ou array
 *
 * @param Container (Um array, ou uma string)
 *
 */
void length(Stack s,Container x) {
    Container n = { .label = Long, .LONG = (x.label != String) ? (long) x.ARRAY->sizeofstack : (long) strlen(x.STRING) };
    push(n, s);
}

/**
 * \brief Devolve o valor do array com o indice indicado pelo o utilizador
 *
 *
 * @param Container (o array que vamos trabalhar com)
 * @param Container (indice para o array dado) 
 *
 */
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

// buscarXINICIO
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
            res.label = Array;
            res.ARRAY = initialize_stack();
            for(int i = 0; i < y.LONG; i++) push(x.ARRAY->arr[i],res.ARRAY); // como isto faz um for na mesma, certo é possível não usar pointers... caso de dúvidas: ver prepend
            free(x.ARRAY);
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

/**
 * \brief Devolve o valor do indice da primeira ocurrencia de uma substring numa dada string
 *
 *
 * @param Stack
 * @param Container (string a verificar)
 * @param Container (subtring a procurar)  
 *
 */
void substring(Stack s, Container str, Container substr) { // VERIFICAR SE É MESMO ISTO!

    long a = strspn(str.STRING,substr.STRING);
    Container res = { .label = Long, .LONG = a };
    push(res,s);
}

/**
 * \brief Separa uma string em elementos de um array pelas as ocorrencias de uma determinada substring
 *
 *
 * @param Stack
 * @param Container (string a separar)
 * @param Container (subtring a usar como separadora)  
 *
 */
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

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de whitespace
 *
 *
 * @param Stack
 * @param Container (string a separar) 
 *
 */
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

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de newlines
 *
 *
 * @param Stack
 * @param Container (string a separar) 
 *
 */
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
 
/**
 * \brief Função auxiliar para concatenar um número com um array
 *
 * @param Container (O número)
 * @param Container (O Array) 
 *
 * @returns Container
 */
Container prepend(Container x, Container y) { // TODO: definir isto no .h, also melhorei esta para não mexer em pointers, foi my bad
    push(y.ARRAY->arr[y.ARRAY->sizeofstack],y.ARRAY);
    for(int i = y.ARRAY->sizeofstack; i ; i--) {
        y.ARRAY->arr[i] = y.ARRAY->arr[i-1];
    }
    y.ARRAY->arr[0] = x;
    return y;
}

/**
 * \brief Função auxiliar para concatenar um array com um número
 *
 * @param Container (O Array)
 * @param Container (A String) 
 *
 * @returns Container
 */
Container append(Container x, Container y) { // TODO: definir isto no .h
    push(y,x.ARRAY);
}