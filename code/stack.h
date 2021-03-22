/**
 * @file Ficheiro com as várias invocações às funções da Stack
 */

/* expression.h */
typedef struct {
    int sizeofnums;                                 // base pointer (numero elementos)
    int alloc;                                      // número alocado
    int *nums;                                      // stack itself
} Stack;

void initialize(Stack *);
int *peek(Stack *);
void changesizeofnums(Stack *, int);
void changecurrent(Stack *, int);
void push(int,Stack *);
int pop(Stack *);
void freelast(Stack *);
void freeall(Stack *,char *);