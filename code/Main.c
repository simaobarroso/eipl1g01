/**
 * @file Ficheiro que contêm a função principal do programa
 */

#include <assert.h>
#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CALC 10240

/**
 * \brief Preenche a stack e faz as várias operações na própria
 *
 * @param Stack e Input do terminal
 *
 */
void stackop(Stack *,char *);

/**
 * \brief Função main (função principal do programa)
 *
 * @returns O valor 0
 */
int main(void) {
    Stack s;
    initialize(&s);
    char calc[CALC];
    assert(fgets(calc, CALC, stdin) != NULL);

    stackop(&s, calc);
    for(int i = 0; i < s.sizeofstack; i++) {
        printf("%d", s.arr[i]);                                 // isto está errado --Mota
        /*
        printstack(&s);
        */
    }
    putchar('\n');
    free(s.arr);
    return 0;
}

/**
 * \brief Mesma função definida em cima 
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Stack e Input do terminal 
 *
 */

// vai ser preciso muita coisa aqui...
void stackop(Stack *stack, char *calc) {
    int i = 0;
    while(calc[i] != '\n' && calc[i] != '\0') {
        // para nums
        char num[15] = "";
        if(calc[i] >= '0' && calc[i] <= '9') { // 30 = '0' e 39 = '9'
            int sign = 1;
            
            while(calc[i] >= '0' && calc[i] <= '9') {
                if(i != 0 && calc[i-1] == '-') sign = -1;
                strncat(num,&calc[i],1);
                i++;
            }
            push((atoi(num)*sign), stack); // adaptar isto --Mota
        }
        // para ops
        else if(calc[i] != ' ' && !(calc[i+1] >= '0' && calc[i+1] <= '9')){
            operation(calc[i],stack);
        }
        i++;
    }
}

/*
Portanto, cenas:

A função push, apesar de estar adaptada, vai de certeza precisar de cenas que a ponham a
funfar direito, visto que estava adaptada a int. Tudo o que for operação de int neste
momento tem que funcionar ambas com double e long, logo acho preferível fazer as operações
com o que quer que receba imediatamente com o "case of".
Alguma explicação que seja necessária, por favor dizer!

ass.: Mota
*/