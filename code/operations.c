#include "operations.h"

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
