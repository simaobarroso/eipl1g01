/**
 * @file Ficheiro com as várias possibilidades de operações a serem executadas
 */
#include "operations.h"

#include <assert.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

/**
 * \brief "Variavel global"
 */
#define CALC 100

/**
 * \brief Operacao com dois numeros, independentemente do tipo
 *
 * @param Funcao e operador
 * 
 * @returns Retorna uma funcao que faz operacao com dois numeros 
 */
#define MATH_OPERATION(func, op)                           \
    Container func(Container x, Container y) {             \
        Container res;                                     \
        res.label = Double;                                \
        if (x.label == Double && y.label == Double) {      \
            res.content.f = op(x.content.f, y.content.f);  \
        } else if (x.label == Double && y.label == Long) { \
            res.content.f = op(x.content.f, y.content.l);  \
        } else if (x.label == Long && y.label == Double) { \
            res.content.f = op(x.content.l, y.content.f);  \
        } else if (x.label == Long && y.label == Long) {   \
            res.content.l = op(x.content.l, y.content.l);  \
            res.label = Long;                              \
        } else                                             \
            assert(0 || "Error: wrong type");              \
        return res;                                        \
    }

/**
 * \brief Soma dois numeros 
 */
#define SOMA(x, y) x + y
/**
 * \brief Subtrai dois numeros 
 */
#define SUBTRAI(x, y) x - y
/**
 * \brief Multiplica dois numeros 
 */
#define MULTIPLICA(x, y) x* y
/**
 * \brief Divisao dois numeros 
 */
#define DIVIDE(x, y) x / y

/**
 * \brief Operacao com dois inteiros
 *
 * @param Funcao e operador
 * 
 * @returns Retorna uma funcao que faz operacao com dois inteiros
 */
#define INTEGER_OPERATION(func, op)                     \
    Container func(Container x, Container y) {          \
        Container res;                                  \
        res.label = Long;                               \
        if (x.label == Long && y.label == Long) {       \
            res.content.l = x.content.l op y.content.l; \
        } else                                          \
            assert(0 || "Error: wrong type");           \
        return res;                                     \
    }

MATH_OPERATION(soma, SOMA)
MATH_OPERATION(subtrai, SUBTRAI)
MATH_OPERATION(multiplica, MULTIPLICA)
MATH_OPERATION(divide, DIVIDE)
MATH_OPERATION(potencia, pow)
INTEGER_OPERATION(modulo, %)
INTEGER_OPERATION(bitwiseand, &)
INTEGER_OPERATION(bitwiseor, |)
INTEGER_OPERATION(bitwisexor, ^)

Container incrementa(Container x) {
    switch (x.label) {
        case Double:
            ++x.content.f;
            break;
        case Long:
            ++x.content.l;
            break;
        case Char:
            ++x.content.c;
            break;
        default:
            assert(0 || "Error: wrong type");
    }
    return x;
}

Container decrementa(Container x) {
    switch (x.label) {
        case Double:
            --x.content.f;
            break;
        case Long:
            --x.content.l;
            break;
        case Char:
            --x.content.c;
            break;
        default:
            assert(0 || "Error: wrong type");
    }
    return x;
}

Container bitwisenot(Container x) {
    if (x.label == Long) x.content.l = ~x.content.l;
    return x;
}

Container toChar(Container x) {
    if (x.label != Char) {
        if (x.label == Long) {
            x.content.c = x.content.l;
            x.label = Char;
        } else if (x.label == Double) {
            x.content.c = toInt(x).content.l;
        }
        else
            assert(0 || "Error: wrong type");
        x.label = Char;
    }
    return x;
}

Container toInt(Container x) {
    if (x.label != Long) {
        if (x.label != String)
            x.content.l = (x.label == Double) ? x.content.f : x.content.c;
        else
            assert(0 || "Error: wrong type");
        x.label = Long;
    }
    return x;
}

Container toDouble(Container x) {
    if (x.label != Double) {
        if (x.label != String)
            x.content.f = (x.label == Long) ? x.content.l : x.content.c;
        else
            assert(0 || "Error: wrong type");
        x.label = Double;
    }
    return x;
}

Container toString(Container x) { // tentar implementar apenas quando aparece o "l"
    char str[CALC];
    if (x.label != String) {
        if (x.label == Long) {
            sprintf(str,"%ld",x.content.l);
            x.content.s = strdup(str);
        } else if (x.label == Char) {
            sprintf(str,"%c",x.content.c);
            x.content.s = strdup(str);
        }
        else if (x.label == Double) {
            sprintf(str,"%g",x.content.f);
            x.content.s = strdup(str);
        } else 
            assert(0 || "Error: wrong type");
        x.label = String;
    }
    return x;
}

void troca3(Stack *stack) {
    if (stack->sizeofstack >= 3) {
        int n = 0;
        Container guarda[3];

        while (n < 3) {
            guarda[n] = pop(stack);
            n++;
        }
        push(guarda[1], stack);
        push(guarda[0], stack);
        push(guarda[2], stack);
    } else
        assert(0 || "Error: not enough elements");
}

void inverte2(Stack *stack) {
    int size = 2;
    Container guarda2[size--];

    while (size >= 0) {
        guarda2[size] = pop(stack);
        size--;
    }
    push(guarda2[1], stack);
    push(guarda2[0], stack);
}

void duplica(Stack *stack) {
    push(stack->arr[stack->sizeofstack - 1], stack);
}

void copiaN(Stack *stack) {
    Container copy = pop(stack); // vai buscar o indice a tirar da stack
    long n;
    if (copy.label == Long) {
        n = copy.content.l; // o indice tem que ser long
        push(stack->arr[stack->sizeofstack - n - 1], stack); // dá push do elemento no indice no topo
    }
    else
        assert(0 || "Error: wrong type");
}

