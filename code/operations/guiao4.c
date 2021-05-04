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
    char string[SIZE];
    char add[SIZE];
    assert(fgets(string,SIZE,stdin) != NULL);
    while (strchr(string,'\n') && strchr(fgets(add,SIZE,stdin),'\n')) {
		assert(add != NULL);
        strcat(string,add);
    }
    Container res = { .label = String, .STRING = strndup(string,strlen(string)-1) };
    push(res,s);
}
// 
// /**
//  * \brief Coloca um array numa stack
//  *
//  * @param Stack 
//  * @param Container (O array dado) 
//  *
//  */
// void colocar_stack(Stack stack, Container array){
//     for(int n= 0;n < array->ARRAY->sizeofstack;n++) push((*array).ARRAY->arr[n], stack);
// }
// 
// /**
//  * \brief Coloca um array numa stack
//  *
//  * @param Container (Um array, uma String ou um enum)
//  * @param Container (Um array, uma String ou um enum)
//  *
//  */
// void concatenar_sa(Container* x,Container* y,Stack stack) { // TODO(Mota): algo de errado não está certo
//     if(x->label == Array && y->label == Array){
//         for (int i= 0; i < y.ARRAY->sizeofstack;i++) push(*y.ARRAY->arr[i], stack);
//     }
//     if((x->label == String && y->label == String) ||(isNum(x) && y->label == String) ||(x->label == String && isNum(y)) ) strcat(x, y);
//     else if((x->label == String && y->label == Array) || (isNum(x) && y->label == Array)) prepend(x,y);
//     else if((x->label == Array && y->label == String) || (x->label == Array && isNum(y))) append(x,y);
// }
// 
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
    Container n = { .label = Long, .LONG = (x.label != String) ? (long)x.ARRAY->sizeofstack : (long)strlen(x.STRING) };
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
            for(int i = 0; i < y.LONG; i++) push(s->arr[i],res.ARRAY);
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
// 
// //push dos x ultimos elementos do array
// void buscarXFIM(Container x, Stack s, Container stack){
//     Label ofres = stack.label;
//     Stack new = initialize_stack();
//     
//     for (int i = s->sizeofstack - x.LONG; i < s->sizeofstack; i++)
//     {
//         push(s->arr[i],new);
//     }
//     
//     Container res = { .label = stack.label, .ARRAY = new };
//     free(stack.ARRAY);
//     push(res,s);
// }
// 
// void removerINICIO(Stack s, Container stack) {
//     Label ofres = stack.label;
//     Stack new = initialize_stack();
//     for (int i = 1; i < s->sizeofstack; i++)
//     {
//         push(s->arr[i],new);
//     }
//     
//     Container res = { .label = stack.label, .ARRAY = new };
//     free(stack.ARRAY);
//     push(res,s);
// }
// 
// void removerFIM(Stack s, Container stack) {
//     pop(stack.ARRAY);
//     push(stack,s);
// }
// 
// void substring(Stack s, Container x, Container y) {
// 
//     char* aux = x.STRING;
//     long a = strtok(x.STRING,y.STRING) - aux;
//     Container res = { .label = Long, .LONG = a };
//     push(res,s);
// }
// 
// 
// void separar_sub(Stack s, Container string, Container substring) { // pegar no último e dar push das substrings
// 
// }
// 
// void separar_space(Stack s, Container x) {
// 
//     Stack of_res = initialize_stack();
//     Container res = { .label = Array, .ARRAY = of_res };
//     Container buffer = { .label = String };
//     char* to_push;
//     int i = 0, o = 0;
//     while (x.STRING != NULL)
//     {
//         if (isspace(x.STRING[i]) != 0) o++;
//         else {
//             buffer.STRING = strdup(x.STRING,o);
//             x.STRING += o + 1;
//             push(buffer,res.ARRAY);
//         }
//         i++;
//     }
//     push(res,s);
// }
// 
// void separar_lines(tack s, Container x) {
//     Stack of_res = initialize_stack();
//     Container res = { .label = Array, .ARRAY = of_res };
//     Container buffer = { .label = String };
//     char* to_push;
//     int i = 0, o = 0;
//     while (x.STRING != NULL)
//     {
//         if ((x.STRING[i]) != '\n') o++;
//         else {
//             buffer.STRING = strdup(x.STRING,o);
//             x.STRING += o + 1;
//             push(buffer,res.ARRAY);
//         }
//         i++;
//     }
//     push(res,s);
// }
// 
// //----------FUNÇÕES AUXILIARES----------
// 
// /**
//  * \brief Função auxiliar para concatenar uma string com um array
//  *
//  * @param Container (A String)
//  * @param Container (O Array) 
//  *
//  * @returns Container
//  */
// Container prepend(Container x, Container y) {
//     Container res = { .label = Array, .ARRAY = initialize_stack() };
//     res.ARRAY->arr[0] = x;
//     for(int i = 0; i < y.ARRAY->sizeofstack; i++) push(pop(y.ARRAY),res.ARRAY);
//     free(y.ARRAY);
//     return res;
// }
// 
// /**
//  * \brief Função auxiliar para concatenar um array com uma string
//  *
//  * @param Container (O Array)
//  * @param Container (A String) 
//  *
//  * @returns Container
//  */
// Container append(Container x, Container y) {
//     push(y,x.ARRAY);
// }