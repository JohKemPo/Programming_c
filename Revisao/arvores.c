#include <stdio.h>
#include <stdlib.h>

typedef struct ArvoreBin
{
    int info;
    struct ArvBin *esq, *dir;
}TAB;

//init
TAB *init();
//del
//print
//busca
//criar (raiz, esq, dir )
TAB *criar(int raiz, TAB *esq, TAB *dir);
TAB *insere_vet(int *vet, int n);
//altura
    int maior(int x, int y){
        if( x >= y) return x;
        return y;
    }
    //vazia = -1
    int calc_altura(TAB *a){
        if(!a)return -1;
        return a + maior(calc_altura(a->esq), calc_altura(a->dir));
    }
//nivel
//remove no especifico
//remover par
//remover impar
//remover k

int main(int argc, char const *argv[])
{
    TAB *ab;
    return 0;
}

TAB *init(){
    return NULL;
}

TAB *criar(int raiz, TAB *esq, TAB *dir)
{
    TAB *new = (TAB*) malloc(sizeof(TAB));
    if(!new)exit(1);

    new->info = raiz;
    new->esq = esq;
    new->dir = dir;

    return new;
}

TAB *insere_vet(int *vet, int n){
    if(n <= 0) return NULL;
    return criar(vet[n/2], insere_vet(vet, n/2), insere_vet(&vet[(n/2)+1], n-(n/2)-1));
}

