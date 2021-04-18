#include "operations.h"

/**
 * \brief Os vários operadores matemáticos
 */
enum Operations {
    NewLine = 'l',
    Either = 'e',   // isto vai criar condições consoante o carater seguinte
    Soma = '+',
    Subtrai = '-',
    Multiplica = '*',
    Divide = '/',
    Modulo = '%',
    Potencia = '#',
    Bitwiseand = '&',
    Bitwiseor = '|',
    Bitwisexor = '^',
    Incrementa = ')',
    Decrementa = '(',
    Bitwisenot = '~',
    ToChar = 'c',
    ToInt = 'i',
    ToString = 's',
    ToDouble = 'f',
    Troca3 = '@',
    Inverte2 = '\\',
    Duplica = '_',
    CopiaN = '$',
    Pop = ';',
    Menor = '<',
    Maior = '>',
    Igual = '=',
    Nao = '!',
    CopiaTopo = ':',
    Ifthenelse = '?'

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
 void parser(Stack*,char*,int*,Container*);

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

/**
 * \brief Controla os valores das variáveis
 *
 * @param Stack
 * @param Char
 * @param Container
 * @param Int
 *
 */
void variavel(Stack*,char,Container*,int);