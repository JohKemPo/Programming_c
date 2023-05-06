#include "TABB.c"
#include <stdio.h>
#include <stdlib.h>

// TABB *TABB_inicializa(void);
// TABB *TABB_cria(int raiz, TABB *esq, TABB *dir);

// void TABB_imp_pre(TABB *a);
// void TABB_imp_pos(TABB *a);
// void TABB_imp_sim(TABB *a);
// void TABB_imp_ident(TABB *a);

// void TABB_libera(TABB *a);

// TABB *TABB_busca(TABB *a, int elem);

// TABB *TABB_insere(TABB *a, int elem);
// TABB *TABB_retira(TABB *a, int info);

TABB *TABB_maior(TABB *a);
TABB *TABB_menor(TABB *a);
TABB* retira_impares(TABB* a);
int* mN(TABB*a, int N);
int count(TABB *a, int n);
void add_vet(int *vet, TABB *a, int N, int *pos);

int main(int argc, char const *argv[])
{
    TABB *a = TABB_inicializa();
    int *vet;

    a = TABB_cria(5, NULL, NULL);
    a = TABB_insere(a, 10);
    a = TABB_insere(a, 2);
    a = TABB_insere(a, 3);
    a = TABB_insere(a, 4);
    a = TABB_insere(a, 1);
    a = TABB_insere(a, 7);
    a = TABB_insere(a, 6);
    TABB_imp_ident(a);

    printf("MAIOR:\n");
    TABB_imp_ident(TABB_maior(a));

    printf("\nMENOR:\n");
    TABB_imp_ident(TABB_menor(a));

    printf("\nSEM IMPAR:\n");
    TABB_imp_ident(retira_impares(a));


    printf("%d", count(a, 11));

    TABB_libera(a);
    return 0;
}
TABB *TABB_maior(TABB *a)
{
    if(a->dir)return TABB_maior(a->dir);
    return a;
}

TABB *TABB_menor(TABB *a)
{
    if(a->esq)return TABB_maior(a->esq);
    return a;
}

TABB* retira_impares(TABB* a){
    if(!a) return a;

    a->esq = retira_impares(a->esq);
    a->dir = retira_impares(a->dir);

    if(a->info % 2 != 0) a = TABB_retira(a, a->info);

    return a;
}

int count(TABB *a, int n){

    if(!a) return 0;

    
    if(a->info < n) return 2 + count(a->esq, n) + count(a->dir, n);
    return count(a->esq, n);
}
void add_vet(int *vet, TABB *a, int N, int *pos){
    if(!a) return;
    if(a->info >= N) add_vet(vet, a->esq, N, pos);
    else{
        add_vet(vet, a->esq, N, pos);
        vet[*pos] = a->info;
        ++*pos;        
        add_vet(vet, a->dir, N, pos);
    }
}
int* mN(TABB*a, int N){
    if(!a) return NULL;
    int *vet = (int*) malloc(count(a, N) *  sizeof(int));

    add_vet(vet, a, N, 0);
}
