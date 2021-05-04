/**
 * \brief Ficheiro com os tipos e funções do parser
 */
#ifndef PARSER_H
#define PARSER_H

#include "../stack.h"
#include "../operations/operations.h"

/**
 * \brief Número de argumentos em cada função
 */
typedef enum { /**Enum com tipo Arguments **/
    args_s, args_1, args_2, args_3 } Arguments;

/**
 * \brief Tipo de função com 3 Container
 */
typedef void (*Args3Operation)(Stack,Container,Container,Container);

/**
 * \brief Tipo de função com 2 Container
 */
typedef void (*Args2Operation)(Stack,Container,Container);

/**
 * \brief Tipo de função com 1 Container
 */
typedef void (*Args1Operation)(Stack,Container);

/**
 * \brief Tipo de função sem Container
 */
typedef void (*ArgsStackOperation)(Stack);

/* COMING SOON TO YOUR HOME CINEMA:

typedef void (*StackOperation)(Stack);

typedef void (*NormalOperation)(Stack,Container*);

typedef void (*BlockOperation)(Stack,Container*,OperatorFunction*);

*/

/**
 * \brief Tipo de cada elemento do array que gere funções
 */
typedef struct { /**Struct com tipo OperatorFunction **/
    Arguments arg;
    union {
        ArgsStackOperation args_s;
        Args1Operation args_1;
        Args2Operation args_2;
        Args3Operation args_3;
    } f;
} OperatorFunction;

/**
 * \brief Os vários operadores matemáticos
 */
enum Operations { /**Enum com tipo Operations **/
    // GUIÃO 1
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
    // GUIÃO 2
    NewLine = 'l',
    ToInt = 'i',
    ToChar = 'c',
    ToDouble = 'f',
    ToString = 's',
    Troca3 = '@',
    Inverte2 = '\\',
    Duplica = '_',
    CopiaN = '$',
    Pop = ';',
    // GUIÃO 3
    FromEitherE = '&'+256,
    FromEitherOu = '|'+256,
    Menor = '<',
    Maior = '>',
    FromEitherMenor = '<'+256,    // como não é usado em blocos, índice do either
    FromEitherMaior = '>'+256,    // idém^^
    Igual = '=',
    Nao = '!',
    Ifthenelse = '?',
    MudaVariavel = ':',
    // GUIÃO 4
    Range = ',',
    Length = ','+128,
    ReadInput = 't',
    Concat = '+'+128,
    ConcatTimes = '*'+128,
    Separa = '/'+128,
    SubstringIndex = '#'+128,
    ColocaStackM = ')'+128,
    ColocaStackm = '('+128,
    FromArrToStack = '~'+128,
    ElemInit = '<'+128,
    ElemEnd = '>'+128,
    ValIndex = '='+128,
    // GUIÃO 5
    ExecBloco = '~'+256,
    Map = '%'+256,
    Fold = '*'+256,
    Filter = ','+256,
    Sort = '$'+256,
    While = 'w'+256
};

/**
 * \brief Definição das variáveis
 */
enum Variaveis {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

/**
 * \brief Determina se o operador é para ser feito como Num, Foldable ou Lambda, dependendo do número de parâmetros de cada função
 *
 * @param Stack
 *
 * @returns int
 */
int hashkey(Stack,char**,OperatorFunction*);

/**
 * \brief Inicializa todas as variáveis de A-Z
 *
 * @returns Container
 */
Container* variables(void);

/**
 * \brief É o cérebro de toda a operação que organiza e distribui os operadores para as respetivas funções
 *
 * @returns OperatorFunction
 */
OperatorFunction* hash(void);

/**
 * \brief Mesma função definida em cima
 *
 * É colocada aqui por preferência, de modo a tornar o código mais legível
 *
 * @param Stack 
 * @param String (Char*)
 */
 void parser(Stack,char*,OperatorFunction*,Container*);

/**
 * \brief Controla que tipo de operador começado com 'e' vai ser usado
 *
 * @param Stack
 * @param char
 * @param int
 */
char* either(Stack,char*);

/**
 * \brief Dá parse a números 
 *
 * @param String (Char*)
 * @param Stack
 * @param Container
 * @param Int
 *
 * @returns char*
 */
char* number_parse(Stack,char*);

/**
 * \brief Dá parse a char
 *
 * @param Stack
 * @param String
 *
 * @returns char*
 */
char* char_parse(Stack,char*);

/**
 * \brief Dá parse a char
 *
 * @param Stack
 * @param String
 * @param Container
 *
 * @returns char*
 */
char* var_control(Stack,char*,Container*);

/**
 * \brief Inicia o parse de qualquer estrutura
 *
 * @param Stack
 * @param String
 * @param OperatorFuncion
 * @param Container
 *
 * @returns char*
 */
char* structure_parse(Stack,char*,OperatorFunction*,Container*);

/**
 * \brief Dá parse a arrays
 *
 * @param Stack
 * @param String
 * @param OperatorFuncion
 * @param Container
 *
 * @returns char*
 */
char* array_parse(Stack,char*,OperatorFunction*,Container*);

/**
 * \brief Dá parse a blocos
 *
 * @param Stack
 * @param String
 *
 * @returns char*
 */
char* block_parse(Stack,char*);

/**
 * \brief Dá parse a strings
 *
 * @param Stack
 * @param String
 *
 * @returns char*
 */
char* string_parse(Stack stack, char* line);

/**
 * \brief Dá parse a funções
 *
 * @param Stack
 * @param String
 *
 * @returns char*
 */
char* parse_hash(Stack,char*,OperatorFunction*);

#endif /* PARSER_H */