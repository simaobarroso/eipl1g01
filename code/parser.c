#include "parser.h"

#include <ctype.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8192

void parser(Stack* stack, char* line, int* hashmap, Container* vars) {
    int i = 0;
    Container toPush;
    relable_container(&toPush, String);
    while (line[i] != '\n' && line[i] != '\0') { // como o fgets apanha o '\n', verificamos para ambos, o '\0' 'e apenas standard verificar em C
        
        // para nums
        if (isdigit(line[i]) || line[i] == '.' || (line[i] == '-' && isdigit(line[i+1]))) {
            toPush = number_parse(line, &i);
            push(toPush,stack);
        }

        // para char
        else if (line[i] == '\'') {
            relable_container(&toPush, Char);
            toPush.content.c = line[++i];
            ++i;
        }

        // para strings/arrays/blocos
        else if (line[i] == '[' || line[i] == '"' || line[i] == '{') {
            // if (line[i-1] == '\'') {
            char* string = "";
            switch (line[i]) {
                // case '[': parse_array(); break;
                case '"':
                    while(line[i] != '"' && line[i+1] == ' ') { // isto pode dar treta para depois do guião 3 --Mota
                        strncat(string,&line[i++],1);
                    }
                    toPush.content.s = strndup(string,80);
                    break;
                default: return;
            push(toPush,stack);
            }
        }

        // para variáveis
        else if (line[i] >= 'A' && line[i] <= 'Z') {
            int control = 0;
            variavel(stack,line[i],vars,control);
            push(vars[line[i] - 'A'],stack);
        }

        // para ops
        else if (hashmap[(int)line[i]]) operation(line, stack, vars, hashmap, &i);
        
        else assert(0 || "Error: wrong input.");
        i++;
    }
}

Container number_parse(char* line, int* i) {
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
        res.content.s = strndup(num,80);
        (*i) += 2;
    }
    // TODO(Mota): estas condições aqui em baixo podem ser genéricas, certo era fixe se pudessemos separar isto
    else {
        if (isfloat) {  // verifica se é float
            relable_container(&res,Double);
            res.content.f = strtof(num,&aux);
        } else {  // acontece se for long
            relable_container(&res,Long);
            res.content.l = strtol(num,&aux,10);
        }
    }
    return res;
}

void operation(char* line, Stack* stack, Container* vars, int* hashmap, int* i) { // provavelmente vamos ter que dar um carater de controlo
    Container res;
    int control = 1;
    char newline[SIZE];
    switch (line[*i]) {
        case NewLine:
            assert(fgets(newline, SIZE, stdin) != NULL);
            parser(stack,newline,hashmap,vars);
            /*
            strncat(newline,&line[i],SIZE/2);   // TODO(Mota): isto come sempre o primeiro carater, acho que os endereços estão errados algures
            line[i-1] = '\0';                   // nope, nao estou orgulhoso disto --Mota
            strncat(line,newline,SIZE/2);
            */
        case Either: /* *iterator++; */ break;
        case Soma:
            res = soma(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Subtrai:
            res = subtrai(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Multiplica:
            res = multiplica(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Divide:
            res = divide(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Modulo:
            res = modulo(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Potencia:
            res = potencia(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Bitwiseand:
            res = bitwiseand(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Bitwiseor:
            res = bitwiseor(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Bitwisexor:
            res = bitwisexor(pop(stack), pop(stack));
            push(res, stack);
            break;
        case Incrementa:
            res = incrementa(pop(stack));
            push(res, stack);
            break;
        case Decrementa:
            res = decrementa(pop(stack));
            push(res, stack);
            break;
        case Bitwisenot:
            res = bitwisenot(pop(stack));
            push(res, stack);
            break;
        case ToChar:
            res = toChar(pop(stack));
            push(res, stack);
            break;
        case ToDouble:
            res = toDouble(pop(stack));
            push(res, stack);
            break;
        case ToInt:
            res = toInt(pop(stack));
            push(res, stack);
            break;
        case ToString:
            res = toString(pop(stack));
            push(res, stack);
            break;
        case CopiaTopo:
            (*i)++;
            variavel(stack,line[*i],vars,control);
            break;
        case Troca3: troca3(stack); break;
        case Inverte2: inverte2(stack); break;
        case Duplica: duplica(stack); break;
        case CopiaN: copiaN(stack); break;
        case Pop: pop(stack); break;
        default: return;
    }
}

void variavel(Stack* s,char var,Container* vars, int control) {
    vars[var - 'A'] = (control) ? s->arr[s->sizeofstack-1] : vars[var - 'A'];
}