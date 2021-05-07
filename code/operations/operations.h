/**
 * @file Ficheiro com as várias invocações às funções de operações
 */
#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "../control_types.h"
#include "../parser/parser.h"
#include "../stack/stack.h"

#include <math.h>

// -------------------- GUIÃO 1 --------------------

/**
 * \brief A soma de duas variáveis
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void soma(Stack,Container,Container);
/**
 * \brief A subtração de duas variáveis
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void subtrai(Stack,Container,Container);
/**
 * \brief A multiplicação de duas variáveis
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void multiplica(Stack,Container,Container);
/**
 * \brief A divisão de duas variáveis
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void divide(Stack,Container,Container);
/**
 * \brief O modulo de duas variáveis
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void modulo(Stack,Container,Container);
/**
 * \brief A potência de uma variável elevada à outra
 *
 * @param Container Um dos valor a dividir
 * 
 * @param Container Um dos valor a dividir
 */
void potencia(Stack,Container,Container);
/**
 * \brief Forma um "e lógico" bitwise
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void bitwiseand(Stack,Container,Container);
/**
 * \brief Forma um bitwiseor
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void bitwiseor(Stack,Container,Container);
/**
 * \brief Forma um bitwisexor
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void bitwisexor(Stack,Container,Container);
/**
 * \brief Incrementação de uma unidade a uma variável int
 *
 * @param Container Um dos valor a usar
 * 
 * @param Container Um dos valor a usar
 */
void incrementa(Stack,Container);
/**
 * \brief Decrementação de uma unidade a uma variável int
 *
 * @param Container Valor a usar
 */
void decrementa(Stack,Container);
/**
 * \brief Forma um bitwisenot
 *
 * @param Container Valor a usar
 */
void bitwisenot(Stack,Container);

// -------------------- GUIÃO 2 --------------------

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
/**
 * \brief Mesmo que a pop, mas para ser usada no array de funções
 *
 * @param Stack
 */
void void_pop(Stack);

// -------------------- GUIÃO 3 --------------------

/**
 * \brief Devolve o contrário do valor dado, por exemplo, se for 0, devolve 1, se for diferente de 0 devolve 0
 *
 * @param Stack
 * 
 * @param Container Valor a usar
 */
void nao(Stack,Container);
/**
 * \brief Vê se um valor é menor que outro, se for menor, devolve esse valor, se não devolve 0
 *
 * @param Stack
 * 
 * @param Container Valor a comparar
 * 
 * @param Container Valor a comparar
 */
void menor(Stack,Container,Container);
/**
 * \brief Vê se um valor é maior que outro, se for maior, devolve esse valor, se não devolve 0
 *
 * @param Stack
 * 
 * @param Container Valor a comparar
 * 
 * @param Container Valor a comparar
 */
void maior(Stack,Container,Container);
/**
 * \brief Vê se um valor é igual ao outro, se for, devolve esse valor, se não devolve 0
 *
 * @param Stack
 * 
 * @param Container Valor a comparar
 * 
 * @param Container Valor a comparar
 */
void igual(Stack,Container,Container);
/**
 * \brief Se os dois argumnetos forem diferentes de 0, retorna o segundo argumento. Caso contrario, retorna 0.
 *
 * @param Stack
 * 
 * @param Container Valor a verificar
 * 
 * @param Container Valor a verificar
 */
void elogic(Stack,Container,Container);
/**
 * \brief Se os dois argumnetos forem iguais a 0, retorna 0. Caso contrario, devolve o primeiro argumento se este for verdadeiro, ou o segundo, caso contrario.
 *
 * @param Stack
 * 
 * @param Container Valor a verificar
 * 
 * @param Container Valor a verificar
 */
void oulogic(Stack,Container,Container);
/**
 * \brief Retorna o maior dos dois agrumentos a Stack.
 *
 * @param Stack
 * 
 * @param Container Valor a comparar
 * 
 * @param Container Valor a comparar
 */
void compmaior(Stack,Container,Container);
/**
 * \brief Retorna o menor dos dois argumentos a Stack.
 *
 * @param Stack
 * 
 * @param Container Valor a comparar
 * 
 * @param Container Valor a comparar
 */
void compmenor(Stack,Container,Container);

/**
 * \brief Necessita de três numeros, se o primeiro não for 0, devolve o segundo valor, se não, devolve o terceiro valor
 *
 * @param Stack
 * 
 * @param Container Valor a verificar
 * 
 * @param Container Valor a verificar
 * 
 * @param Container Valor a verificar
 */
void ifthenelse(Stack,Container,Container,Container);

/**
 * \brief Controla os valores das variáveis
 *
 * @param Stack
 * 
 * @param Char Variavel a qual se vai atribuir o valor
 * 
 * @param Container Array das variaveis
 * 
 * @param Int Valor a atribuir
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

// -------------------- GUIÃO 4 --------------------

/**
 * \brief Lê o input até encontrar o carater nulo
 *
 * @param Stack
 */
void ler_input(Stack);

/**
 * \brief Coloca um array numa stack
 *
 * @param Stack 
 * 
 * @param Container Array a usar
 */
void colocar_stack(Stack, Container);

/**
 * \brief Função auxiliar que concatena duas Strings/Arrays 
 *
 * @param Container Array/String a concatenar
 * 
 * @param Container Array/String a concatenar
 *
 * \returns Array/String concatenado
 */
Container concatenar(Container x, Container y);

