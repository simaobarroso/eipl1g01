#include "control_types.h"
#include "parser.h"
#include "operations.h"
#include "stack.h"

Container* variables(void) {
    static Container vars[26] = {
        [A] = { .label = Long, .LONG = 10 },
        [B] = { .label = Long, .LONG = 11 },
        [C] = { .label = Long, .LONG = 12 },
        [D] = { .label = Long, .LONG = 13 },
        [E] = { .label = Long, .LONG = 14 },
        [F] = { .label = Long, .LONG = 15 },
        [N] = { .label = Char, .CHAR = '\n'},
        [S] = { .label = Char, .CHAR = ' '},
        [X] = { .label = Long, .LONG = 0 },
        [Y] = { .label = Long, .LONG = 1 },
        [Z] = { .label = Long, .LONG = 2 }
    };
    return vars;
}


/*
Este array tem 384 posições

As primeiras 128 posições correspondem a quando o operador é para ser executado com Long, Char ou Double, exceto nos casos de lógica
As segundas para quando é para ser executado com Array ou String
As terceiras para quando é para ser executado com um bloco
*/

/**
 * \brief Facilitador de inicialização da struct OperatorFunction
 */
#define HASH_CONTENT(index,label,func)  \
    hashtable[index].arg = label;       \
    hashtable[index].f.label = func;

OperatorFunction* hash(void) {
    static OperatorFunction hashtable[384];
    
    hashtable_num_func(hashtable);
    hashtable_io_func(hashtable);
    hashtable_type_func(hashtable);
    hashtable_stack_func(hashtable);
    hashtable_logic_func(hashtable);
    hashtable_foldable_func(hashtable);
    hashtable_block_func(hashtable);

    return hashtable;
}

void hashtable_num_func(OperatorFunction* hashtable) {
    HASH_CONTENT(Soma,args_2,soma)
    HASH_CONTENT(Subtrai,args_2,subtrai)
    HASH_CONTENT(Multiplica, args_2, multiplica)
    HASH_CONTENT(Divide, args_2, divide)
    HASH_CONTENT(Modulo, args_2, modulo)
    HASH_CONTENT(Potencia, args_2, potencia)
    HASH_CONTENT(Bitwiseand, args_2, bitwiseand)
    HASH_CONTENT(Bitwiseor, args_2, bitwiseor)
    HASH_CONTENT(Bitwisexor, args_2, bitwisexor)
    HASH_CONTENT(Bitwisenot, args_1, bitwisenot)
    HASH_CONTENT(Incrementa, args_1, incrementa)
    HASH_CONTENT(Decrementa, args_1, decrementa)
}

void hashtable_io_func(OperatorFunction* hashtable) {
    HASH_CONTENT(NewLine, args_s, newline)
    HASH_CONTENT(NewLine+128, args_s, newline)
    HASH_CONTENT(NewLine+256, args_s, newline)
    HASH_CONTENT(ReadInput, args_s, ler_input)
    HASH_CONTENT(ReadInput+128, args_s, ler_input)
    HASH_CONTENT(ReadInput+256, args_s, ler_input)
    HASH_CONTENT(Print, args_s, print_top)
    HASH_CONTENT(Print+128, args_s, print_top)
    HASH_CONTENT(Print+256, args_s, print_top)
}

void hashtable_type_func(OperatorFunction* hashtable) {
    HASH_CONTENT(ToInt, args_s, to_int_op)
    HASH_CONTENT(ToInt+128, args_s, to_int_op)
    HASH_CONTENT(ToChar, args_s, to_char_op)
    HASH_CONTENT(ToChar+128, args_s, to_char_op)
    HASH_CONTENT(ToDouble, args_s,to_double_op)
    HASH_CONTENT(ToDouble+128, args_s,to_double_op)
    HASH_CONTENT(ToString, args_s, to_string_op)
    HASH_CONTENT(ToString+128, args_s, to_string_op)
    HASH_CONTENT(Pop, args_s, void_pop)
    HASH_CONTENT(Pop+128, args_s, void_pop)
    HASH_CONTENT(Pop+256, args_s, void_pop)
}

void hashtable_stack_func(OperatorFunction* hashtable) {
    HASH_CONTENT(Troca3, args_s, troca3)
    HASH_CONTENT(Troca3+128, args_s, troca3)
    HASH_CONTENT(Troca3+256, args_s, troca3)
    HASH_CONTENT(Inverte2,args_s,inverte2)
    HASH_CONTENT(Inverte2+128,args_s,inverte2)
    HASH_CONTENT(Inverte2+256,args_s,inverte2)
    HASH_CONTENT(Duplica, args_s, duplica)
    HASH_CONTENT(Duplica+128, args_s, duplica)
    HASH_CONTENT(Duplica+256, args_s, duplica)
    HASH_CONTENT(CopiaN,args_s,copiaN)
    HASH_CONTENT(CopiaN+128,args_s,copiaN)
}

void hashtable_logic_func(OperatorFunction* hashtable) {
    HASH_CONTENT(FromEitherE,args_2,elogic)
    HASH_CONTENT(FromEitherOu,args_2,oulogic)
    HASH_CONTENT(FromEitherMaior,args_2,compmaior)
    HASH_CONTENT(FromEitherMenor,args_2,compmenor)
    HASH_CONTENT(Maior,args_2,maior)
    HASH_CONTENT(Menor,args_2,menor)
    HASH_CONTENT(Igual,args_2,igual)
    HASH_CONTENT(Nao,args_1,nao)
    HASH_CONTENT(Ifthenelse,args_3,ifthenelse)
    HASH_CONTENT(Ifthenelse+128,args_3,ifthenelse)
    HASH_CONTENT(Ifthenelse+256,args_3,ifthenelse)
}

void hashtable_foldable_func(OperatorFunction* hashtable) {
    HASH_CONTENT(Range,args_1,range)
    HASH_CONTENT(Length,args_1,length)
    HASH_CONTENT(ValIndex, args_2, indice)
    HASH_CONTENT(ElemInit,args_2,buscarXINICIO)
    HASH_CONTENT(ElemEnd,args_2,buscarXFIM)
    HASH_CONTENT(RemoveFim,args_1,removerFIM)
    HASH_CONTENT(RemoveInicio,args_1,removerINICIO)
    HASH_CONTENT(SubstringIndex,args_2,substring)
    HASH_CONTENT(Separa,args_2,separar_which)
    HASH_CONTENT(PopStack,args_1,colocar_stack)
    HASH_CONTENT(Concat,args_2,concatenar_sa)
    HASH_CONTENT(ConcatenarVezes,args_2,concatenarVezes)
}

void hashtable_block_func(OperatorFunction* hashtable) {
    HASH_CONTENT(ExecBloco,args_b,aplicarbloco)
    HASH_CONTENT(Map,args_b,map)
    HASH_CONTENT(Fold,args_b,fold)
    HASH_CONTENT(Filter,args_b,filter)
    HASH_CONTENT(SortOn,args_b,ordenar)
    HASH_CONTENT(While,args_b,while_bloco)
}