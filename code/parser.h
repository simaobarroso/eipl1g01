#include "operations.h"

/**
 * \brief Os vários operadores matemáticos
 */
enum Operations {
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
    Not = '!',
    CopiaTopo = ':',
    IfThenElse = '?'

    // acrescentar os próximos operadores aqui (próximos guiões)
};

enum Variaveis {
    A,
    B,
    C,
    D,
    E,
    F,
    G,
    H,
    I,
    J,
    K,
    L,
    M,
    N,
    O,
    P,
    Q,
    R,
    S,
    T,
    U,
    V,
    W,
    X,
    Y,
    Z
};
/**
 * \brief Mesma função definida em cima
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Stack e Input do terminal
 *
 */
 void parser(Stack*,char*,int*,Container*);

/**
 * \brief Realiza as operações a serem executadas
 *
 * @param Operador e Stack
 *
 */
void operation(char*, Stack*, Container*, int*);
Container number_parse(char*,int*);
void variavel(Stack*,char,Container*,int);