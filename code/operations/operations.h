/**
 * @file Ficheiro com as várias invocações às funções de operações
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../control_types.h"
#include "../parser/parser.h"
#include "../stack/stack.h"

#include <math.h>

// GUIÃO 1

/**
 * \brief A soma de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da soma das variáveis
 */
void soma(Stack,Container,Container);
/**
 * \brief A subtração de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da subtração das variáveis
 */
void subtrai(Stack,Container,Container);
/**
 * \brief A multiplicação de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da multiplicação das variáveis
 */
void multiplica(Stack,Container,Container);
/**
 * \brief A divisão de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da divisão inteira das variáveis
 */
void divide(Stack,Container,Container);
/**
 * \brief O modulo de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do modulo das variáveis
 */
void modulo(Stack,Container,Container);
/**
 * \brief A potência de uma variável elevada à outra
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da potência
 */
void potencia(Stack,Container,Container);
/**
 * \brief Forma um "e lógico" bitwise
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do "e lógico"
 */
void bitwiseand(Stack,Container,Container);
/**
 * \brief Forma um bitwiseor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwiseor
 */
void bitwiseor(Stack,Container,Container);
/**
 * \brief Forma um bitwisexor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisexor
 */
void bitwisexor(Stack,Container,Container);
/**
 * \brief Incrementação de uma unidade a uma variável int
 *
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável acrescido de um
 */
void incrementa(Stack,Container);
/**
 * \brief Decrementação de uma unidade a uma variável int
 *
 * @param Uma variável do tipo int (integer)
 *
 * @returns O valor da variável decrescido de um
 */
void decrementa(Stack,Container);
/**
 * \brief Forma um bitwisenot
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisenot
 */
void bitwisenot(Stack,Container);

// GUIÃO 2

/**
 * \brief Troca o 3º valor da stack para o topo
 *
 * @param Stack
 */
void troca3(Stack);
/**
 * \brief Mete o 2º valor da stack no topo
 *
 * @param Stack
 */
void inverte2(Stack);
/**
 * \brief Duplica o valor do topo da stack
 *
 * @param Stack
 */
void duplica(Stack);
/**
 * \brief Copia o n-ésimo valor da stack (o valor no topo da stack é 0) e mete esse valor no topo
 *
 * @param Stack
 */
void copiaN(Stack);
/**
 * \brief Lê uma linha e insere-a como string na Stack
 *
 * @param Stack
 */
void newline(Stack);

// GUIÃO 3

/**
 * \brief Devolve o contrário do valor dado, por exemplo, se for 0, devolve 1, se for diferente de 0 devolve 0
 *
 * @param Stack
 */
void nao(Stack,Container);
/**
 * \brief Vê se um valor é menor que outro, se for menor, devolve esse valor, se não devolve 0
 *
 * @param Stack
 */
void menor(Stack,Container,Container);
/**
 * \brief Vê se um valor é maior que outro, se for maior, devolve esse valor, se não devolve 0
 *
 * @param Um apontador para uma stack
 */
void maior(Stack,Container,Container);
/**
 * \brief Vê se um valor é igual ao outro, se for, devolve esse valor, se não devolve 0
 *
 * @param Stack
 */
void igual(Stack,Container,Container);
/**
 * \brief Se os dois argumnetos forem diferentes de 0, retorna o segundo argumento. Caso contrario, retorna 0.
 *
 * @param Stack
 */
void elogic(Stack,Container,Container);
/**
 * \brief Se os dois argumnetos forem iguais a 0, retorna 0. Caso contrario, devolve o primeiro argumento se este for verdadeiro, ou o segundo, caso contrario.
 *
 * @param Stack
 */
void oulogic(Stack,Container,Container);
/**
 * \brief Retorna o maior dos dois agrumentos a Stack.
 *
 * @param Container
 * @param Container
 * @param Stack
 */
void compmaior(Stack,Container,Container);
/**
 * \brief Retorna o menor dos dois argumentos a Stack.
 *
 * @param Container
 * @param Container
 * @param Stack
 */
void compmenor(Stack,Container,Container);

/**
 * \brief Necessita de três numeros, se o primeiro não for 0, devolve o segundo valor, se não, devolve o terceiro valor
 *
 * @param Stack
 */
void ifthenelse(Stack,Container,Container,Container);

/**
 * \brief Controla os valores das variáveis
 *
 * @param Stack
 * @param Char
 * @param Container
 * @param Int
 *
 */
void muda_variavel(Stack,char,Container*,int);

/**
 * \brief Coverte o topo da stack para o tipo especificado na função
 *
 * @param Stack
 */
void to_int_op(Stack);

/**
 * \brief Coverte o topo da stack para o tipo especificado na função
 *
 * @param Stack
 */
void to_char_op(Stack);

/**
 * \brief Coverte o topo da stack para o tipo especificado na função
 *
 * @param Stack
 */
void to_double_op(Stack);

/**
 * \brief Coverte o topo da stack para o tipo especificado na função
 *
 * @param Stack
 */
void to_string_op(Stack);

// GUIÃO 4

/**
 * \brief Lê o input até encontrar o carater nulo
 *
 * @param Stack
 */
void ler_input(Stack);

/**
 * \brief Constrói um array do 0 até ao número dado
 *
 * @param Stack
 * @param Container
 */
void range(Stack,Container);

void length(Stack,Container);

void indice(Stack,Container,Container);

void buscarXINICIO(Stack,Container,Container);

char* buscarXINICIO_string(Container,Container);

void removerFIM(Stack,Container);

char* removerFIM_string(Stack,char*);

void substring(Stack,Container,Container);

// GUIÃO 5

// void foldf(Stack,char*);

// void map(Stack,char*);

#endif /* OPERATIONS_H */