#include "parser.h"
#include "../operations/operations.h"
#include "../types.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

void parser(Stack stack, char* line, void* hashmap, Container* vars) {
    while(line) {
        
        line+=2; // passa o espaço ou o que for à frente, crasha se não for
    }
}

void number_parse(Stack stack,char* line, int* i) {
    Container res;
    int isfloat = 0;
    char num[20] = "";
    char* aux = num;

    while (isdigit(line[*i]) || line[*i] == '.' || (line[*i] == '-' && isdigit(line[*i+1]))) {
        if (line[*i] == '.') isfloat = 1;
        strncat(num,&line[*i],1);
        (*i)++;
        aux++;
    }
    if (line[(*i)+2] == 's') {
        res.label = String;
        res.STRING = strndup(num,80);
        (*i) += 2;
    }
    // TODO(Mota): estas condições aqui em baixo podem ser genéricas, certo era fixe se pudessemos separar isto
    else {
        if (isfloat) {  // verifica se é float
            initialize_container(&res,Double);
            res.DOUBLE = strtof(num,&aux);
        } else {  // acontece se for long
            initialize_container(&res,Long);
            res.LONG = strtol(num,&aux,10);
        }
    }
    push(res,stack);
}

void fazer_bloco(Stack s,char* line,int* i) { // lembrar que isto não junta {} nem ' ' ao bloco
    (*i) += 2;
    char bloco[80] = "";
    Container res = { .label = Block };

    while(line[(*i)+1] != '}') {
        strncat(bloco,&line[*i],1);
        (*i)++;
    }
    (*i)++;
    res.content.b = strdup(bloco);
    push(res,s);
}

void newline(Stack s,char* line) {
    char* newline;
    assert(fgets(newline, SIZE, stdin) != NULL);
    strcat(newline,line); // isto da maneira que está anda 2 para a frente e não devia
}

void types_conversion(Container* x, char* line, int* i) {
    switch(line[*i]) {
        case 'i': toInt(*x);
        case 'f': toDouble(*x);
        case 'c': toChar(*x);
        default: toString(*x);
    }
}