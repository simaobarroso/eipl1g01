#ifndef OPERATIONS_H
#define OPERATIONS_H

/**
 * @file Ficheiro com as várias invocações às funções de operações
 */
#include "../stack.h"

#include <math.h>

void* initialize_hashmap(void);

/**
 * \brief A soma de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da soma das variáveis
 */
Container soma(Container,Container);
/**
 * \brief A subtração de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da subtração das variáveis
 */
Container subtrai(Container,Container);
/**
 * \brief A multiplicação de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da multiplicação das variáveis
 */
Container multiplica(Container,Container);
/**
 * \brief A divisão de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da divisão inteira das variáveis
 */
Container divide(Container,Container);
/**
 * \brief O modulo de duas variáveis
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do modulo das variáveis
 */
Container modulo(Container,Container);
/**
 * \brief A potência de uma variável elevada à outra
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor da potência
 */
Container potencia(Container,Container);
/**
 * \brief Forma um "e lógico" bitwise
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do "e lógico"
 */
Container bitwiseand(Container,Container);
/**
 * \brief Forma um bitwiseor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwiseor
 */
Container bitwiseor(Container,Container);
/**
 * \brief Forma um bitwisexor
 *
 * @param Duas variáveis do tipo int (integer)
 *
 * @returns O valor do bitwisexor
 */
Container bitwisexor(Container,Container);
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
 * @param Stack
 */
void troca3(Stack*);
/**
 * \brief Mete o 2º valor da stack no topo
 *
 * @param Stack
 */
void inverte2(Stack*);
/**
 * \brief Duplica o valor do topo da stack
 *
 * @param Stack
 */
void duplica(Stack*);
/**
 * \brief Copia o n-ésimo valor da stack (o valor no topo da stack é 0) e mete esse valor no topo
 *
 * @param Stack
 */
void copiaN(Stack*);
/**
 * \brief Devolve o contrário do valor dado, por exemplo, se for 0, devolve 1, se for diferente de 0 devolve 0
 *
 * @param Stack
 */
Container nao(Stack*);
/**
 * \brief Vê se um valor é menor que outro, se for menor, devolve esse valor, se não devolve 0
 *
 * @param Stack
 */
Container menor(Stack*);
/**
 * \brief Vê se um valor é maior que outro, se for maior, devolve esse valor, se não devolve 0
 *
 * @param Um apontador para uma stack
 */
Container maior(Stack*);
/**
 * \brief Vê se um valor é igual ao outro, se for, devolve esse valor, se não devolve 0
 *
 * @param Stack
 */
Container igual(Stack*);
/**
 * \brief Se os dois argumnetos forem diferentes de 0, retorna o segundo argumento. Caso contrario, retorna 0.
 *
 * @param Stack
 */
Container elogic(Stack*);
/**
 * \brief Se os dois argumnetos forem iguais a 0, retorna 0. Caso contrario, devolve o primeiro argumento se este for verdadeiro, ou o segundo, caso contrario.
 *
 * @param Stack
 */
Container oulogic(Stack*);
/**
 * \brief Retorna o maior dos dois agrumentos a Stack.
 *
 * @param Stack
 */
Container compmaior(Stack*);
/**
 * \brief Retorna o menor dos dois argumentos a Stack.
 *
 * @param Uma stack
 */
Container compmenor(Stack*);
/**
 * \brief Necessita de três numeros, se o primeiro não for 0, devolve o segundo valor, se não, devolve o terceiro valor
 *
 * @param Stack
 */
Container ifthenelse(Stack*);
/**
 * \brief Função que inicializa as variáveis
 *
 * @param Container
 */
Container* initialize_vars(void);
/**
 * \brief Controla os valores das variáveis
 *
 * @param Stack
 * @param Char
 * @param Container
 * @param Int
 *
 */
void muda_variavel(Stack*,char,Container*,int);

#endif /* OPERATIONS_H */