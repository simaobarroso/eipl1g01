#ifndef TYPES_H
#define TYPES_H

/**
 * \brief Todos os tipos que vão ser usados na Stack
 */
typedef enum Label { Long, Char, Double, String, Array, Lambda } Label;

// para escrever pointer basta fazer *STRING(s) ou *STACK(s)

/**
 * \brief Controla os elementos da stack
 */
typedef struct {
    struct Container* arr;  // stack itself
    int sizeofstack; // número de elementos da stack
    int alloc;       // número alocado
} *Stack,Stack_plain;

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

Label numReturn(Label, Label);
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
 *
 * @param Container
 *
 * @returns bool
 */
int isFoldable(Container);

/**
 * \brief Verifica ser pertence à classe Num
 *
 * @param Container
 *
 * @returns bool
 */
int isNum(Container);

/**
 * \brief Verifica se é String ou Array
 *
 * @param Container
 *
 * @returns Label
 */
Label foldType(Container);

/**
 * \brief Converte qualquer container numérico para a Label indicada
 *
 * @param Label
 * @param Container
 */
void to_num_type(Label,Container*);

#endif /* TYPES_H */