// primeiro
// segundo
#define LOGIC_OPERATION(func,op) 								\
	Container func(Stack* stack){								\
		Container res; 											\
		Container y = toDouble(pop(stack)); 					\
		Container x = toDouble(pop(stack)); 					\
		res.content.l = (x.content.f op y.content.f);			\
		return res; 											\
	}

LOGIC_OPERATION(igual,==)
LOGIC_OPERATION(menor,<)
LOGIC_OPERATION(maior,>)

// Não
Container nao(Stack *stack){
	Container res = toInt(pop(stack));
	res.content.l = !res.content.l;
	return res;
}

// E  (com shortcut) 1 3 e& ... 3 

// x primeiro
// y segundo
Container elogic(Stack* stack) {															
	Container res; 																		
	Container y = pop(stack); 															
	Container x = pop(stack); 															
	switch (x.label) {																	
		case Long:																		
			switch (y.label) {															
				case Long:																
					res.label = Long;													
					res.content.l = (x.content.l && y.content.l) ? y.content.l : 0; break;
				case Double:															
					res.label = Double;													
					res.content.f = (x.content.l && y.content.f) ? y.content.f : 0; break;
				case Char:																
					res.label = Char;													
					res.content.c = (x.content.l && y.content.c) ? y.content.c : 0; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		case Double:																	
			switch (y.label) {															
				case Long:																
					res.label = Long;													
					res.content.l = (x.content.f && y.content.l) ? y.content.l : 0; break;
				case Double:															
					res.label = Double;													
					res.content.f = (x.content.f && y.content.f) ? y.content.f : 0; break;
				case Char:																
					res.label = Char;													
					res.content.c = (x.content.f && y.content.c) ? y.content.c : 0; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		case Char:																		
			switch (y.label) {															
				case Long:																
					res.label = Long;													
					res.content.l = (x.content.c && y.content.l) ? y.content.l : 0; break;
				case Double:															
					res.label = Double;													
					res.content.f = (x.content.c && y.content.f) ? y.content.f : 0; break;
				case Char:																
					res.label = Char;													
					res.content.c = (x.content.c && y.content.c) ? y.content.c : 0; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		default:																		
			assert (0 || "Error: Wrong type");											
	}																					
	return res; 																		
}

Container oulogic(Stack* stack) {															
	Container res; 																		
	Container y = pop(stack); 															
	Container x = pop(stack); 															
	switch (x.label) {																	
		case Long:																		
			switch (y.label) {															
				case Long:																
					res = (x.content.l || y.content.l) && x.content.l ? x : y; break;
				case Double:														
					res = (x.content.l || y.content.f) && x.content.l ? x : y; break;
				case Char:																
					res = (x.content.l || y.content.c) && x.content.l ? x : y; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		case Double:																	
			switch (y.label) {															
				case Long:																
					res = (x.content.f || y.content.l) && x.content.f ? x : y; break;
				case Double:															
					res = (x.content.f || y.content.f) && x.content.f ? x : y; break;
				case Char:																
					res = (x.content.f || y.content.c) && x.content.f ? x : y; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		case Char:																		
			switch (y.label) {															
				case Long:																
					res = (x.content.c || y.content.l) && x.content.c ? x : y; break;
				case Double:															
					res = (x.content.c || y.content.f) && x.content.c ? x : y; break;
				case Char:																
					res = (x.content.c || y.content.c) && x.content.c ? x : y; break;
				default:																
					assert (0 || "Error: Wrong type");									
			} break;																	
		default:																		
			assert (0 || "Error: Wrong type");											
	}																					
	return res; 																		
}

#define EITHER_COMPARE_OPERATION(func,op) 										\
	Container func(Stack* stack){												\
		Container res; 															\
		Container x = pop(stack); 												\
		Container y = pop(stack); 												\
		switch (x.label) {														\
			case Long:															\
				switch (y.label) {												\
					case Long:													\
						res = (x.content.l op y.content.l) ? x : y; break;		\
					case Double:												\
						res = (x.content.l op y.content.f) ? x : y; break;		\
					case Char:													\
						res = (x.content.l op y.content.c) ? x : y; break;		\
					default:													\
						assert (0 || "Error: Wrong type");						\
				} break;														\
			case Double:														\
				switch (y.label) {												\
					case Long:													\
						res = (x.content.f op y.content.l) ? x : y; break;		\
					case Double:												\
						res = (x.content.f op y.content.f) ? x : y; break;		\
					case Char:													\
						res = (x.content.f op y.content.c) ? x : y; break;		\
					default:													\
						assert (0 || "Error: Wrong type");						\
				} break;														\
			case Char:															\
				switch (y.label) {												\
					case Long:													\
						res = (x.content.c op y.content.l) ? x : y; break;		\
					case Double:												\
						res = (x.content.c op y.content.f) ? x : y; break;		\
			case Char:															\
						res = (x.content.c op y.content.c) ? x : y; break;		\
					default:													\
						assert (0 || "Error: Wrong type");						\
				} break;														\
			default:															\
				assert (0 || "Error: Wrong type");								\
		}																		\
		return res; 															\
	}

EITHER_COMPARE_OPERATION(compmaior,>)
EITHER_COMPARE_OPERATION(compmenor,<)

Container ifthenelse(Stack* stack) {												
	Container res; 															
	Container z = pop(stack); // ultimo
	Container y = pop(stack); // segundo
	Container x = pop(stack); // primeiro												
	switch (x.label) {														
		case Long:													
			res = x.content.l ? y : z; break;
		case Char:		
			res = x.content.c ? y : z; break;
		default:													
			assert (0 || "Error: Wrong type");
	}
	return res; 															
}