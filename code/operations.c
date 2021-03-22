/**
 * @file Ficheiro com as várias possibilidades de operações a serem executadas
 */
#include "operations.h"

/**
 * \brief Os vários operadores matemáticos
 */
enum Operations {
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
	Bitwisenot = '~'
    // acrescentar os próximos operadores aqui (próximos guiões)
};

/**
 * \brief Realiza as operações a serem executadas
 *
 * @param Operador e Stack  
 *
 */
void operation(char op, Stack *stack) {
    int res = 0;
    int op1 = pop(stack);
    switch(op) {
        case Soma:
            res = soma(pop(stack),op1);
            break;
        case Subtrai:
            res = subtrai(pop(stack),op1);
            break;
        case Multiplica:
            res = multiplica(pop(stack),op1);
            break;
        case Divide:
            res = divide(pop(stack),op1);
            break;
        case Modulo:
            res = modulo(pop(stack),op1);
            break;
        case Potencia:
            res = potencia(pop(stack),op1);
            break;
        case Bitwiseand:
            res = bitwiseand(pop(stack),op1);
            break;
        case Bitwiseor:
            res = bitwiseor(pop(stack),op1);
            break;
        case Bitwisexor:
            res = bitwisexor(pop(stack),op1);
            break;
        case Incrementa:
            res = incrementa(op1);
            break;
        case Decrementa:
            res = decrementa(op1);
            break;
        case Bitwisenot:
            res = bitwisenot(op1);
            break;
        default:
            return;
    }
    push(res,stack);
}

/**
 * \brief A soma de duas variáveis
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da soma das variáveis
 */
int soma (int x, int y) {
    return(x+y);
}

/**
 * \brief A subtração de duas variáveis
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da subtração das variáveis
 */
int subtrai (int x, int y) {
    return(x-y);
}


/**
 * \brief A multiplicação de duas variáveis
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da multiplicação das variáveis
 */
int multiplica (int x, int y) {
    return(x*y);
}

/**
 * \brief A divisão de duas variáveis
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da divisão inteira das variáveis
 */
int divide (int x, int y) {
    return((y != 0) 
        ? (x / y)
        : 0);
} 


/**
 * \brief O modulo de duas variáveis
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do modulo das variáveis
 */
int modulo (int x, int y) {
    return(x % y);
}

/**
 * \brief A potência de uma variável elevada à outra
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da potência
 */
int potencia (int x, int y) {
    return(pow (x, y));
}

/**
 * \brief Forma um "e lógico" bitwise
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do "e lógico"
 */
int bitwiseand (int x, int y) {
    return(x & y);
}

/**
 * \brief Forma um bitwiseor
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwiseor
 */
int bitwiseor (int x, int y) {
    return(x | y);
}


/**
 * \brief Forma um bitwisexor
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisexor
 */
int bitwisexor (int x, int y) {
    return(x ^ y);
}

/**
 * \brief Incrementação de uma unidade a uma variável int
 * 
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável acrescido de um
 */
int incrementa (int x) {
	return ++x;
}

/**
 * \brief Decrementação de uma unidade a uma variável int
 * 
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável decrescido de um
 */
int decrementa (int x) {
	return --x;
}

/**
 * \brief Forma um bitwisenot
 * 
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisenot
 */
int bitwisenot (int x) {
    return ~x;
}
