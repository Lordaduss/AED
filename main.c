#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

int main()
{
    char *s = "(A+B}";
    int topoPilha,i;
    Pilha p;

    iniPilha(&p);
    for(i=0; s[i]!='\0'; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            push(&p,s[i]);
        }
        if(s[i]==')' || s[i]=='}' || s[i]==']'){
            if(vaziaPilha(&p)){
                printf("O finalizador nao possui um inicializador");
                exit(1);
            }
            else{
                topoPilha=pop(&p);
                if(topoPilha=='(' && s[i]!=')'){
                    printf("Os delimitadores nao sao do mesmo tipo");
                    exit(1);
                }
                else if(topoPilha=='{' && s[i]!='{'){
                    printf("Os delimitadores nao sao do mesmo tipo");
                    exit(1);
                }
                else if(topoPilha=='[' && s[i]!=']'){
                    printf("Os delimitadores nao sao do mesmo tipo");
                    exit(1);
                }
            }
        }
    }
    if(!vaziaPilha(&p)){
        printf("Algum escopo nao foi fechado");
    }
    else{
        printf("A expressao esta correta");
    }
}
