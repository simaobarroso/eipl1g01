#include "operations.h"
#include <assert.h>

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
	Container res { .label = Long, .content.l = 0 }; 																		
	Container y = ToInt.pop(stack); 															
	Container x = ToInt.pop(stack);
	switch (x.label) {																	
	
	case Long: res = (x.content.f) ? toLong(y) : res; break;
    case Double: res = (x.content.f) ? toInt(y) : res; break;
    case Char: res = (x.content.f) ? toChar(y) : res; break;																				
	default:																
		assert (0 || "Error: Wrong type");	
	} 																					
	return res; 																		
}		
Container oulogic(Stack* stack) {															
	Container res{ .label = Long, .content.l = 0 }; 																		
	Container y = ToInt.pop(stack); 															
	Container x = ToInt.pop(stack); 															
	switch (x.label) {																	
		case Long: res = (x.content.f && (x.content.f || y.content.f) && x.content.f > y.content.f) ? toLong(x) : toLong(y);; break;
		case Double: res = (x.content.f && (x.content.f || y.content.f) && x.content.f > y.content.f) ? toInt(x) : toInt(y); break;
		case Char: res = (x.content.f && (x.content.f || y.content.f) && x.content.f > y.content.f) ? toChar(x) : toChar(y); ; break;										
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