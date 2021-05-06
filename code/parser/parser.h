/**
 * \brief Ficheiro com os tipos e funções do parser
 */
#ifndef _PARSER
#define _PARSER

#include "../stack/stack.h"
#include "../control_types.h"

/**
 * \brief Número de argumentos em cada função
 */
typedef enum { /**Enum com tipo Arguments **/
    args_s = 0, args_1, args_2, args_3, args_b } Arguments;

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

struct OperatorFunction;
/**
 * \brief Tipo de função para blocos
 */
typedef void (*BlockOperation)(Stack,Container,Container,struct OperatorFunction*,Container*);

/**
 * \brief Tipo de cada elemento do array que gere funções
 */
typedef struct OperatorFunction { /**Struct com tipo OperatorFunction **/
    Arguments arg;
    union {
        ArgsStackOperation args_s;
        Args1Operation args_1;
        Args2Operation args_2;
        Args3Operation args_3;
        BlockOperation args_b;
    } f;
} OperatorFunction;

/*
enum StackNumOperators {
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
    NewLine = 'l',      // precisa de existir em todos
    ToInt = 'i',        // precisa de existir em todos
    ToChar = 'c',       // precisa de existir em todos
    ToDouble = 'f',     // precisa de existir em todos
    ToString = 's',     // precisa de existir em todos
    Troca3 = '@',       // precisa de existir em todos
    Inverte2 = '\\',    // precisa de existir em todos
    Duplica = '_',      // precisa de existir em todos
    CopiaN = '$',       // precisa de existir em todos
    Pop = ';',          // precisa de existir em todos
    // GUIÃO 3
    Menor = '<',
    Maior = '>',
    Igual = '=',
    Nao = '!',
    Ifthenelse = '?',   // precisa de existir em todos
    MudaVariavel = ':',
    // GUIÃO 4
    ReadInput = 't'     // precisa de existir em todos
    Range = ','
};

enum FoldableOperators {
    // GUIÃO 4
    Length = ',',
    Concat = '+',
    ConcatTimes = '*',
    Separa = '/',
    SubstringIndex = '#',
    RemoveInicio = '(',
    RemoveFim = ')',
    PopStack = '~',
    ElemInit = '<',
    ElemEnd = '>',
    ValIndex = '='
};

enum BlockLogicOperators {
    // GUIÃO 3
    FromEitherE = '&',
    FromEitherOu = '|',
    FromEitherMenor = '<',
    FromEitherMaior = '>',
    // GUIÃO 5
    ExecBloco = '~',
    Map = '%',
    Fold = '*',
    Filter = ',',
    Sort = '$',
    While = 'w'
};
*/

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
    FromEitherMenor = '<'+256,    // como não é usado em blocos, índice do either
    FromEitherMaior = '>'+256,    // idém^^
    Menor = '<',
    Maior = '>',
    Igual = '=',    // isto vai ser um caso especial
    Nao = '!',
    Ifthenelse = '?',
    MudaVariavel = ':',
    // GUIÃO 4
    Range = ',',
    ReadInput = 't',
    Length = ','+128,
    Concat = '+'+128,
    ConcatenarVezes = '*'+128,
    Separa = '/'+128,
    SubstringIndex = '#'+128,
    RemoveInicio = '('+128,
    RemoveFim = ')'+128,
    PopStack = '~'+128,
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
char* parse_hash(Stack,char*,OperatorFunction*,Container*);

/**
 * \brief Distrubui os diversos pop pelas respetivas funções
 *
 * @param Stack
 * @param OperatorFunction
 * @param Container
 */
void num_args(Stack s, OperatorFunction* func);

#endif