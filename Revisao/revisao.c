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

// void insert_k(TLSE *lst);
// void remove(TLSE *lst);
// void remove_first(TLSE *lst);// !!
// void remove_k(TLSE *lst);



int main(int argc, char const *argv[])
{
    TLSE *lst = init();
    lst = insert_start(lst, 3);
    lst = insert_start(lst, 2);
    lst = insert_start(lst, 1);

    // lst = insert_end(lst, 1);
    // lst = insert_end(lst, 3);
    // lst = insert_end(lst, 4);
    
    // print_direta(lst);
    print_direta_rec(lst);
    print_invers(lst); // TIRAR DÚVIDA

    clear(lst);
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
    TLSE *new = (TLSE*) malloc(sizeof(TLSE));
    if(!new) exit(1);

    /*
    TLSE *novo = insert_start(NULL, x);
    */

    new->info = info;
    new->prox = NULL;
    if(!lst)return new;

    TLSE *aux = lst;
    while(aux != NULL){
        aux = aux->prox;
    }
    aux->prox = new;
}

TLSE *insert_end_rec(TLSE *lst, int info){
    if(lst)return insert_start(lst, info); // insert_start(NULL, info)

    lst->prox = insert_end_rec(lst->prox, info);
    return lst;
}

TLSE *insert_ordered(TLSE *lst, int info){
    TLSE *p = lst, * ant = NULL;

    while(!p && p->info < info){
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
    if((lst) || lst->info >=info)return insert_start(lst, info);
}

TLSE *search(TLSE *lst, int info){
    TLSE *aux = lst;
    while(!aux && aux->info != info){
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
    printf("\n");
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
    }
    // printf("NULL");
}

void print_invers(TLSE *lst){
    TLSE *pointer = lst, *aux = init();
    printf("\n");
    while(pointer != NULL){
        aux = insert_start(aux, pointer->info);
        pointer = pointer->prox;
    }
    print_direta(aux);
    clear(aux);
}

