/**
 * \brief Ficheiro com os tipos e funções do parser
 */
#ifndef _PARSER
#define _PARSER

#include "stack.h"
#include "control_types.h"

/**Enum com tipo Arguments **/
typedef enum { 
    /**Função com apenas uma stack **/    
    args_s = 0,
    /**Função com um container **/
    args_1,
    /**Função com dois containers **/
    args_2, 
    /**Função com três containers **/
    args_3, 
    /**Função para blocos **/
    args_b 
} Arguments;

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

/**Struct com tipo OperatorFunction */
typedef struct OperatorFunction { 
    /**Tipo de função*/
    Arguments arg;
    /**Union que distribui funções*/
    union {
        /**Função de stack*/
        ArgsStackOperation args_s;
        /**Função com um container*/
        Args1Operation args_1;
        /**Função com dois containers*/
        Args2Operation args_2;
        /**Função com três containers*/
        Args3Operation args_3;
        /**Função para blocos*/
        BlockOperation args_b;
    } f;
} OperatorFunction;

/**Enum com tipo Operations **/
typedef enum {
    // GUIÃO 1
    /** Soma */
    Soma = '+',
    /** Subtrai */
    Subtrai = '-',
    /** Multiplica */
    Multiplica = '*',
    /** Divide */
    Divide = '/',
    /** Modulo */
    Modulo = '%',
    /** Potencia */
    Potencia = '#',
    /** Bitwiseand */
    Bitwiseand = '&',
    /** Bitwiseor */
    Bitwiseor = '|',
    /** Bitwisexor */
    Bitwisexor = '^',
    /** Incrementa */
    Incrementa = ')',
    /** Decrementa */
    Decrementa = '(',
    /** Bitwisenot */
    Bitwisenot = '~',
    // GUIÃO 2
    /** NewLine */
    NewLine = 'l',
    /** ToInt */
    ToInt = 'i',
    /** ToChar */
    ToChar = 'c',
    /** ToDouble */
    ToDouble = 'f',
    /** ToString */
    ToString = 's',
    /** Troca3 */
    Troca3 = '@',
    /** Inverte2 */
    Inverte2 = '\\',
    /** Duplica */
    Duplica = '_',
    /** CopiaN */
    CopiaN = '$',
    /** Pop */
    Pop = ';',
    // GUIÃO 3
    /* FromEitherE */
    FromEitherE = '&'+256,
    /** FromEitherOu */
    FromEitherOu = '|'+256,
    /** FromEitherMenor */
    FromEitherMenor = '<'+256,    // como não é usado em blocos, índice do either
    /** FromEitherMaior */
    FromEitherMaior = '>'+256,    // idém^^
    /** Menor */
    Menor = '<',
    /** Maior */
    Maior = '>',
    /** Igual */
    Igual = '=',    // isto vai ser um caso especial
    /** Nao */
    Nao = '!',
    /** Nao */
    Ifthenelse = '?',
    /** MudaVariavel */
    MudaVariavel = ':',
    // GUIÃO 4
    /** Range */
    Range = ',',
    /** ReadInput */
    ReadInput = 't',
    /** Print */
    Print = 'p',
    /** Length */
    Length = ','+128,
    /** Concat */
    Concat = '+'+128,
    /** ConcatenarVezes */
    ConcatenarVezes = '*'+128,
    /** Separa */
    Separa = '/'+128,
    /** SubstringIndex */
    SubstringIndex = '#'+128,
    /** RemoveInicio */
    RemoveInicio = '('+128,
    /** RemoveFim */
    RemoveFim = ')'+128,
    /** PopStack */
    PopStack = '~'+128,
    /** ElemInit */
    ElemInit = '<'+128,
    /** ElemEnd */
    ElemEnd = '>'+128,
    /** ValIndex */
    ValIndex = '='+128,
    // GUIÃO 5
    /** ExecBloco */
    ExecBloco = '~'+256,
    /** Map */
    Map = '%'+256,
    /** Fold */
    Fold = '*'+256,
    /** Filter */
    Filter = ','+256,
    /** SortOn */
    SortOn = '$'+256,
    /** While */
    While = 'w'+256
} Operations;

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
 * \brief Inicializa os índices da hashtable correspondentes a operações de números
 *
 * @param OperatorFunction
 */
void hashtable_num_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações de input, output e pop
 *
 * @param OperatorFunction
 */
void hashtable_io_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações que alteram o topo da stack
 *
 * @param OperatorFunction
 */
void hashtable_type_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações da stack
 * 
 * @param OperatorFunction
 */
void hashtable_stack_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações lógicas
 *
 * @param OperatorFunction
 */
void hashtable_logic_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações de arrays e strings
 *
 * @param OperatorFunction
 */
void hashtable_foldable_func(OperatorFunction*);

/**
 * \brief Inicializa os índices da hashtable correspondentes a operações de blocos
 *
 * @param OperatorFunction
 */
void hashtable_block_func(OperatorFunction*);

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