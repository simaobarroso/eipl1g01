/* expression.h */
#include "operations.h"

typedef struct {
    int sizeofnums;                                 // base pointer
    int current;                                    // stack pointer
    int *nums;                                      // stack itself
} Stack;

extern void initialize(Stack *);
extern int *peek(Stack *);
extern void changesizeofnums(Stack *, int);
extern void changecurrent(Stack *, int);
extern void push(int,Stack *);
extern void freelast(Stack *);
extern void freeall(Stack *,char *);