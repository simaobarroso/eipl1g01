#include "../control_types.h"
#include "parser.h"
#include "../operations/operations.h"
#include "../stack/stack.h"

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

/**
 * \brief Facilitador de inicialização da struct OperatorFunction
 */
#define HASH_CONTENT(label,func) .arg = label, .f.label = func

/*
Este array tem 384 posições

As primeiras 128 posições correspondem a quando o operador é para ser executado com Long, Char ou Double
As segundas para quando é para ser executado com Array ou String
As terceiras para quando é para ser executado com um bloco

OperatorFunction** hash(void) {
    static OperatorFunction* hashtable[3] = {
        hash_start1(),          // inicializa os primeiros 128
        hash_start2(),          // inicializa os segundos 128
        hash_start3()           // inicializa os últimos 128
    };
    return *hashtable;
}

OperatorFunction* hash_start1(void) {
    static OperatorFunction hashtable[128] = {
        // GUIÃO 1
        [Soma] =            { HASH_CONTENT(args_2,soma) },
        [Subtrai] =         { HASH_CONTENT(args_2,subtrai) },
        [Multiplica] =      { HASH_CONTENT(args_2,multiplica) },
        [Divide] =          { HASH_CONTENT(args_2,divide) },
        [Modulo] =          { HASH_CONTENT(args_2,modulo) },
        [Potencia] =        { HASH_CONTENT(args_2,potencia) },
        [Bitwiseand] =      { HASH_CONTENT(args_2,bitwiseand) },
        [Bitwiseor] =       { HASH_CONTENT(args_2,bitwiseor) },
        [Bitwisexor] =      { HASH_CONTENT(args_2,bitwisexor) },
        [Incrementa] =      { HASH_CONTENT(args_1,incrementa) },
        [Decrementa] =      { HASH_CONTENT(args_1,decrementa) },
        [Bitwisenot] =      { HASH_CONTENT(args_1,bitwisenot) },
        // GUIÃO 2
        [NewLine] =         { HASH_CONTENT(args_s,newline) },
        [ToInt] =           { HASH_CONTENT(args_s,to_int_op) },
        [ToChar] =          { HASH_CONTENT(args_s,to_char_op) },
        [ToDouble] =        { HASH_CONTENT(args_s,to_double_op) },
        [ToString] =        { HASH_CONTENT(args_s,to_string_op) },
        [Troca3] =          { HASH_CONTENT(args_s,troca3) },
        [Inverte2] =        { HASH_CONTENT(args_s,inverte2) },
        [Duplica] =         { HASH_CONTENT(args_s,duplica) },
        [CopiaN] =          { HASH_CONTENT(args_s,copiaN) },
        [Pop] =             { HASH_CONTENT(args_s,void_pop) },
        // GUIÃO 3
        [Igual] =           { HASH_CONTENT(args_2,igual) },
        [Maior] =           { HASH_CONTENT(args_2,maior) },
        [Menor] =           { HASH_CONTENT(args_2,menor) },
        [Nao] =             { HASH_CONTENT(args_1,nao) },
        [Ifthenelse] =      { HASH_CONTENT(args_3,ifthenelse) },
        // GUIÃO 4
        [Range] =           { HASH_CONTENT(args_1,range) },
    };
}

OperatorFunction* hash_start2(void) {
    static OperatorFunction hashtable[128] = {
        // GUIÃO 2
        [NewLine] =         { HASH_CONTENT(args_s,newline) },
        [ToInt] =           { HASH_CONTENT(args_s,to_int_op) },
        [ToChar] =          { HASH_CONTENT(args_s,to_char_op) },
        [ToDouble] =        { HASH_CONTENT(args_s,to_double_op) },
        [ToString] =        { HASH_CONTENT(args_s,to_string_op) },
        [Troca3] =          { HASH_CONTENT(args_s,troca3) },
        [Inverte2] =        { HASH_CONTENT(args_s,inverte2) },
        [Duplica] =         { HASH_CONTENT(args_s,duplica) },
        [CopiaN] =          { HASH_CONTENT(args_s,copiaN) },
        [Pop] =             { HASH_CONTENT(args_s,void_pop) },
        // GUIÃO 3
        [Ifthenelse] =      { HASH_CONTENT(args_3,ifthenelse) },
    };
}

OperatorFunction* hash_start3(void) {
    static OperatorFunction hashtable[128] = {
        // GUIÃO 2
        [NewLine] =     { HASH_CONTENT(args_s,newline) },
        [Troca3] =          { HASH_CONTENT(args_s,troca3) },
        [Inverte2] =        { HASH_CONTENT(args_s,inverte2) },
        [Duplica] =         { HASH_CONTENT(args_s,duplica) },
        [CopiaN] =          { HASH_CONTENT(args_s,copiaN) },
        [Pop] =             { HASH_CONTENT(args_s,void_pop) },
        // GUIÃO 3
        [FromEitherE] =     { HASH_CONTENT(args_2,elogic) },
        [FromEitherOu] =    { HASH_CONTENT(args_2,oulogic) },
        [FromEitherMaior] = { HASH_CONTENT(args_2,compmaior) },
        [FromEitherMenor] = { HASH_CONTENT(args_2,compmenor) },
        [Ifthenelse] =      { HASH_CONTENT(args_3,ifthenelse) },
        // GUIÃO 4
        [ReadInput] =       { HASH_CONTENT(args_s,ler_input) },
    };
}
*/

