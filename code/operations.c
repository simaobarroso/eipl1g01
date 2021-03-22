#include "operations.h"

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

int soma (int x, int y) {
    return(x+y);
}

int subtrai (int x, int y) {
    return(x-y);
}

int multiplica (int x, int y) {
    return(x*y);
}

int divide (int x, int y) {
    return((y != 0) 
        ? (x / y)
        : 0);
} 

int modulo (int x, int y) {
    return(x % y);
}

int potencia (int x, int y) {
    return(pow (x, y));
}

int bitwiseand (int x, int y) {
    return(x & y);
}

int bitwiseor (int x, int y) {
    return(x | y);
}

int bitwisexor (int x, int y) {
    return(x ^ y);
}

int incrementa (int x) {
	return ++x;
}

int decrementa (int x) {
	return --x;
}

int bitwisenot (int x) {
    return ~x;
}
