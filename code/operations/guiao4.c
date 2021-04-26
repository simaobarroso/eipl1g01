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
 * \brief Mesma função definida em cima
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Array 
 * @param Int (indice para o array dado) 
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

