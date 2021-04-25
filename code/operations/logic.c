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