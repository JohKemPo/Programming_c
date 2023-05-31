#include <stdio.h>
#include <stdlib.h>

typedef struct arvb{
    int nchaves, *chave, floha;
    struct arvb **filho;
}TARVB;

TARVB * TARVB_inicializa(int t){
    TARVB *a = (TARVB*) malloc(sizeof(TARVB));
    if(!a) exit(1);

    a->nchaves = 0;
    a->floha = 1;
    a->chave = (int*) malloc (sizeof(int) * ((2*t) - 1));
    a->filho = (TARVB **) malloc(sizeof(TARVB*) * (2*t));
    int i = 0;
    for(i; i < 2*t; i++)a->filho[i] = NULL;

    return a;
}


