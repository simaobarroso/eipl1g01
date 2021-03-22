#include <assert.h>
#include "operations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CALC 100

void stackop(Stack *,char *);

int main(void) {
    Stack s;
    initialize(&s);
    char calc[CALC];
    assert(fgets(calc, CALC, stdin) != NULL);

    stackop(&s, calc);
    for(int i = 0; i < s.sizeofnums; i++) {
        printf("%d", s.nums[i]);
    }
    putchar('\n');
    return 0;
}

void stackop(Stack *stack, char *calc) {
    int i = 0;

    while(calc[i] != '\n' && calc[i] != '\0') {
        // para nums
        char num[15] = "";
        int sign = 1;
            if(calc[i] >= '0' && calc[i] <= '9') { // 30 = '0' e 39 = '9'
            // push((atoi(num)*sign), stack);
        }
        // para ops
        else if(calc[i+1] == ' ' || calc[i+1] == '\0' || calc[i+1] == '\n') {
            operation(calc[i],stack);
        }
        i++;
    }
}