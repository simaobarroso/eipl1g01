#include "operations.h"

// acrescentar os próximos operadores aqui
enum OpType {
    Unary = 0,
    Binary
};

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
};

int optype(int op) {
    int res;
    if(op == ' ') res = -1;
    else if(op == ')' || op == '(' || op == '~') res = Unary;
    else res = Binary;
    return res;
}

int operation(char op, int *x) {
    int res;
    switch(op) {
        case Soma:
            res = soma(x-1);
            break;
        case Subtrai:
            res = subtrai(x-1);
            break;
        case Multiplica:
            res = multiplica(x-1);
            break;
        case Divide:
            res = divide(x-1);
            break;
        case Modulo:
            res = modulo(x-1);
            break;
        case Potencia:
            res = potencia(x-1);
            break;
        case Bitwiseand:
            res = bitwiseand(x-1);
            break;
        case Bitwiseor:
            res = bitwiseor(x-1);
            break;
        case Bitwisexor:
            res = bitwisexor(x-1);
            break;
        case Incrementa:
            res = incrementa(x);
            break;
        case Decrementa:
            res = decrementa(x);
            break;
        case Bitwisenot:
            res = bitwisenot(x);
            break;
        default:
            break;
            res = -1;
    }
    return res;
}

int soma (int *x) {
    return((*x) + x[1]);
}

int subtrai (int *x) {
    return((*x) - x[1]);
}

int multiplica (int *x) {
    return((*x) * x[1]);
}

int divide (int *x) {
    return((x[1] != 0) 
        ? ((*x) / x[1])
        : 0);
} 

int modulo (int *x) {
    return((*x) % x[1]);
}

int potencia (int *x) {
    return(pow ((*x), x[1]));
}

int bitwiseand (int *x) {
    return((*x) & x[1]);
}

int bitwiseor (int *x) {
    return((*x) | x[1]);
}

int bitwisexor (int *x) {
    return((*x) ^ x[1]);
}

int incrementa (int *x) {
	return (*x)++;
}

int decrementa (int *x) {
	return (*x)--;
}

int bitwisenot (int *x) {
    return(~(*x));
}
