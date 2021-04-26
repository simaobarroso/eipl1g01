#include "types.h"

int isFoldable(Container c) {
    return (c.label >= String && !Block);
}

int isNum(Label l) {
    return (l <= Char);
}

Label numReturn(Label x, Label y) {
    return (x > y) ? x : y;
}

Label foldType(Foldable t) {
    return (STACK(t)) ? Array : String;
}