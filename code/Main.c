#include <stdio.h>
#include <assert.h>
#include "operations.h"
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>

#define CALC 100

void stackop(Stack *,char *);
void initialize(Stack *);

//*****************************************
// Main
int main (){
   
     Stack s;
    char *calc = malloc(CALC*sizeof(char));
    
    assert(fgets(calc, CALC, stdin) != NULL);

    stackop(&s, calc);
    for(int i = 0; i < s.sizeofnums; i++) {
        printf("%d", s.nums[i]);
    }
    putchar('\n');
    freeall(&s,calc);
    return 0;
}

    
    return 0;

}

void stackop(Stack *stack, char *calc) {
    int calcsize = strlen(calc);
    changesizeofnums(stack,0);
    int i;
    while(i < calcsize) {
        // para nums
        if(calc[i] >= '0' || calc[i] <= '9') {
            char *num =  "";
            int sign = 1;
            
            while(calc[i] != ' ') {
                if(calc[i-1] == '-') sign = -1;
                strncat(num,&calc[i],1);
                i++;
            }
            push((atoi(num)*sign), stack);
        }
        // para ops
        else {
            int op = optype(calc[i]);
            if(op != -1) {
                int *n = peek(stack);
                operation(calc[i],n-op);
                if(op) freelast(stack);
                stack->current -= op+1;
            }
            i++;
        }
    }
}
