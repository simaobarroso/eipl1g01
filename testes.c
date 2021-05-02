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


#define SIZE 100
/**
 * \brief Função com testes aos vários guiões
 *
 */
void testes (){
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
    

    char line3[SIZE] = "79 108 97 c @ c @ c @";
    Stack b = initialize_stack();
    puts("Teste 1 : 79 108 97 c @ c @ c @ ");
    printf("Resultado suposto : Ola \nResultado obtido: ");
    parser(b,line3,hashtable,vars);
    printstack(b);
    free_stack(b);
    puts("\n");


    char line4[SIZE] = "2 3 4 @ ; _ # \ _ # +";
    Stack c = initialize_stack();
    puts("Teste 2 : 2 3 4 @ ; _ # \ _ # + ");
    printf("Resultado suposto : 283 \nResultado obtido: ");
    parser(c,line4,hashtable,vars);
    printstack(c);
    free_stack(c);
    puts("\n");


    char line5[SIZE] = "7 2 3 2 $";
    Stack d = initialize_stack();
    puts("Teste 3 : 7 2 3 2 $ ");
    printf("Resultado suposto : 7237 \nResultado obtido: ");
    parser(d,line5,hashtable,vars);
    printstack(d);
    free_stack(d);
    puts("\n");


    char line6[SIZE] = "1 2 3 4 5 \ ; @";
    Stack e = initialize_stack();
    puts("Teste 4 : 1 2 3 4 5 \ ; @");
    printf("Resultado suposto : 1352 \nResultado obtido: ");
    parser(e,line6,hashtable,vars);
    printstack(e);
    free_stack(e);
    puts("\n");

    puts("FIM DOS TESTES DO GUIÃO 3");
    
    // guião 3
    puts("TESTES GUIÃO 3:");

    char line7[SIZE] = "3 5 = ! 7 2 >" ;
    Stack f = initialize_stack();
    puts("Teste 1 : 3 5 = ! 7 2 > ");
    printf("Resultado suposto : 11 \nResultado obtido: ");
    parser(f,line7,hashtable,vars);
    printstack(f);
    free_stack(f);
    puts("\n");


    char line8[SIZE] = "5 2 = 2 3 ?" ;
    Stack g = initialize_stack();
    puts("Teste 2 : 5 2 = 2 3 ?");
    printf("Resultado suposto : 3 \nResultado obtido: ");
    parser(g,line8,hashtable,vars);
    printstack(g);
    free_stack(g);
    puts("\n");

    char line9[SIZE] = "A B * :T T" ;
    Stack h = initialize_stack();
    puts("Teste 3 : A B * :T T ");
    printf("Resultado suposto : 110110 \nResultado obtido: ");
    parser(h,line9,hashtable,vars);
    printstack(h);
    free_stack(h);
    puts("\n");


    char line10[SIZE] = "1 3 e&" ;
    Stack i = initialize_stack();
    puts("Teste 4 : 1 3 e& ");
    printf("Resultado suposto : 3 \nResultado obtido: ");
    parser(i,line10,hashtable,vars);
    printstack(i);
    free_stack(i);
    puts("\n");

    puts("FIM DOS TESTES DO GUIÃO 3");

    // guião 4
    puts("TESTES GUIÃO 4:");
    

    char line11[SIZE] = " [ 7 2 3 ] ," ;
    Stack j = initialize_stack();
    puts("Teste 1 : [ 7 2 3 ] ,  ");
    printf("Resultado suposto : 3  \nResultado obtido: ");
    parser(j,line11,hashtable,vars);
    printstack(j);
    free_stack(j);
    puts("\n");


    char line12[SIZE] = "“abc” 3 * _ S \ ," ;
    Stack k = initialize_stack();
    puts("Teste 2 : “abc” 3 * _ S \ ,");
    printf("Resultado suposto : abcabcabc 9  \nResultado obtido: ");
    parser(k,line12,hashtable,vars);
    printstack(k);
    free_stack(k);
    puts("\n");


    char line13[SIZE] = "5 , 3 >" ;
    Stack l = initialize_stack();
    puts("Teste 3 : 5 , 3 > ");
    printf("Resultado suposto : 234 \nResultado obtido: ");
    parser(l,line13,hashtable,vars);
    printstack(l);
    free_stack(l);
    puts("\n");


    char line14[SIZE] = "[ 1 2 3 ] ( + [ 7 5 ] +" ;
    Stack m = initialize_stack();
    puts("Teste 4 : [ 1 2 3 ] ( + [ 7 5 ] + ");
    printf("Resultado suposto : 23175  \nResultado obtido: ");
    parser(m,line14,hashtable,vars);
    printstack(m);
    free_stack(m);
    puts("\n");


    char line15[SIZE] = "“olaqqabcqqxyz” “qq” / ," ;
    Stack n = initialize_stack();
    puts("Teste 5 : “olaqqabcqqxyz” “qq” / , ");
    printf("Resultado suposto : 3 \nResultado obtido:  ");
    parser(n,line15,hashtable,vars);
    printstack(n);
    free_stack(n);
    puts("\n");
    
    puts("FIM DOS TESTES DO GUIÃO 4");
    
    // guião 5

    puts("TESTES GUIÃO 5:");

    char line16[SIZE] = "2 { 3 * }" ;
    Stack o = initialize_stack();
    puts("Teste 1 : 2 { 3 * }");
    printf("Resultado suposto : 2{ 3 * } \nResultado obtido:  ");
    parser(o,line16,hashtable,vars);
    printstack(o);
    free_stack(o);
    puts("\n");


    char line17[SIZE] = "[ 1 2 3 ] { 2 # } %" ;
    Stack p = initialize_stack();
    puts("Teste 2 :[ 1 2 3 ] { 2 # } % ");
    printf("Resultado suposto : 149 \nResultado obtido:  ");
    parser(p,line17,hashtable,vars);
    printstack(p);
    free_stack(p);
    puts("\n");

    char line18[SIZE] = "5 , { ) } %" ;
    Stack q = initialize_stack();
    puts("Teste 3 :5 , { ) } % ");
    printf("Resultado suposto : 12345 \nResultado obtido:  ");
    parser(q,line18,hashtable,vars);
    printstack(q);
    free_stack(q);
    puts("\n");


    char line19[SIZE] = "10 , { ) } % { * } *" ;
    Stack r = initialize_stack();
    puts("Teste 4 : 10 , { ) } % { * } * ");
    printf("Resultado suposto : 3628800 \nResultado obtido:  ");
    parser(r,line19,hashtable,vars);
    printstack(r);
    free_stack(r);
    puts("\n");


    char line20[SIZE] = "l { ( ( } % qnc" ;
    Stack t = initialize_stack();
    puts("Teste 5 : l { ( ( } % qnc");
    printf("Resultado suposto : ola  \nResultado obtido:  ");
    parser(t,line20,hashtable,vars);
    printstack(t);
    free_stack(t);
    puts("\n");

    char line21[SIZE] = "2 { 3 * } ~" ;
    Stack u = initialize_stack();
    puts("Teste 6 : 2 { 3 * } ");
    printf("Resultado suposto : 6 \nResultado obtido:  ");
    parser(u,line21,hashtable,vars);
    printstack(u);
    free_stack(u);
    puts("\n");

    puts("FIM DOS TESTES DO GUIÃO 5");

}
