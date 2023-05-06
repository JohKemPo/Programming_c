#include <stdio.h>
#include <stdlib.h>
#include "TAB.c"

void TAB_imp_niv(TAB *a);
TAB* copia (TAB *a);
TAB* espelho (TAB *a);
TAB* maior(TAB *a);
TAB* maior_aux(TAB *a, TAB *maior);
TAB* menor(TAB *a);
TAB* menor_aux(TAB *a, TAB *menor);
int igual (TAB* a, TAB* b);
int nf(TAB *a);

int main(int argc, char const *argv[])
{
    TAB *a = TAB_inicializa(), *b = TAB_inicializa(), *espelhada;
    a = TAB_cria(2, TAB_cria(4, TAB_cria(4, TAB_cria(6, NULL, NULL), TAB_cria(4, NULL, NULL)), TAB_cria(6, NULL, NULL)), TAB_cria(6, NULL, NULL));
    // b = TAB_cria(2, TAB_cria(4, NULL, NULL), TAB_cria(6, NULL, NULL));
    b = copia(a);

    TAB_imp_ident(a);
    printf("-------------------------\n\n");
    TAB_imp_ident(b);
    //copia
    espelhada = espelho(a);
    printf("-------------------------\n\n");
    TAB_imp_ident(espelhada);
    printf("-------------------------\n\n");
    printf("MAIOR - %d", maior(a)->info);
    printf("\nMENOR - %d", menor(a)->info);

    printf("\n-------------------------\n\n");
    if(igual(a,b))printf("IGUAIS");

    printf("-------------------------\n\n");
    printf("NF - %d", nf(a));

    TAB_libera(a);
    TAB_libera(b);
    TAB_libera(espelhada);
    return 0;
}
 int nf(TAB *a){
    if(!a)return 0;
    if(!a->esq && !a->dir)return 1;
    return nf(a->esq) + nf(a->dir);
    
 }

int igual (TAB* a, TAB* b){
    if(!a || !b)return 1;
    if(!a || !b || a->info != b->info)return 0;
    return igual(a->esq, b->esq) && igual(a->dir, b->dir);
}

TAB *maior_aux(TAB *a, TAB *maior){
    if(a){
        maior = maior_aux(a->esq, maior);
        if(a->info > maior->info)return a;
        maior = maior_aux(a->dir, maior);
        if(a->info > maior->info)return a;
    }
    return maior;
}
TAB* maior(TAB *a){
    return maior_aux(a, a);
}

TAB *menor_aux(TAB *a, TAB *menor){
    if(a){
        menor = menor_aux(a->esq, menor);
        if(a->info < menor->info)return a;
        menor = menor_aux(a->dir, menor);
        if(a->info < menor->info)return a;
    }
    return menor;
}
TAB* menor(TAB *a){
    return menor_aux(a, a);
}


TAB* copia (TAB *a){
    TAB *aux = TAB_inicializa();
    if(a){
        copia(a->esq);
        copia(a->dir);
        aux = TAB_cria(a->info, a->esq, a->dir);
    }
    return aux;
}

TAB* espelho (TAB *a){
    TAB *espelho = TAB_inicializa();
    if(a){
        copia(a->esq);
        copia(a->dir);
        espelho = TAB_cria(a->info, a->dir, a->esq);
    }
}
void TAB_imp_nivel(TAB *a){
    //usa fial
    //crai a fila
    //insere no
    //enquanto a fila n esta vazia
}


// void TAB_imp_pre(TAB *a){
//     if(a){
//         printf("%d", a->info);
//         TAB_imp_pre(a->esq);
//         TAB_imp_pre(a->dir);
//     }
// }


// void TAB_imp_sim(TAB *a){
//     if(a){
//         TAB_imp_sim(a->esq);
//         printf("%d", a->info);
//         TAB_imp_sim(a->dir);
//     }
// }


// void TAB_imp_pos(TAB *a){
//     if(a){
//         TAB_imp_pos(a->esq);
//         TAB_imp_pos(a->dir);
//         printf("%d", a->info);
//     }
// }


// void TAB_imp_nivel(TAB *a){
//     //usa fial
//     //crai a fila
//     //insere no
//     //enquanto a fila n esta vazia
// }

//  TAB *search_pre(TAB *a, int info){
//     if((!a) || (a->info == info)) return a;
//     TAB *resp = TAB_busca(a->esq, info);
//     if(resp) return resp;
//     return TAB_busca(a->dir, info);
// }

// void TAB_libera(TAB *a){
//   if(a){
//     TAB_libera(a->esq);
//     TAB_libera(a->dir);
//     free(a);
//   }
// }