/**
 * \brief Copia a String / Array e concatena-a X vezes
 *
 * @param Stack
 * 
 * @param Container Array/String a usar
 *
 * @param Container Array/String a usar
 */
void concatenarVezes (Stack,Container,Container);

/**
 * \brief Função auxiliar
 *
 * 
 * @param const char 
 *
 * @param const char 
 * 
 */
char* concat(const char *, const char *);

/**
 * \brief Concatena strings ou arrays
 *
 * @param Container Array/String a concatenar
 * 
 * @param Container Array/String a concatenar
 */
void concatenar_sa(Stack,Container,Container);

/**
 * \brief Constrói um array com o tamanho do número dado
 *
 * @param Stack
 * 
 * @param Container O numero de elementos do array a criar
 */
void range(Stack,Container);

/**
 * \brief Devolve o tamanho de uma string ou array
 * 
 * @param Stack
 * 
 * @param Container Array/String a usar
 */
void length(Stack,Container);

/**
 * \brief Devolve o valor do array com o indice indicado pelo o utilizador
 *
 * @param Stack
 * 
 * @param Container Array a verificar
 * 
 * @param Container Indice para o array dado 
 */
void indice(Stack,Container,Container);

/**
 * \brief Devolve os primeiros elementos/caracteres de um array ou String dependendo do segundo valor
 *
 * @param Stack
 * 
 * @param Container Array/String a usar
 * 
 * @param Container Numero de elementos a ir buscar
 */
void buscarXINICIO(Stack,Container,Container);

/**
 * \brief Função auxiliar para buscarXINICIO para funcionar com Strings
 *
 * @param Container String a usar
 * 
 * @param Container Numero de elementos a ir buscar
 * 
 * \returns Substring obtido  
 */
char* buscarXINICIO_string(Container,Container);

/**
 * \brief Devolve os ultimos elementos/caracteres de um array ou String dependendo do segundo valor
 *
 * @param Stack
 * 
 * @param Container Array/String a usar
 * 
 * @param Container Numero de elementos a ir buscar
 */
void buscarXFIM(Stack,Container,Container);

/**
 * \brief Função auxiliar para o buscarXFIM funcionar com Strings
 *
 * @param Container String a usar
 * 
 * @param Container Numero de elementos a ir buscar
 * 
 * \returns Substring obtida 
 */
char* buscarXFIM_string(Container,Container);

/**
 * \brief Remove o primeiro elemento de um array ou de uma String
 *
 * @param Stack
 * 
 * @param Container Array/String a usar
 */
void removerINICIO(Stack,Container);

/**
 * \brief Remove o primeiro elemento de um array ou de uma String
 *
 * @param Container String a usar
 *
 * @param Container Char a devolver
 * 
 * \returns String alterada
 */
char* removerINICIO_string(char*,Container*);

/**
 * \brief Remove o ultimo elemento de um array ou de uma String
 *
 * @param Stack
 * 
 * @param Container Array/String a usar
 */
void removerFIM(Stack,Container);

/**
 * \brief Função auxiliar para o removerFIM funcionar com Strings
 * 
 * @param Stack
 * 
 * @param Container String a usar
 * 
 * \returns String alterada 
 */
char* removerFIM_string(Stack,char*);

/**
 * \brief Devolve o valor do indice da primeira ocurrencia de uma substring numa dada string
 *
 * @param Stack
 * 
 * @param Container String a verificar
 * 
 * @param Container Subtring a procurar
 */
void substring(Stack,Container,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocorrencias de uma determinada substring
 *
 * @param Stack
 * 
 * @param Container String a separar
 * 
 * @param Container Subtring a usar como separadora
 */
void separar_sub(Stack,Container,Container);

/**
 * \brief Define qual das Separações por espaço devia ser feita
 *
 * @param Stack
 * 
 * @param Container String a separar
 * 
 * @param Container Carater ou string a usar como separadora  
 */
void separar_which(Stack,Container,Container);

void separar_string(Stack,Container,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de whitespace
 *
 * @param Stack
 * 
 * @param Container String a separar 
 */
void separar_space(Stack,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de newlines
 *
 * @param Stack
 * 
 * @param Container String a separar
 */
void separar_lines(Stack,Container);

/**
 * \brief Função auxiliar para concatenar um número com um array
 *
 * @param Container Número a concatenar
 * 
 * @param Container Array a concatenar 
 *
 * @returns Container
 */
Container prepend(Container,Container);

/**
 * \brief Função auxiliar para concatenar um array com um número
 *
 * @param Container Array a concatenar
 * 
 * @param Container Numero a concatenar 
 *
 * @returns Container
 */
Container append(Container,Container);

// -------------------- GUIÃO 5 --------------------

void aplicarbloco(Stack,Container,Container,OperatorFunction*,Container*);

/**
 * \brief Função que aplica uma ação a cada elemento de um array/string
 *
 * @param Stack
 * @param Container
 * @param Container
 * @param OperatorFunction
 * @param Container
 */
void map(Stack,Container,Container,OperatorFunction*,Container*);

void fold(Stack,Container,Container,OperatorFunction*,Container*);

void filter(Stack,Container,Container,OperatorFunction*,Container*);

/**
 * \brief Função que insere elementos num array enquanto a condição a ser verificada for verdadeira
 *
 * @param Stack
 * @param Container
 * @param Container
 * @param OperatorFunction
 * @param Container
 */
void while_bloco(Stack,Container,Container,OperatorFunction*,Container*);

// void fold(Stack,char*);

#endif