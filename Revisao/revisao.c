#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista * prox;
}TLSE;

TLSE *init();
TLSE *insert_start(TLSE *lst, int info);
TLSE *insert_end(TLSE *lst, int info);
TLSE *insert_end_rec(TLSE *lst, int info);
TLSE *insert_ordered(TLSE *lst, int info);
TLSE *insert_ordered_rec(TLSE *lst, int info);
TLSE *search(TLSE *lst, int info);
TLSE *search_rec(TLSE *lst, int info);
void print_direta(TLSE *lst);
void print_direta_rec(TLSE *lst);
void print_invers(TLSE *lst);
void clear(TLSE *lst);
TLSE *remove_elem(TLSE *lst, int info);
void inverte(TLSE* lst);
TLSE *inverte_retornando(TLSE* lst);
TLSE *desloca (TLSE* lst, int n);
TLSE *copia (TLSE *lst);
TLSE* rto (TLSE* lst, int elem);

// void remove_first(TLSE *lst);// !!



int main(int argc, char const *argv[])
{
    TLSE *lst = init(), *busca, *deslocada, *copiada, *aparicoes;
    // lst = insert_start(lst, 3);
    // lst = insert_start(lst, 2);
    // lst = insert_start(lst, 1);

    // lst = insert_ordered(lst, 10);
    // lst = insert_ordered(lst, 9); 
    // lst = insert_ordered(lst, 2);
    
    // lst = insert_ordered_rec(lst, 10);
    // lst = insert_ordered_rec(lst, 9);
    // lst = insert_ordered_rec(lst, 2);
    
    // lst = insert_end(lst, 1);
    // lst = insert_end(lst, 3);
    // lst = insert_end(lst, 4);
    
    lst = insert_end_rec(lst, 1);
    lst = insert_end_rec(lst, 3);
    lst = insert_end_rec(lst, 4);
    lst = insert_end_rec(lst, 5);
    lst = insert_end_rec(lst, 8);
    lst = insert_end_rec(lst, 8);
    lst = insert_end_rec(lst, 8);
    lst = insert_end_rec(lst, 8);
    lst = insert_end_rec(lst, 10);

    printf("\nprint direta\n");
    print_direta(lst);
    printf("\nprint direta recursiva\n");
    print_direta_rec(lst);
    printf("\n\nprint inversa\n");
    print_invers(lst); // TIRAR DÚVIDA

    busca = search(lst, 1);
    if(busca)printf("Existe\n");
    busca = search_rec(lst, 3);
    if(busca)printf("Existe\n");

    printf("Remove elem\n");
    lst = remove_elem(lst, 3);
    print_direta(lst);


    inverte(lst);
    printf("Invertida\n");
    print_direta(lst);

    printf("Deslocada\n");
    deslocada = desloca(lst, 2);
    print_direta(deslocada);
    print_direta(lst);
    
    printf("Copiada\n");
    copiada = copia(lst);
    print_direta(copiada);
    print_direta(lst);

    printf("Aparicoes\n");
    aparicoes = rto(lst, 8);
    print_direta(aparicoes);
    print_direta(lst);


    clear(lst);
    clear(copiada);
    return 0;
}

TLSE *init(){
    return NULL;
}
void clear(TLSE *lst){
    TLSE *aux = lst, *pointer;
    while (aux){
        pointer = aux;
        aux = aux->prox;
        free(pointer);
    }
}

TLSE *insert_start(TLSE *lst, int info){
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    if(!new)exit(1);

    new->info = info;
    new->prox = lst;
    return new;
}
TLSE *insert_end(TLSE *lst, int info){
    // TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    // if(!new) exit(1);

    TLSE *new = insert_start(NULL, info);

    if(!lst)return new;

    TLSE *aux = lst;
    while(aux->prox){
        aux = aux->prox;
    }
    aux->prox = new;
    return lst;
}

