/**
 * @file Ficheiro com as várias invocações às funções da Stack
 */
/* expression.h */
typedef enum {                                      // ir acrescentando nos próximos guiões
    Long,
    Double,
    Char
} Label;

typedef struct {                                    // idém ^^
    Label label;
    union {
        long l;
        double f;
        char c;
    } Content;
} Container;

typedef struct {
    Container *arr;                                 // stack itself
    int sizeofstack;                                // base pointer (numero elementos)
    int alloc;                                      // número alocado
} Stack;

void initialize(Stack *);
// int *peek(Stack *);
// void changesizeofnums(Stack *, int);
void changecurrent(Stack *, int);
void push(int, Stack *);
Container pop(Stack *);