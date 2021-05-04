/**
 * \brief Todos os tipos que vão ser usados na Stack
 */
#ifndef TYPES_H
#define TYPES_H

/**
 * \brief Controla o tipo de cada container
 */
typedef enum Label { Long, Char, Double, String, String_A, Array, Lambda } Label;

/**
 * \brief Controla os elementos da stack
 */
typedef struct {
    struct Container* arr;  // stack itself
    int sizeofstack; // número de elementos da stack
    int alloc;       // número alocado
} *Stack, Stack_plain;

/**
 * \brief Erro de identação: deve ser mandado quando se inserem espaços/tabs/newline a mais
 */
#define ERROR_0 { fputs("Error 0: wrong identation\n", stderr); exit(1); }
/**
 * \brief Erro de tipos: deve ser mandado quando uma conversão de tipos corre mal, p. ex. Array para Double
 */
#define ERROR_1 { fputs("Error 1: wrong type\n", stderr); exit(1); }

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
 * \brief Por questões de familiariedade, pretende simular a classe Foldable como em Haskell
 */
typedef union {
    char* s;
    Stack a;
} Foldable;

/**
 * \brief Por questões de familiariedade, pretende simular a classe Num como em Haskell
 */
typedef union {
    long l;
    double d;
    char c;
} Num;

/**
 * \brief Estrutura de um container, que controla o tipo dos elementos da stack
 */
typedef struct Container {
    Label label;
    union {
        Num n;
        Foldable f;
        char* b;
    } content;
} Container;

/**
 * \brief Define qual o tipo de Num que certa função pode devolver através da "importância" do tipo no enum
 *
 * @param Label
 * @param Label
 *
 * @returns Label
 */
// Label numReturn(Label, Label);
#define NUM_RETURN(x,y) x >= y ? x : y

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
 * \brief Verifica ser pertence à classe Foldable
 */
#define IS_FOLDABLE(c) c.label >= String && !Lambda

/**
 * \brief Verifica ser pertence à classe Num
 */
#define IS_NUM(c) c.label <= Char

/**
 * \brief Verifica se é String ou Array
 */
#define FOLD_TYPE(c) Array - (c.label == String) + (c.label == String_A)

/**
 * \brief Devolve o máximo entre dois números
 */
#define MAX(a,b) (a > b) ? a : b

/**
 * \brief Converte qualquer container numérico para a Label indicada
 *
 * @param Label
 * @param Container
 */
Container to_num_type(Label,Container*);

/**
 * \brief Por questões de melhor gestão de tipos, converte char* em Stack
 *
 * @param Container
 *
 * @returns Container
 */
Container string_to_array(Container x);

/**
 * \brief Função que dá parse a uma string para ser transformada em número, a ser usada juntamente com strtol e strtod
 *
 * @param String
 * @param String
 *
 * @returns Se o número é float ou não
 */
int number_string(char** line,char** num,char** end);

#endif /* TYPES_H */ 