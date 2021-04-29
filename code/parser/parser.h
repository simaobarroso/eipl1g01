#ifndef PARSER_H
#define PARSER_H

#include "../stack.h"
#include "../operations/operations.h"

/*
 * \brief 
 */
typedef enum { args_s, args_1, args_2, args_3 } Arguments;

/*
 * \brief Tipo de função com 3 Container
 */
typedef void (*Args3Operation)(Stack,Container,Container,Container);
/*
 * \brief Tipo de função com 2 Container
 */
typedef void (*Args2Operation)(Stack,Container,Container);
/*
 * \brief Tipo de função com 1 Container
 */
typedef void (*Args1Operation)(Stack,Container);
/*
 * \brief Tipo de função sem Container
 */
typedef void (*ArgsStackOperation)(Stack);

/*
 * \brief Tipo de cada elemento do array que gere funções
 */
typedef struct {
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
enum Operations {
    NewLine = 'l',
    ReadInput = 't',
    Subtrai = '-',
    Soma = '+',
    Concat = '+'+128,
    Multiplica = '*',
    ConcatTimes = '*'+128,
    fold = '*'+128,
    Divide = '/',
    Separa = '/'+128,
    Modulo = '%',
    Map = '%'+256,
    Potencia = '#',
    SubsIndex = '#'+128,
    Bitwiseand = '&',
    FromEitherE = '&'+128,
    Bitwiseor = '|',
    FromEitherOu = '|'+128,
    Bitwisexor = '^',
    Incrementa = ')',
    ColocaStackM = ')'+128,
    Decrementa = '(',
    ColocaStackm = '('+128,
    Bitwisenot = '~',
    Stackarr = '~'+128,
    ExecBloco = '~'+256,
    ToChar = 'c',
    ToInt = 'i',
    ToString = 's',
    ToDouble = 'f',
    Troca3 = '@',
    Inverte2 = '\\',
    Duplica = '_',
    CopiaN = '$',
    Ordena = '$'+128,
    Pop = ';',
    Menor = '<',
    ElemInit = '<'+128,
    FromEitherMenor = '<'+256,    // como não é usado em blocos, índice do either
    Maior = '>',
    Elemend = '>'+128,
    FromEitherMaior = '>'+256,    // idém^^
    Igual = '=',
    ValIndex = '='+128,
    Nao = '!',
    MudaVariavel = ':',
    Ifthenelse = '?',
    Range = ',',
    Length = ','+128,
    Filter = ','+256,
    While = 'w'
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
 * \brief Dá parse a todo o tipo de estruturas
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
 * \brief Dá parse a funções
 *
 * @param Stack
 * @param String
 *
 * @returns char*
 */
char* parse_hash(Stack,char*,OperatorFunction*);

#endif /* PARSER_H */