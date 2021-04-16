/**
 * @file Ficheiro com as várias invocações às funções de operações
 */
#include "stack.h"

#include <math.h>

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
    CopyTop = ':',
    IfThenElse = '?',
    A = 'A',
    B = 'B',
    C = 'C',
    D = 'D',
    E = 'E',
    F = 'F',
    NewLine = 'N',
    S = 'S',
    X = 'X',
    Y = 'Y',
    Z = 'Z'

    // acrescentar os próximos operadores aqui (próximos guiões)
};

#define MATH_OPERATION_HEADER(func) Container func(Container, Container)

/**
 * \brief Realiza as operações a serem executadas
 *
 * @param Operador e Stack
 *
 */
void operation(char, Stack*);
/**
 * \brief A soma de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da soma das variáveis
 */
MATH_OPERATION_HEADER(soma);
/**
 * \brief A subtração de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da subtração das variáveis
 */
MATH_OPERATION_HEADER(subtrai);
/**
 * \brief A multiplicação de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da multiplicação das variáveis
 */
MATH_OPERATION_HEADER(multiplica);
/**
 * \brief A divisão de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da divisão inteira das variáveis
 */
MATH_OPERATION_HEADER(divide);
/**
 * \brief O modulo de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do modulo das variáveis
 */
MATH_OPERATION_HEADER(modulo);
/**
 * \brief A potência de uma variável elevada à outra
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da potência
 */
MATH_OPERATION_HEADER(potencia);
/**
 * \brief Forma um "e lógico" bitwise
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do "e lógico"
 */
MATH_OPERATION_HEADER(bitwiseand);
/**
 * \brief Forma um bitwiseor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwiseor
 */
MATH_OPERATION_HEADER(bitwiseor);
/**
 * \brief Forma um bitwisexor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisexor
 */
MATH_OPERATION_HEADER(bitwisexor);
/**
 * \brief Incrementação de uma unidade a uma variável int
 *
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável acrescido de um
 */
Container incrementa(Container);
/**
 * \brief Decrementação de uma unidade a uma variável int
 *
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável decrescido de um
 */
Container decrementa(Container);
/**
 * \brief Forma um bitwisenot
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisenot
 */
Container bitwisenot(Container);
/**
 * \brief Converte para char
 *
 * @param Uma variável de qualquer tipo
 *
 * @returns O valor em Char
 */
Container toChar(Container);
/**
 * \brief Converte para Int
 *
 * @param Uma variável de qualquer tipo
 *
 * @returns O valor em Int
 */
Container toInt(Container);
/**
 * \brief Converte para Double
 *
 * @param Uma variável de qualquer tipo
 *
 * @returns O valor em Double
 */
Container toDouble(Container);
/**
 * \brief Converte para String
 *
 * @param Uma variável de qualquer tipo
 *
 * @returns O valor em String
 */
Container toString(Container);
/**
 * \brief Troca o 3º valor da stack para o topo
 *
 * @param Uma stack
 */
void troca3(Stack*);
/**
 * \brief Mete o 2º valor da stack no topo
 *
 * @param Uma stack
 */
void inverte2(Stack*);
/**
 * \brief Duplica o valor do topo da stack
 *
 * @param Uma stack
 */
void duplica(Stack*);
/**
 * \brief Copia o n-ésimo valor da stack (o valor no topo da stack é 0) e mete esse valor no topo
 *
 * @param Uma stack
 */
void copiaN(Stack*);