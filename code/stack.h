/**
 * @file Ficheiro com as várias invocações às funções da Stack
 */
/* expression.h */
typedef enum { // ir acrescentando nos próximos guiões
    Long,
    Double,
    Char,
    String,
    NotAType
} Label;

typedef struct { // idém ^^
    Label label;
    union {
        long l;
        double f;
        char c;
        char* s;
    } content;
} Container;

typedef struct {
    Container* arr;  // stack itself
    int sizeofstack; // tamanho da stack
    int alloc;       // número alocado
} Stack;

void initialize(Stack*);
void initializeContainer(Container*,Label);
void changecurrent(Stack*, int);
void push(Container, Stack*);
Container pop(Stack*);
void printstack(Stack*);