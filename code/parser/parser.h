#include "../stack.h"
#ifndef PARSER_H
#define PARSER_H

/**
 * \brief Os vários operadores matemáticos
 */
enum Operations {
    NewLine = 'l',
    Either = 'e',   // isto vai criar condições consoante o carater seguinte
    Soma_concat = '+',
    Subtrai = '-',
    Multiplica_concatT_fold = '*',
    Divide_separa = '/',
    Modulo_map = '%',
    Potencia_subsindex = '#',
    Bitwiseand = '&',
    Bitwiseor = '|',
    Bitwisexor = '^',
    Incrementa_colocaStack = ')',
    Decrementa_colocaStack = '(',
    Bitwisenot_stackarr_exebloco = '~',
    ToChar = 'c',
    ToInt = 'i',
    ToString = 's',
    ToDouble = 'f',
    Troca3 = '@',
    Inverte2 = '\\',
    Duplica = '_',
    CopiaN_ordena = '$',
    Pop = ';',
    Menor_eleminit = '<',
    Maior_elemend = '>',
    Igual_valindex = '=',
    Nao = '!',
    MudaVariavel = ':',
    Ifthenelse = '?',
    LerInput = 't',
    Length_filter = ',',
    ExecCondBloco = 'w'

    // acrescentar os próximos operadores aqui (próximos guiões)
};

/**
 * \brief Definição das variáveis
 */
enum Variaveis {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

/**
 * \brief Mesma função definida em cima
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Stack 
 * @param String (Char*) 
 *
 */
 void parser(Stack*,char*,Container*);

/**
 * \brief Realiza as operações a serem executadas
 *
 * @param String
 * @param Stack
 * @param Container
 * @param Hashmap
 * @param Int
 *
 */
void operation(char*, Stack*, Container*, int*, int*);

/**
 * \brief Dá parse a números 
 *
 * @param String (Char*)
 * @param Stack
 * @param Container
 * @param Int
 *
 * @returns Container
 *
 */
Container number_parse(char*,int*);

void fazer_bloco(Stack*,char*,int*);

void newline(Stack*,char*,int*);

#endif /* PARSER_H */