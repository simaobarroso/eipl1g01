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

}

void range(Stack s) {

}

void tamanho(Stack s) {

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

void buscarX() {

}

void remover() {

}

void substring() {

}

void separar_sub(Stack s) { // pegar no último e dar push das substrings

}

void separar_space(Container* x) {

}

void separar_lines(Container* x) {

}