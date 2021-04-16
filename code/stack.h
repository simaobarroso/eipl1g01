/**
 * @file Ficheiro com as várias invocações às funções da Stack
 */
/* expression.h */

/**
 * \brief Todos os tipos que vão ser usados na Stack
 */
typedef enum { // ir acrescentando nos próximos guiões
    Long,
    Double,
    Char,
    String
} Label;

/**
 * \brief Estrutura de um container, que controla o tipo dos elementos da stack
 */
typedef struct { // idém ^^
    Label label;
    union {
        long l;
        double f;
        char c;
        char* s;
    } content;
} Container;

/**
 * \brief Controla os elementos da stack
 */
typedef struct {
    Container* arr;  // stack itself
    int sizeofstack; // número de elemntos da stack
    int alloc;       // número alocado
} Stack;

/**
 * \brief Inicializa a Stack
 *
 * @param Stack
 */
void initialize(Stack*);
/**
 * \brief Inicializa um conteiner com a label indicada
 *
 * @param Container e uma label
 */
void initializeContainer(Container*,Label);
/**
 * \brief Verifica se a stack a stack está vazia
 *
 * @param Stack
 *
 * @returns Se está vazia retorna 1, caso contrário retorna 0
 */
int isEmpty(Stack* list);
/**
 * \brief Verifica se uma stack está cheia
 *
 * @param Stack
 *
 * @returns Se está cheia retorna 1, caso contrário retorna 0
 */
int isFull(Stack* list);

/**
 * \brief Coloca um valor no último índicie do array (topo da stack)
 *
 * @param Stack e um Int
 */
void push(Container, Stack*);
/**
 * \brief Retira um valor no último índicie do array (topo da stack)
 *
 * @param Stack
 *
 * @returns Devolve o conteúdo desse índice
 */
Container pop(Stack*);
/**
 * \brief Imprime a stack para o stdout.
 *
 * @param Stack
 */
void printstack(Stack*);