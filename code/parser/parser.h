#ifndef PARSER_H
#define PARSER_H

#include "../stack.h"
#include "../operations/operations.h"

typedef enum { args_s, args_1, args_2, args_3 } Arguments;

typedef void (*Args3Operation)(Container*,Container*,Container*,Stack);
typedef void (*Args2Operation)(Container*,Container*,Stack);
typedef void (*Args1Operation)(Container*,Stack);
typedef void (*ArgsStackOperation)(Stack);

#define ARGUMENTS(label) f.label

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
    ExecBloco = '~'+128,
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
    FromEitherMenor = '<'+128,    // como não é usado em blocos, índice do either
    Maior = '>',
    Elemend = '>'+128,
    FromEitherMaior = '>'+128,    // idém^^
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

/*
typedef void (*ParseString)(Stack,char*);

typedef void (*ParseToOperation)(Stack,char*,OperatorFunction*);

typedef enum { None, Normal, ToOperate, Variable, Error } ParseFunction;

typedef struct {
    ParseFunction f;
    union {
        Container var;
        ParseFunction func;
    } p;
} Parser;

enum Parsing {
    Either = 'e',
    MakeArray = '[',
    MakeBlock = '{',
    MakeString = '"',
    MakeChar = '\'',
    Negativo = '-',             // predefinição do parser
    Space = ' ',                // dá "identation error"
    Tab = '\t',                 // idem^^
    Enter = '\n'                // idem^^
};
*/

/**
 * \brief Definição das variáveis
 */
enum Variaveis {A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z};

/**
 * \brief Determina se o operador é para ser feito como Num, Foldable ou Lambda
 *
 * @param Stack
 *
 * @returns int
 */
int hashkey(Stack,char*);

Container* variables(void);

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
 * \brief Realiza as operações a serem executadas
 *
 * @param String
 * @param Stack
 * @param Container
 * @param Hashmap
 * @param Int
 *
 */
void operation(char*,Stack, Container*, int*, int*);

/**
 * \brief Controla que tipo de operador começado com 'e' vai ser usado
 *
 * @param Stack
 * @param char
 * @param int
 */
void either(Stack,char*);

/**
 * \brief Dá parse a números 
 *
 * @param String (Char*)
 * @param Stack
 * @param Container
 * @param Int
 *
 * @returns Container
 *
 */
void number_parse(Stack,char*);

void char_parse(Stack,char*);

void var_control(Stack,char*,Container*);

void structure_parse(Stack,char*,OperatorFunction*,Container*);

void parse_hash(Stack,char*,OperatorFunction*);

#endif /* PARSER_H */