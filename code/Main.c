#include <stdio.h>
#include <math.h>
#include <assert.h>

// Definições das funcoes matematicas

int soma(int num1, int num2);
int subtrai(int num1, int num2);
int multiplica(int num1, int num2);
int divide(int num1, int num2);
int modulo(int num1, int num2);
int potencia(int num1, int num2);
int incrementa(int num1, int num2); // num2 sempre 1
int decrementa(int num1, int num2); // num2 sempre 1
int bitwiseand(int num1, int num2);
int bitwiseor(int num1, int num2);
int bitwisexor(int num1, int num2);
int bitwisenot(int num1, int num2); // num2 sempre 1

//*****************************************
// Main
int main (){
    //leitura da string de operaçoes
    assert( fgets(s, STRSIZE, stdin) != NULL);

}
//*****************************************
//funcoes matematicas

int soma (int x, int y) {
  return(x + y);
}

int subtrai (int x, int y) {
  return(x - y);
}

int multiplica (int x, int y) {
  return(x * y);
}

int divide (int x, int y) {
  if (y != 0)
    return (x / y);
  else
    return 0;
} 

int modulo (int x, int y) {
    return (x % y);
}

int potencia (int x, int y) {
    return (pow (x, y));
}

int bitwiseand (int x, int y) {
    return (x & y);
}

int bitwiseor (int x, int y) {
    return (x | y);
}

int bitwisexor (int x, int y) {
    return (x ^ y);
}

int incrementa (int x, int y) {
	return (y + x);
}

int decrementa (int x, int y) {
	return (y - x);
}

int bitwisenot (int x, int y) {
    return ((~ y) * x);
}

