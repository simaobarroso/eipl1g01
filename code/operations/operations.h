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
 * \brief Coloca um array numa stack
 *
 * @param Stack 
 * @param Container (O array dado) 
 *
 */
void colocar_stack(Stack, Container);

/**
 * \brief Concatena strings ou arrays
 *
 * @param Container (Um array, uma String ou um enum)
 * @param Container (Um array, uma String ou um enum)
 *
 */
void concatenar_sa(Stack,Container,Container);



/**
 * \brief Constrói um array do 0 até ao número dado
 *
 * @param Stack
 * @param Container
 */
void range(Stack,Container);

/**
 * \brief Devolve o tamanho de uma string ou array
 *
 * @param Container (Um array, ou uma string)
 *
 */
void length(Stack,Container);

/**
 * \brief Devolve o valor do array com o indice indicado pelo o utilizador
 *
 *
 * @param Container (o array que vamos trabalhar com)
 * @param Container (indice para o array dado) 
 *
 */
void indice(Stack,Container,Container);

/**
 * \brief Devolve os primeiros elementos/caracteres de um array ou String dependendo do segundo valor
 *
 *
 * @param Container (o array ou string que vamos trabalhar com)
 * @param Container 
 * @param Stack
 *
 */
void buscarXINICIO(Stack,Container,Container);

/**
 * \brief Função auxiliar para buscarXINICIO para funcionar com Strings
 *
 *
 * @param Container (a string que vamos trabalhar com)
 * @param Container 
 * @param Stack
 *
 */
char* buscarXINICIO_string(Container,Container);

/**
 * \brief Devolve os ultimos elementos/caracteres de um array ou String dependendo do segundo valor
 *
 *
 * @param Container (o array ou string que vamos trabalhar com)
 * @param Container (indice para o array dado) 
 * @param Stack
 *
 */
void buscarXFIM(Container,Stack,Container);

/**
 * \brief Função auxiliar para o buscarXFIM funcionar com Strings
 *
 *
 * @param Container
 * @param Container 
 *
 */
char* buscarXFIM_string(Container,Container);

/**
 * \brief Remove o primeiro elemento de um array ou de uma String
 *
 *
 * @param Container (o array ou string que vamos trabalhar com)
 * @param Container (Stack final)
 *
 */
void removerINICIO(Stack,Container);

/**
 * \brief Remove o ultimo elemento de um array ou de uma String
 *
 *
 * @param Container (o array ou string que vamos trabalhar com)
 * @param Container (Stack final)
 *
 */
void removerFIM(Stack,Container);

/**
 * \brief Função auxiliar para o removerFIM funcionar com Strings
 *
 *
 * @param Container
 * @param Container 
 *
 */
char* removerFIM_string(Stack,char*);

/**
 * \brief Devolve o valor do indice da primeira ocurrencia de uma substring numa dada string
 *
 *
 * @param Stack
 * @param Container (string a verificar)
 * @param Container (subtring a procurar)  
 *
 */
void substring(Stack,Container,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocorrencias de uma determinada substring
 *
 *
 * @param Stack
 * @param Container (string a separar)
 * @param Container (subtring a usar como separadora)  
 *
 */
void separar_sub(Stack,Container,Container);

/**
 * \brief Define Qual das Separações por espaço devia ser feita
 *
 *
 * @param Container
 * @param Container 
 * @param Stack
 *
 */
void separar_which_space(Stack,Container,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de whitespace
 *
 *
 * @param Stack
 * @param Container (string a separar) 
 *
 */
void separar_space(Stack,Container);

/**
 * \brief Separa uma string em elementos de um array pelas as ocurrencias de newlines
 *
 *
 * @param Stack
 * @param Container (string a separar) 
 *
 */
void separar_lines(Stack,Container);

/**
 * \brief Função auxiliar para concatenar um número com um array
 *
 * @param Container (O número)
 * @param Container (O Array) 
 *
 * @returns Container
 */
Container prepend(Container,Container);

/**
 * \brief Função auxiliar para concatenar um array com um número
 *
 * @param Container (O Array)
 * @param Container (A String) 
 *
 * @returns Container
 */
Container append(Container,Container);

// GUIÃO 5

// void fold(Stack,char*);

// void map(Stack,char*);

#endif /* OPERATIONS_H */