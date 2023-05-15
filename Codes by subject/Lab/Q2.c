// AB e ABB
#include <stdio.h>
#include <stdlib.h>
#include "TAB.c"
// #include "TABB.c"
#include "TLSEINT.c"

/*
(Q2) Retornar todos os ancestrais de um nó na árvore B, da raiz da árvore até o elemento passado como parâmetro,
usando a biblioteca de lista encadeada - TLSEINT* misc(TAB *a, int elem), onde:

typedef struct lseint{
  int lim_inf, lim_sup;
  struct lseint *prox;
} TLSEINT;
*/

#define inf -10000000
#define sup 10000000

TLSEINT *anc(TAB *ab, int elem);
TLSEINT *anc_aux(TAB *ab, int elem, int *vet,int tam);
void TAB_to_vet(TAB *ab, int *vet, int *posicao);
void bubbleSort(int *vet, int n);
void len_ab(TAB* ab, int *count);
int superior(int *vet, int n, int tam);
int inferior(int *vet, int n, int tam);


int main(int argc, char const *argv[])
{
    
    TAB *ab = TAB_inicializa();
    TLSEINT *ancestrais = TLSEINT_inicializa();

    //CRIA A ARVORE BINÁRIA
    ab = TAB_cria(3,TAB_cria(5, 
                        TAB_cria(1, NULL, NULL) , 
                        TAB_cria(2, 
                            TAB_cria(4, NULL, NULL), 
                            TAB_cria(6, NULL, NULL))), 
                    TAB_cria(8,
                        TAB_cria(7, NULL, NULL), 
                        TAB_cria(9, NULL, NULL)));

    TAB_imp_ident(ab);

    ancestrais = anc(ab,2);
    TLSEINT_imprime(ancestrais);

    TAB_libera(ab);
    TLSEINT_libera(ancestrais);
    return 0;
}
void len_ab(TAB* ab, int *count){
    if(!ab)return;
    ++*count;
    len_ab(ab->esq, count);
    len_ab(ab->dir, count);
}

//CRIA VETOR COM O ELEMENTOS DA ARVORE EM PÓS ORDEM OU PROFUNDIDADE
void TAB_to_vet(TAB *ab, int *vet, int *posicao){
    if(!ab)return;
    
    vet[*posicao] = ab->info;
    ++*posicao;
    
    TAB_to_vet(ab->esq, vet, posicao);
    TAB_to_vet(ab->dir, vet, posicao);
}
//ORDENA O VETOR POR BUBBLE
void bubbleSort(int *vet, int n){
     int i, j;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (vet[j] > vet[j+1]) {
                // Troca os elementos
                int temp = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = temp;
            }
        }
    }
}
//ACHA LIMITE SUPERIOR
int superior(int *vet, int n, int tam){
    for(int i = 0; i < tam; i++){
        if(n == vet[i] && i == 0)return vet[i+1];
        if( n == vet[i] && i == tam-1)return sup;
        if(n == vet[i])return vet[i+1];
    }
}
//ACHA LIMITE INFERIOR
int inferior(int *vet, int n, int tam){
    for(int i = 0; i < tam; i++){
        if(n == vet[i] && i == 0)return inf;
        if( n == vet[i] && i == tam-1)return vet[i-1];
        if(n == vet[i])return vet[i-1];
    }        
}

TLSEINT *anc_aux(TAB *ab, int elem, int *vet,int tam){
    if(!ab || ab->info == elem)return NULL;
    if(TAB_busca(ab->esq, elem))return TLSEINT_insere(anc_aux(ab->esq, elem, vet, tam), inferior(vet,ab->info, tam), superior(vet,ab->info, tam));
    return TLSEINT_insere(anc_aux(ab->dir, elem, vet, tam), inferior(vet,ab->info, tam), superior(vet,ab->info, tam));
}


TLSEINT *anc(TAB *ab, int elem){
    if(!ab || !TAB_busca(ab, elem))return NULL;
    int count = 0, i = 0;
    int *vet;

    len_ab(ab, &count);
    printf("---%d\n", count);

    vet = (int*) malloc(count*sizeof(int));
    TAB_to_vet(ab, vet, &i);
    //ANTES DE ORDENAR
    for(int j =0; j < count; j++){
        printf("%d | ",vet[j]);
    }printf("\n");

    bubbleSort(vet, count);
    
    //PÓS DE ORDENAR
    for(int j =0; j < count; j++){
        printf("%d | ",vet[j]);
    }printf("\n");


    // printf("SUP = %d\n", superior(vet, 9, count));
    // printf("SUP = %d\n", inferior(vet, 9, count));

    // free(vet);

    return anc_aux(ab, elem, vet, count);
    
}