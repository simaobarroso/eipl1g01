#include "operations.h"
#include <assert.h>

// primeiro
// segundo
/**
 * \brief Facilitador de escrita de operações lógicas que retornam "bool"
 */
#define LOGIC_OPERATION(func,op) 								\
	void func(Stack stack, Container x, Container y) {			\
		Container res = { .label = Long }; 						\
		res.LONG = (toDouble(x).DOUBLE op toDouble(y).DOUBLE);	\
		push(res,stack); 										\
	}

LOGIC_OPERATION(igual,==)
LOGIC_OPERATION(menor,<)
LOGIC_OPERATION(maior,>)

void nao(Stack s,Container x){
	toInt(x);
	x.LONG = ~x.LONG;
	push(x,s);
}

// x primeiro
// y segundo
void elogic(Stack stack, Container x, Container y) {
	Container res = { .label = Long, .LONG = 0 }; 																		
	if (toDouble(x).DOUBLE) res = y;
	push(res,stack);
}

void oulogic(Stack stack, Container x, Container y) {
	Container res;
	Label x_l = x.label;
	Label y_l = y.label;
	res = (toDouble(x).DOUBLE && (x.DOUBLE || toDouble(y).DOUBLE) && x.DOUBLE > y.DOUBLE)
		? to_num_type(x_l,&x)
		: to_num_type(y_l,&y);
	push(res,stack); 																		
}

// x segundo
// y primeiro
/**
 * \brief Facilitador de escrita de operações lógicas que retornam o maior/menor dos números inseridos
 */
#define EITHER_COMPARE_OPERATION(func,op) 									\
	void func(Stack stack, Container x, Container y) { 						\
		Container res; 														\
		Label x_l = x.label; 												\
		Label y_l = y.label; 												\
		res = (toDouble(x).DOUBLE op toDouble(y).DOUBLE) 					\
			? to_num_type(x_l,&x) 											\
			: to_num_type(y_l,&y); 											\
		push(res,stack); 													\
	}

EITHER_COMPARE_OPERATION(compmaior,>)
EITHER_COMPARE_OPERATION(compmenor,<)

void ifthenelse(Stack stack, Container z, Container y, Container x) {
	Container res;
	res = toInt(x).LONG ? y : z;
	push(res,stack);
}