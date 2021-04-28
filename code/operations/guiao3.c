#include "operations.h"
#include <assert.h>

// primeiro
// segundo
#define LOGIC_OPERATION(func,op) 						\
	void func(Container *x, Container *y,Stack stack) {	\
		Container res; 									\
		toDouble(*y);						 			\
		toDouble(*x); 									\
		res.LONG = ((*x).DOUBLE op (*y).DOUBLE);		\
		push(res,stack); 								\
	}

LOGIC_OPERATION(igual,==)
LOGIC_OPERATION(menor,<)
LOGIC_OPERATION(maior,>)

void nao(Container* x){
	toInt(*x);
	(*x).LONG = !(*x).LONG;
}

// x primeiro
// y segundo
void elogic(Container* x, Container* y, Stack stack) {
	Container res = { .label = Long, .LONG = 0 }; 																		
	toDouble(*x);
	toDouble(*y);
	switch (x->label) {
		case Long: if ((*x).DOUBLE) res = toInt(*y); break;
    	case Double: if ((*x).DOUBLE) res = *y; break;
    	case Char: if ((*x).DOUBLE) res = toChar(*y); break;
		default: assert (0 || "Error: Wrong type");	
	} 																					
	push(res,stack);
}

Container oulogic(Stack stack) {															
	Container res = { .label = Long, .LONG = 0 };
	Container y = pop(stack);
	Container x = pop(stack);
	Label x_l = x.label;
	Label y_l = y.label;
	toDouble(y);
	toDouble(x);
	switch (x.label) {																	
		case Long: 
			res = (x.DOUBLE && (x.DOUBLE || y.DOUBLE) && x.DOUBLE > y.DOUBLE) ? to_num_type(x,x_l) : toInt(y); break;
		case Double: 
			res = (x.DOUBLE && (x.DOUBLE || y.DOUBLE) && x.DOUBLE > y.DOUBLE) ? x : y; break;
		case Char: 
			res = (x.DOUBLE && (x.DOUBLE || y.DOUBLE) && x.DOUBLE > y.DOUBLE) ? toChar(x) : toChar(y); ; break;										
		default:																		
			assert (0 || "Error: Wrong type");											
	}																					
	return res; 																		
}

// x segundo
// y primeiro
#define EITHER_COMPARE_OPERATION(func,op) 									\
	void func(Container* x,Container* y,Stack stack) {						\
		Container res; 														\
		switch (x->label) {													\
			case Long:														\
				switch (y->label) {											\
					case Long:												\
						res = ((*x).LONG op (*y).LONG) ? x : y; break;		\
					case Double:											\
						res = ((*x).LONG op (*y).DOUBLE) ? x : y; break;	\
					case Char:												\
						res = (x.LONG op y.CHAR) ? x : y; break;			\
					default:												\
						assert (0 || "Error: Wrong type");					\
				} break;													\
			case Double:													\
				switch (y.label) {											\
					case Long:												\
						res = (x.DOUBLE op y.LONG) ? x : y; break;			\
					case Double:											\
						res = (x.DOUBLE op y.DOUBLE) ? x : y; break;		\
					case Char:												\
						res = (x.DOUBLE op y.CHAR) ? x : y; break;			\
					default:												\
						assert (0 || "Error: Wrong type");					\
				} break;													\
			case Char:														\
				switch (y.label) {											\
					case Long:												\
						res = (x.CHAR op y.LONG) ? x : y; break;			\
					case Double:											\
						res = (x.CHAR op y.DOUBLE) ? x : y; break;			\
			case Char:														\
						res = (x.CHAR op y.CHAR) ? x : y; break;			\
					default:												\
						assert (0 || "Error: Wrong type");					\
				} break;													\
			default:														\
				assert (0 || "Error: Wrong type");							\
		}																	\
		push(res,stack);													\
	}

EITHER_COMPARE_OPERATION(compmaior,>)
EITHER_COMPARE_OPERATION(compmenor,<)

void ifthenelse(Container* z, Container* y, Container* x, Stack stack) {
	Container res;
	switch (x->label) {
		case Long:
			res = (*x).LONG ? *y : *z; break;
		case Char:
			res = (*x).CHAR ? *y : *z; break;
		default:
			assert (0 || "Error: Wrong type");
	}
	push(res,stack);
}