TLSE *insert_end_rec(TLSE *lst, int info){
    if(!lst)return insert_start(lst, info); // insert_start(NULL, info)

    lst->prox = insert_end_rec(lst->prox, info);
    return lst;
}

TLSE *insert_ordered(TLSE *lst, int info){
    TLSE *p = lst, * ant = NULL;

    while((p) && p->info < info){
        ant = p;
        p = p->prox;
    }
    if(ant == NULL){
        return insert_start(lst, info);
    }
    ant->prox = insert_start(p, info);
    return lst;
}

TLSE *insert_ordered_rec(TLSE *lst, int info){
    if((!lst) || lst->info >=info)return insert_start(lst, info);
    // lst != Null --> lst
    // lst == Null --> !lst
}

TLSE *search(TLSE *lst, int info){
    TLSE *aux = lst;
    while(aux && aux->info != info){
        aux = aux->prox;
    }
    return aux;
}

TLSE *search_rec(TLSE *lst, int info){
    if((lst) || lst->info==info) return lst;
    return search_rec(lst->prox, info);
}


void print_direta(TLSE *lst){
    TLSE *aux = lst;
    while(aux != NULL){
        printf("| %d| -> ", aux->info);
        aux = aux->prox;
    }
    printf("NULL\n");
}

void print_direta_rec(TLSE *lst){
   
    if(lst != NULL){
        printf("| %d| -> ", lst->info);
        print_direta_rec(lst->prox);
    }else printf("NULL");
}

void print_invers(TLSE *lst){
    TLSE *pointer = lst, *aux = init();
    
    while(pointer != NULL){
        aux = insert_start(aux, pointer->info);
        pointer = pointer->prox;
    }
    print_direta(aux);
    clear(aux);
}

TLSE *remove_elem(TLSE *lst, int info){
    TLSE *aux = lst, *ant = NULL;

    if(!search(lst, info))return lst;

    //percorrer a lsita
    while(aux->prox && aux->info != info){
        // guardar o no anterior
        ant = aux;
        aux = aux->prox;
    } 
    if(!ant){
        ant = aux;
        aux = aux->prox;
        free(ant);
        return aux;
    }   

    //reeorg ponteiros
    ant->prox = aux->prox;

    //free elemento    
    free(aux);
    return lst;
}
void inverte(TLSE* lst) {
    TLSE *new = init(), *aux = lst;

    while(aux){
        new = insert_start(new, aux->info);
        aux = aux->prox;
    }
    // clear(lst);
    // lst = init();
    // print_direta(lst);
    // print_direta(new);
    *lst = *new;
}

TLSE *inverte_retornando(TLSE* lst) {
    TLSE *new = init(), *aux = lst;

    while(aux){
        new = insert_start(new, aux->info);
        aux = aux->prox;
    }
    // clear(lst);
    // lst = init();
    // print_direta(lst);
    // print_direta(new);
    return new;

}
TLSE *desloca (TLSE* lst, int n){
    TLSE *aux = lst, *aux_tmp = copia(lst);
    int tmp;

    if( n % 2 == 0){
        tmp = lst->info;
        aux_tmp = remove_elem(aux_tmp, tmp);
        aux_tmp = insert_end(aux_tmp, tmp);
        return aux_tmp;
    }
    while (aux->prox)aux = aux->prox;
    
    tmp = aux->info;
    aux_tmp = remove_elem(aux_tmp, tmp);
    aux_tmp = insert_start(aux_tmp, tmp);
    print_direta(lst);
    return aux_tmp;
}

TLSE *copia (TLSE *lst){
    TLSE *aux = lst, *new = init();
    while (aux){
        new = insert_end(new, aux->info);
        aux = aux->prox;
    }
    // new = remove_elem(new, 4);
    return new;
}

TLSE* rto (TLSE* lst, int elem){
    TLSE *aux = copia(lst);

    while (search(aux, elem))aux = remove_elem(aux, elem);
    
    return aux;
}