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
 * @param Array 
 *
 */
void ColocarStack(Stack *stack, Container *array){
for(int n= 0;n < array.ARRAY->sizeofstack;n++) push(array.ARRAY->arr[n], stack);
}

void ConcatenarSA(){

}

void TamnhoRange(){

}

/**
 * \brief Devolve o valor do array com o indice indicado pelo o utilizador
 *
 *
 * @param Container (o array que vamos trabalhar com)
 * @param Container (indice para o array dado) 
 *
 */
Container Indice(Container array, Container indice) {
    return array.ARRAY[indice.LONG];
}

void BuscarX(){

}

void Remover(){

}

void Substring(){

}


void SepararSub(){

}

void SepararSpace(){

}

void SepararLines(){

}

