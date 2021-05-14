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

/** Os vários operadores matemáticos */
enum Operations { /**Enum com tipo Operations **/
    // GUIÃO 1
    /** soma*/
    Soma = '+',
    /** subtração */
    Subtrai = '-',
    /** multiplicação */
    Multiplica = '*',
    /** divisão */
    Divide = '/',
    /** modulo */
    Modulo = '%',
    /** potencia */
    Potencia = '#',
    /** bitwiseand */
    Bitwiseand = '&',
    /** bitwiseor */
    Bitwiseor = '|',
    /** bitwisexor*/
    Bitwisexor = '^',
    /** ++ */
    Incrementa = ')',
    /** -- */
    Decrementa = '(',
    /** bitwisenot */
    Bitwisenot = '~',
    // GUIÃO 2
    /** \n */
    NewLine = 'l',
    /** para inteiro*/
    ToInt = 'i',
    /** para caracter */
    ToChar = 'c',
    /** para double*/
    ToDouble = 'f',
    /** para string*/
    ToString = 's',
    /** operação arroba*/
    Troca3 = '@',
    /** inverte 2 */
    Inverte2 = '\\',
    /** dpulica topo stack */
    Duplica = '_',
    /** copia n numeros */
    CopiaN = '$',
    /** pop stack */
    Pop = ';',
    // GUIÃO 3
    /** fromeitehre*/
    FromEitherE = '&'+256,
    /** fromeitherou */
    FromEitherOu = '|'+256,
    /** fromeithermenor*/
    FromEitherMenor = '<'+256,    // como não é usado em blocos, índice do either
    /** from either maior*/
    FromEitherMaior = '>'+256,    // idém^^
    /** menor */
    Menor = '<',
    /** maior */
    Maior = '>',
    /** igual */
    Igual = '=',    // isto vai ser um caso especial
    /** não */
    Nao = '!',
    /** ifthenelse */
    Ifthenelse = '?',
    /** muda variavel*/
    MudaVariavel = ':',
    // GUIÃO 4
    /** range */
    Range = ',',
    /** le input */
    ReadInput = 't',
    /** dá print */
    Print = 'p',
    /** tamanho*/
    Length = ','+128,
    /** concat */
    Concat = '+'+128,
    /** concatenarVezes */
    ConcatenarVezes = '*'+128,
    /** separa */
    Separa = '/'+128,
    /** index substring */
    SubstringIndex = '#'+128,
    /** remove inicio*/
    RemoveInicio = '('+128,
    /** remove fim*/
    RemoveFim = ')'+128,
    /** pop stack*/
    PopStack = '~'+128,
    /** elem init */
    ElemInit = '<'+128,
    /** elme end */
    ElemEnd = '>'+128,
    /** val index*/
    ValIndex = '='+128,
    // GUIÃO 5
    /** execute bloco*/
    ExecBloco = '~'+256,
    /** map */
    Map = '%'+256,
    /** fold */
    Fold = '*'+256,
    /** filter */
    Filter = ','+256,
    /** sortOn*/
    SortOn = '$'+256,
    /** while */
    While = 'w'+256
};

/** Definição das variáveis */
enum Variaveis {
    /** Variável */
    A,
    /** Variável */
    B,
    /** Variável */
    C,
    /** Variável */
    D,
    /** Variável */
    E,
    /** Variável */
    F,
    /** Variável */
    G,
    /** Variável */
    H,
    /** Variável */
    I,
    /** Variável */
    J,
    /** Variável */
    K,
    /** Variável */
    L,
    /** Variável */
    M,
    /** Variável */
    N,
    /** Variável */
    O,
    /** Variável */
    P,
    /** Variável */
    Q,
    /** Variável */
    R,
    /** Variável */
    S,
    /** Variável */
    T,
    /** Variável */
    U,
    /** Variável */
    V,
    /** Variável */
    W,
    /** Variável */
    X,
    /** Variável */
    Y,
    /** Variável */
    Z
    };

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