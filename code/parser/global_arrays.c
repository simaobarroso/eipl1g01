#include "../types.h"
#include "parser.h"
#include "../operations/operations.h"

Container* variables(void) {
    static Container vars[128] = {
        [A] = { .label = Long, .LONG = 10 },
        [B] = { .label = Long, .LONG = 11 },
        [C] = { .label = Long, .LONG = 12 },
        [D] = { .label = Long, .LONG = 13 },
        [E] = { .label = Long, .LONG = 14 },
        [F] = { .label = Long, .LONG = 15 },
        [G] = { .label = Long, .LONG = 0 },
        [H] = { .label = Long, .LONG = 0 },
        [I] = { .label = Long, .LONG = 0 },
        [J] = { .label = Long, .LONG = 0 },
        [K] = { .label = Long, .LONG = 0 },
        [L] = { .label = Long, .LONG = 0 },
        [M] = { .label = Long, .LONG = 0 },
        [N] = { .label = Char, .CHAR = '\n'},
        // meter o resto
        [S] = { .label = Char, .CHAR = ' '},
        // meter o resto
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
*/
OperatorFunction* hash(void) {
    static OperatorFunction hashmap[128*3] = {
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
        [Duplica] =         { HASH_CONTENT(args_s,duplica) },
        [CopiaN] =          { HASH_CONTENT(args_s,copiaN) },
        [Pop] =             { HASH_CONTENT(args_s,void_pop) },
        [Pop+128] =         { HASH_CONTENT(args_s,void_pop) },
        [Pop+256] =         { HASH_CONTENT(args_s,void_pop) },
        [Igual] =           { HASH_CONTENT(args_2,igual) }, // TODO: pode não ser usado só com Num
        [Maior] =           { HASH_CONTENT(args_2,maior) },
        [Menor] =           { HASH_CONTENT(args_2,menor) },
        [Nao] =             { HASH_CONTENT(args_1,nao) },
        [Ifthenelse] =      { HASH_CONTENT(args_3,ifthenelse) },
        [Ifthenelse+128] =  { HASH_CONTENT(args_3,ifthenelse) }
    };
return hashmap;
}