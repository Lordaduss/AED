#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct{
    int item[MAX];
    int topo;
}Pilha;

void iniPilha(Pilha *p){
    p->topo = 0;
}

int vaziaPilha(Pilha *p){
    if (p->topo == 0){
        return(1);
    }
    else{
        return(0);
    }
}

int cheiaPilha(Pilha *p){
    if (p->topo == MAX){
        return(1);
    }
    else{
        return(0);
    }
}

int push(Pilha *p, int x){
    if (cheiaPilha(p)) {
        return(0);
    }
    else{
        p->item[p->topo] = x;
        p->topo++;
        return(p->topo);
    }
}

int pop(Pilha *p){
   if (vaziaPilha(p)){
      return(0);
   }
   else{
      p->topo--;
      return(p->item[p->topo]);
   }
}
