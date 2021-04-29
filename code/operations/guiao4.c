#include "operations.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../stack.h"
#include "../parser/parser.h"
#include "operations.h"


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

void concatenar_sa(Container* x,Container* y,Stack stack){
    if(x->label == Array && y->label == Array){
        for (int i= 0; i < y.ARRAY->sizeofstack;i++) push(*y.ARRAY->arr[i], stack);
    }
    if((x->label == String && y->label == String) ||(isNum(x) && y->label == String) ||(x->label == String && isNum(y)) ) strcat(x, y);
    if((x->label == String && y->label == Array) || (isNum(x) && y->label == Array)) prepend(x,y);
    if((x->label == Array && y->label == String) || (x->label == Array && isNum(y))) append(x,y);
    }

void range(Stack s) {
    for (int i = 0; i < s->arr->content; i++)
    {
        push(i, stack);
    }
}

void tamanho(Stack s) {
    int n = s->sizeofstack
    push(n, stack);
}
/**
 * \brief Devolve o valor do array com o indice indicado pelo o utilizador
 *
 *
 * @param Container (o array que vamos trabalhar com)
 * @param Container (indice para o array dado) 
 *
 */
void indice(Container* array, Container* indice, Stack s) {
    push(array->ARRAY->arr[indice->LONG],s);
}

void buscarXINICIO() {

}

void buscarXFIM() {

}

void removerINICIO() {

}

void removerFIM() {

}

void substring() {

}

void separar_sub(Stack s) { // pegar no último e dar push das substrings

}

void separar_space(Container* x) {

}

void separar_lines(Container* x) {

}
//----------FUNÇÕES AUXILIARES----------
/**
 * \brief Função auxiliar para concatenar uma string com um array
 *
 * @param Container (A String)
 * @param Container (O Array) 
 *
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
 */
Container append(Container x, Container y) {
    push(y,x.ARRAY);
}