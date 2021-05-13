/**
 * \brief Controla os tipos principais
 */
#ifndef TYPES_H
#define TYPES_H

// ____TIPOS____

/** Controla o tipo de cada container*/
typedef enum Label { Long, Char, Double, String, Array, Lambda, No_Pop } Label;

/** Controla os elementos da stack */
typedef struct {
    /** stack itself */
    struct Container* arr;
    /** número de elementos da stack */
    int sizeofstack; 
    /** número alocado */
    int alloc; 
} *Stack, Stack_plain;

/** Por questões de familiariedade, pretende simular a classe Foldable como em Haskell */
typedef union {
    /** tipo string guião 4 */
    char* s;
    /** tipo array guião 4 */
    Stack a;
} Foldable;

/** Por questões de familiariedade, pretende simular a classe Num como em Haskell */
typedef union {
    /** numeros long */
    long l;
    /** numeros double */
    double d;
    /** caracteres */
    char c;
} Num;

/** Estrutura de um container, que controla o tipo dos elementos da stack */
typedef struct Container {
    /** label */
    Label label;
    union {
        /** numeros */
        Num n;
        /** foldable guião 4 */
        Foldable f;
        /** caracter */
        char* b;
    } content;
} Container;

// - FACILIDADES PARA TIPOS
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define STRING content.f.s
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define ARRAY content.f.a
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define LONG content.n.l
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define DOUBLE content.n.d
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define CHAR content.n.c
/**
 * \brief Introduz facilidades de controlo de tipos
 */
#define LAMBDA content.b
/**
 * \brief Devolve o tipo do topo da stack
 */
#define TOP_TYPE(x) x->arr[x->sizeofstack - 1].label

// - FACILIDADES PARA CONTAS
/**
 * \brief Verifica se um tipo é inteiro ou não
 */
#define IS_INTEGER(x,y) ((NUM_RETURN(x,y) < Double) ? Long : Double)

// - FACILIDADES DA HASHTABLE
/**
 * \brief Verifica ser pertence à classe Foldable
 */
#define IS_FOLDABLE(c) (c.label >= String && c.label < Lambda)
/**
 * \brief Verifica ser pertence à classe Num
 */
#define IS_NUM(c) (c.label <= Double)
/**
 * \brief Verifica se é String ou Array
 */
#define FOLD_TYPE(c) (Array - (c.label == String) + (c.label == String_A))
/**
 * \brief Caso especial da hashkey para lógica
 */
#define LOGIC(x,y) (BOTH_FOLDABLE(x,y) && (**line == '>' || **line == '<' || **line == '='))
/**
 * \brief Verifica se 2 coisas são foldable
 */
#define BOTH_FOLDABLE(x,y) ((x == String && y == String) || (x == Array && y == Array))

// - GENERALIDADES PARA NÚMEROS
/**
 * \brief Define qual o tipo de Num que certa função pode devolver através da "importância" do tipo no enum
 */
#define NUM_RETURN(x,y) (x >= y ? x : y)
/**
 * \brief Calcula o comprimento dum long
 */
#define LONG_LENGTH(s) strspn(s,"-1234567890")
/**
 * \brief Calcula o comprimento dum double
 */
#define DOUBLE_LENGTH(s) strspn(s,".-1234567890")
/**
 * \brief Devolve o máximo entre dois números
 */
#define MAX(a,b) ((a > b) ? a : b)
/**
 * \brief Condição geral deste programa para operações lógicas
 */
#define IF_CONDITION(x)                                     \
        ((IS_NUM(x) && toInt(x).LONG) ||                    \
        (x.label == Array && x.ARRAY->sizeofstack != 0) ||  \
        (x.label == String && *x.STRING)) ||                \
        (x.label == Lambda && *x.LAMBDA)

// ____ERROS____

/**
 * \brief Erro de identação: deve ser mandado quando se inserem espaços/tabs/newline a mais
 */
#define ERROR_0 { fputs("Error 0: wrong identation\n", stderr); exit(1); }
/**
 * \brief Erro de tipos: deve ser mandado quando uma conversão de tipos corre mal, p. ex. Array para Double
 */
#define ERROR_1 { fputs("Error 1: wrong type\n", stderr); exit(1); }
/**
 * \brief Erro de pop: acontece quando não for possível fazer pop
 */
#define ERROR_2 { fputs("Error 2: couldn't pop\n", stderr); exit(1); }
/**
 * \brief Erro de modificação de tipos: acontece quando o enum dos tipos está completamente errado
 */
#define ERROR_3 { fputs("Error 3: this should have been a SIGSEGV\n", stderr); exit(1); }

// ____CONVERSÕES____

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
 * @param Container
 *
 * @returns O valor em Int
 */
Container toInt(Container);
/**
 * \brief Converte para Double
 *
 * @param Container
 *
 * @returns O valor em Double
 */
Container toDouble(Container);
/**
 * \brief Converte para String
 *
 * @param Container
 *
 * @returns O valor em String
 */
Container toString(Container);

/**
 * \brief Converte qualquer container numérico para a Label indicada
 *
 * @param Label
 * @param Container
 */
Container to_num_type(Label,Container*);

/**
 * \brief Por questões de melhor gestão de tipos no guião 5, converte char* em Stack
 *
 * @param Container
 *
 * @returns Container
 */
Container string_to_array(Container x);

/**
 * \brief Reverte o efeito da string_to_array
 *
 * @param Container
 *
 * @returns Container
 */
Container array_to_string(Container x);

/**
 * \brief verifica se a conversão para String é necessária
 *
 * @param Container
 *
 * @returns int
 */
int all_char(Container);


/**
 * \brief verifica se todos os elementos de um array são strings
 *
 * @param Container
 *
 * @returns int
 */
int all_string(Stack);

/**
 * \brief verifica se todos os elementos de um array são arrays
 *
 * @param Container
 *
 * @returns int
 */
int all_array(Stack);

/**
 * \brief Função que dá parse a uma string para ser transformada em número, a ser usada juntamente com strtol e strtod
 *
 * @param String
 * @param String
 *
 * @returns Se o número é float ou não
 */
int number_string(char** line,char** num,char** end);

/**
 * \brief Implementação memory safe do strcat
 *
 * @param char*
 * @param char*
 *
 * @returns char*
 */
char* better_strcat(char* source, char* join);

/**
 * \brief Faz o mesmo que a strcmp, mas para arrays
 *
 * @param Stack
 * @param Stack
 *
 * @returns Int
 */
int arraycmp(Stack,Stack);

/**
 * \brief Duplica um array
 *
 * @param Stack
 *
 * @returns Stack
 **/ 
Stack arraydup(Stack s);

/**
 * \brief Copia um container
 *
 * @param Apontador para um container
 *
 * @returns Container
 **/ 
Container copy_container(Container const*);

/**
 * \brief Converte um container de char para string 
 *
 * @param Container 
 *
 * @returns Container
 **/ 
Container char_to_string(Container);

#endif
