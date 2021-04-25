#include "operations.h"
#include "../parser/parser.h"
#include "../stack.h"

Container* initialize_vars(void) {
    static Container vars[26];
    for(int i = 0, j= 10; i <= F; i++, j++) {
        vars[i].label = Long;
        vars[i].content.l = j;
    }
    vars[N].label = Char;
    vars[N].content.c = '\n';
    vars[S].label = Char;
    vars[S].content.c = ' ';
    for(int i = X, j = 0; i <= Z; i++, j++) {
        vars[i].label = Long;
        vars[i].content.l = j;
    }
    return vars;
}

void muda_variavel(Stack* s,char var,Container* vars, int control) {
    vars[var - 'A'] = (control) ? s->arr[s->sizeofstack-1] : vars[var - 'A'];
}