OperatorFunction* hash(void) {
    static OperatorFunction hashtable[128*3] = {
        // GUIÃO 1
        [Soma] =            { HASH_CONTENT(args_2,soma) },
        [Subtrai] =         { HASH_CONTENT(args_2,subtrai) },
        [Multiplica] =      { HASH_CONTENT(args_2,multiplica) },
        [Divide] =          { HASH_CONTENT(args_2,divide) },
        [Modulo] =          { HASH_CONTENT(args_2,modulo) },
        [Potencia] =        { HASH_CONTENT(args_2,potencia) },
        [Bitwiseand] =      { HASH_CONTENT(args_2,bitwiseand) },
        [Bitwiseor] =       { HASH_CONTENT(args_2,bitwiseor) },
        [Bitwisexor] =      { HASH_CONTENT(args_2,bitwisexor) },
        [Incrementa] =      { HASH_CONTENT(args_1,incrementa) },
        [Decrementa] =      { HASH_CONTENT(args_1,decrementa) },
        [Bitwisenot] =      { HASH_CONTENT(args_1,bitwisenot) },
        // GUIÃO 2
        [NewLine] =         { HASH_CONTENT(args_s,newline) },
        [NewLine+128] =     { HASH_CONTENT(args_s,newline) },
        [NewLine+256] =     { HASH_CONTENT(args_s,newline) },
        [ToInt] =           { HASH_CONTENT(args_s,to_int_op) },
        [ToInt+128] =       { HASH_CONTENT(args_s,to_int_op) },
        [ToChar] =          { HASH_CONTENT(args_s,to_char_op) },
        [ToChar+128] =      { HASH_CONTENT(args_s,to_char_op) },
        [ToDouble] =        { HASH_CONTENT(args_s,to_double_op) },
        [ToDouble+128] =    { HASH_CONTENT(args_s,to_double_op) },
        [ToString] =        { HASH_CONTENT(args_s,to_string_op) },
        [ToString+128] =    { HASH_CONTENT(args_s,to_string_op) },
        [Troca3] =          { HASH_CONTENT(args_s,troca3) },
        [Troca3+128] =      { HASH_CONTENT(args_s,troca3) },
        [Troca3+256] =      { HASH_CONTENT(args_s,troca3) },
        [Inverte2] =        { HASH_CONTENT(args_s,inverte2) },
        [Inverte2+128] =    { HASH_CONTENT(args_s,inverte2) },
        [Inverte2+256] =    { HASH_CONTENT(args_s,inverte2) },
        [Duplica] =         { HASH_CONTENT(args_s,duplica) },
        [Duplica+128] =     { HASH_CONTENT(args_s,duplica) },
        [Duplica+256] =     { HASH_CONTENT(args_s,duplica) },
        [CopiaN] =          { HASH_CONTENT(args_s,copiaN) },
        [CopiaN+128] =      { HASH_CONTENT(args_s,copiaN) },
        [CopiaN+256] =      { HASH_CONTENT(args_s,copiaN) },
        [Pop] =             { HASH_CONTENT(args_s,void_pop) },
        [Pop+128] =         { HASH_CONTENT(args_s,void_pop) },
        [Pop+256] =         { HASH_CONTENT(args_s,void_pop) },
        // GUIÃO 3
        [FromEitherE] =     { HASH_CONTENT(args_2,elogic) },
        [FromEitherOu] =    { HASH_CONTENT(args_2,oulogic) },
        [Igual] =           { HASH_CONTENT(args_2,igual) },
        [Maior] =           { HASH_CONTENT(args_2,maior) },
        [Menor] =           { HASH_CONTENT(args_2,menor) },
        [FromEitherMaior] = { HASH_CONTENT(args_2,compmaior) },
        [FromEitherMenor] = { HASH_CONTENT(args_2,compmenor) },
        [Nao] =             { HASH_CONTENT(args_1,nao) },
        [Ifthenelse] =      { HASH_CONTENT(args_3,ifthenelse) },
        [Ifthenelse+128] =  { HASH_CONTENT(args_3,ifthenelse) },
        [Ifthenelse+256] =  { HASH_CONTENT(args_3,ifthenelse) },
        // GUIÃO 4
        [Range] =           { HASH_CONTENT(args_1,range) },
        [Length] =          { HASH_CONTENT(args_1,length) },
        [ReadInput] =       { HASH_CONTENT(args_s,ler_input) },
        [ReadInput+128] =   { HASH_CONTENT(args_s,ler_input) },
        [ReadInput+256] =   { HASH_CONTENT(args_s,ler_input) },
        [ValIndex] =        { HASH_CONTENT(args_2,indice) },
        [ElemInit] =        { HASH_CONTENT(args_2,buscarXINICIO) },
        [RemoveFim] =       { HASH_CONTENT(args_1,removerFIM) },
        [SubstringIndex] =  { HASH_CONTENT(args_2,substring) },
        [Separa] =          { HASH_CONTENT(args_2,separar_which) },
        [PopStack] =        { HASH_CONTENT(args_1,colocar_stack) },
        [ElemEnd] =         { HASH_CONTENT(args_2,buscarXFIM) },
        [Concat] =          { HASH_CONTENT(args_2,concatenar_sa) },
        [ConcatenarVezes] = { HASH_CONTENT(args_2,concatenarVezes) },
        [RemoveInicio] =    { HASH_CONTENT(args_1,removerINICIO) },
        // GUIÃO 5
        [ExecBloco] =       { HASH_CONTENT(args_b,aplicarbloco) },
        [Map] =             { HASH_CONTENT(args_b,map) },           // não funciona
        [Fold] =            { HASH_CONTENT(args_b,fold) },          // acho que está ao contrário
        [Filter] =          { HASH_CONTENT(args_b,filter) },        // não funciona
        // [Sort] =         { HASH_CONTENT(args_b,sort) },
        [While] =           { HASH_CONTENT(args_b,while_bloco) }    // não testei
    };
return hashtable;
}