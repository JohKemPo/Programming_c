// AB e ABB
#include <stdio.h>
#include <stdlib.h>
#include "TAB.c"
// #include "TABB.c"
#include "TLSEINT.c"

/*
Q1) Uma função em C que, dada uma árvore B qualquer, retorne, num vetor, todos
os elementos maiores que N. A função deve ter o seguinte protótipo: int* mN(TAB*a, int N, int *tam);
*/

int *TAB_mN(TAB *ab, int N, int max);
void len_vet_maior(TAB *ab, int n, int *count);
void TAB_to_vet(TAB *ab, int *vet, int N, int *posicao);



int main(int argc, char const *argv[])
{
    int count = 0;
    TAB *ab = TAB_inicializa();
    int *vet;

    ab = TAB_cria(3,TAB_cria(5, 
                        TAB_cria(1, NULL, NULL) , 
                        TAB_cria(2, 
                            TAB_cria(4, NULL, NULL), 
                            TAB_cria(6, NULL, NULL))), 
                    TAB_cria(8,
                        TAB_cria(7, NULL, NULL), 
                        TAB_cria(9, NULL, NULL)));

    TAB_imp_ident(ab);

    len_vet_maior(ab, 4, &count);
    
    vet = TAB_mN(ab, 4, count);

    for(int i =0; i < count; i++){
        printf("%d | ",vet[i]);
    }printf("\n");

    TAB_libera(ab);
    free(vet);
    return 0;
}

void len_vet_maior(TAB *ab, int n, int *count){
    if(ab){
        if(ab->info > n) ++*count;
        len_vet_maior(ab->esq,n,count);
        len_vet_maior(ab->dir,n,count);
    }
}

void TAB_to_vet(TAB *ab, int *vet, int N, int *posicao){
    if(!ab)return;
    if(ab->info > N){
        vet[*posicao] = ab->info;
        ++*posicao;
    }
    TAB_to_vet(ab->esq, vet, N, posicao);
    TAB_to_vet(ab->dir, vet, N, posicao);
}


int *TAB_mN(TAB *ab, int N, int max){
    int *aux = (int*) malloc( max * sizeof(int));
    int i = 0;

    TAB_to_vet(ab, aux, N, &i);
    return aux;    
}

