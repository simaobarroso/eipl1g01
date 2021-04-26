#ifndef TYPES_H
#define TYPES_H

/**
 * \brief Todos os tipos que vão ser usados na Stack
 */
typedef enum Label { Long, Char, Double, String, Array, Block } Label;

// para escrever pointer basta fazer *STRING(s) ou *STACK(s)
#define STRING(t) t->s
#define STACK(t) t->a

typedef union {
    char* s;
    struct Stack* a;
} *Foldable;

#define LONG(n) n.l
#define DOUBLE(n) n.d
#define CHAR(n) n.c

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
 * \brief Controla os elementos da stack
 */
typedef struct Stack {
    Container* arr;  // stack itself
    int sizeofstack; // número de elementos da stack
    int alloc;       // número alocado
} *Stack;

int isFoldable(Container);

int isNum(Label);

Label numReturn(Label,Label);

Label foldType(Foldable);

#endif /* TYPES_H */