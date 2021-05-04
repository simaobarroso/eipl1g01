#include "operations.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../stack.h"
#include "../parser/parser.h"
#include "operations.h"

/**
 * \brief Variável global para tamanho
 */
#define SIZE 10240

/**
 * \brief lê todo o input do terminal
 *
 * @param Container
 */
void ler_input(Stack s) {
    char* string;
    assert(fgets(string,SIZE,stdin) != NULL);
    while (strchr(string,'\0')) {
        char* add;
        assert(fgets(add,SIZE,stdin) != NULL);
        strcat(string,add);
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
void colocar_stack(Container* array, Stack stack){
    for(int n= 0;n < array->ARRAY->sizeofstack;n++) push(array->ARRAY->arr[n], stack);
}

/**
 * \brief Coloca um array numa stack
 *
 * @param Container (Um array, uma String ou um enum)
 * @param Container (Um array, uma String ou um enum)
 *
 */
void concatenar_sa(Container* x,Container* y,Stack stack) { // TODO(Mota): algo de errado não está certo
    if(x->label == Array && y->label == Array){
        for (int i= 0; i < y.ARRAY->sizeofstack;i++) push(*y.ARRAY->arr[i], stack);
    }
    if((x->label == String && y->label == String) ||(isNum(x) && y->label == String) ||(x->label == String && isNum(y)) ) strcat(x, y);
    else if((x->label == String && y->label == Array) || (isNum(x) && y->label == Array)) prepend(x,y);
    else if((x->label == Array && y->label == String) || (x->label == Array && isNum(y))) append(x,y);
}

/**
 * \brief Coloca um array numa stack
 *
 * @param Container (Um array, uma String ou um enum)
 * @param Container (Um array, uma String ou um enum)
 *
 */
void range(Container x,Stack s) { // ok, esta definitivamente precisa de ser revista...
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
void tamanho(Stack s,Container x) {
    Container n = { .label = Long, .LONG = (x.label != String) ? x.ARRAY->sizeofstack : strlen(x.STRING) };
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
    push(array.ARRAY->arr[indice.LONG],s);
}


void buscarXINICIO(Stack s, Container x) {
    Label ofres = x.label;
    if (ofres == String) string_to_array(x);
    Stack new = initialize_stack();
    
    for (int i = 0; i < x.LONG; i++)
    {
        push(s->arr[i],new);
    }
    
    Container res = { .label = ofres, .ARRAY = new };
    free(x.ARRAY);
    push(res,s);
}

//push dos x ultimos elementos do array
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
    pop(stack.ARRAY);
    push(stack,s);
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
void substring(Stack s, Container str, Container substr) {

    char* aux = str.STRING;
    long a = strtok(str.STRING,substr.STRING) - aux;
    Container res = { .label = Long, .LONG = a };
    push(res,s);
}

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de uma determinada substring
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
    Container res = { .label = Array, .ARRAY = initialize_stack()};
   
    while (str.STRING != NULL)
    {
        n = strspn(str.STRING,substr.STRING);

        if (n != 0) (buffer.STRING = strdup(x.STRING,n));
        else buffer.STRING = x.STRING;

        push(buffer,res.ARRAY);

        x.STRING += (n != 0) ? n + 1 : strlen(x.STRING);

    }
    
    push(res,s);
    
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
            buffer.STRING = strdup(x.STRING,o);
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
            buffer.STRING = strdup(x.STRING,o);
            x.STRING += o + 1;
            push(buffer,res.ARRAY);
        }
        i++;
    }
    push(res,s);
}

//----------FUNÇÕES AUXILIARES----------

/**
 * \brief Função auxiliar para concatenar uma string com um array
 *
 * @param Container (A String)
 * @param Container (O Array) 
 *
 * @returns Container
 */
Container prepend(Container x, Container y) {
    Container res = { .label = Array, .ARRAY = initialize_stack() };
    res.ARRAY->arr[0] = x;
    for(int i = 0; i < y.ARRAY->sizeofstack; i++) push(pop(y.ARRAY),res.ARRAY);
    free(y.ARRAY);
    return res;
}

/**
 * \brief Função auxiliar para concatenar um array com uma string
 *
 * @param Container (O Array)
 * @param Container (A String) 
 *
 * @returns Container
 */
Container append(Container x, Container y) {
    push(y,x.ARRAY);
}