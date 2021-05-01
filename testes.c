/**
 * @file Ficheiro que contêm testes aos vários guiões
 */
#include "code/operations/operations.h"
#include "code/parser/parser.h"
#include "code/stack.h"
#include "code/types.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// FICHEIRO INCOMPLETO


#define SIZE 100
/**
 * \brief Função 
 *
 * @returns int
 */
int main (){
    OperatorFunction* hashtable = hash();
    Container* vars = variables();

    // guião 1 
    puts("TESTES GUIÃO 1");

    char line[SIZE] = "1 ) ) 7 ( ( ( #";
    Stack s = initialize_stack();
    puts("Teste 1 : 1 ) ) 7 ( ( ( # ");
    printf("Resultado suposto : 81 \nResultado obtido: ");
    parser(s,line,hashtable,vars);
    printstack(s);
    free_stack(s);
    puts("\n");


    puts("Teste 2 : ");
    Stack a = initialize_stack();
    char line2[SIZE] = " 12 7 2 &" ;
    puts("Teste 2 :12 7 2 &");
    parser(a,line2,hashtable,vars);
    printf("Resultado suposto : 14 \nResultado obtido: ");
    printstack(a);
    free_stack(a);
    puts("FIM DOS TESTES DO GUIÃO 1");
    
    // guião 2
    puts("TESTES GUIÃO 2:");
    
    puts("Teste 1 : ");
    char line3[SIZE] = "79 108 97 c @ c @ c @";
    Stack b = initialize_stack();
    puts("Teste 1 : 79 108 97 c @ c @ c @ ");
    printf("Resultado suposto : Ola \nResultado obtido: ");
    parser(b,line3,hashtable,vars);
    printstack(b);
    free_stack(b);
    puts("\n");

    puts("Teste 2 : ");
    char line4[SIZE] = "2 3 4 @ ; _ # \ _ # +";
    Stack c = initialize_stack();
    puts("Teste 2 : 2 3 4 @ ; _ # \ _ # + ");
    printf("Resultado suposto : 283 \nResultado obtido: ");
    parser(c,line4,hashtable,vars);
    printstack(c);
    free_stack(c);
    puts("\n");

    puts("Teste 3 : ");
    char line5[SIZE] = "";
    Stack d = initialize_stack();
    puts("Teste 3 : ");
    printf("Resultado suposto :  \nResultado obtido: ");
    parser(d,line5,hashtable,vars);
    printstack(d);
    free_stack(d);
    puts("\n");

    char line5[SIZE] = ;
    parser(s,line,hashtable,vars);

    puts("\n");

    puts("FIM DOS TESTES DO GUIÃO 3");
    
    // guião 3
    puts("");
    char line6[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line7[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line8[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line9[SIZE] = ;

    // guião 4
    char line10[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line11[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line12[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line13[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line14[SIZE] = ;
    
    
    // guião 5
    char line15[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line16[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line17[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line18[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line19[SIZE] = ;
    parser(s,line,hashtable,vars);


    char line20[SIZE] = ;

    return 0;
}
