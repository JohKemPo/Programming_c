/**
 * @file Exe1.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*
Faça uma função recursiva que retorne o número de nós contidos em uma lista L. Considere que L é
simplesmente encadeada, sem nó cabeça e não circular. Os elementos de L não estão necessariamente
em ordem.
*/
#include <stdio.h>
#include <stdlib.h>
#include "header_TLL.h"


int main(int argc, char const *argv[])
{
    TLL *lst = (TLL*) malloc(sizeof(TLL));
    if(!lst)exit(1);

    init(lst);
    print(lst);
    printf("Number of nodes: %d\n", count_node(lst));
    // insert_start(lst);
    // insert_start(lst);
    // insert_start(lst);
    insert_end(lst);
    insert_end(lst);
    insert_end(lst);
    print(lst);
    printf("Number of nodes: %d\n", count_node(lst));
    clean(lst);
    print(lst);
    
    free(lst);
    return 0;
}

void init(TLL *lst)
{
    lst->next = NULL;
}
int empity(TLL *lst)
{
    if(lst->next == NULL)return 1;
    return 0;
}
int count_node(TLL *lst)
{
   int count = 0 ;
   TLL *aux = lst;

   while(aux->next != NULL)
   {
        count++;
        aux = aux->next;
   }
   return count; 
}
void insert_start(TLL *lst)
{
    TLL *new = (TLL*) malloc(sizeof(TLL));
    if(!new)exit(1);

    printf("Enter info: ");
    scanf("%d", &new->info);

    new->next = lst->next;
    lst->next = new;

}

void insert_end(TLL *lst)
{
    TLL *new = (TLL*) malloc(sizeof(TLL));
    if(!new)exit(1);

    printf("Enter info: ");
    scanf("%d", &new->info);

    TLL *aux = lst;
    while (aux->next != NULL)
    {
        aux = aux->next;
    }
    aux->next = new;
    new->next = NULL;
    
}
void print(TLL *lst)
{
    
    if(empity(lst)){
        printf("-> NULL\n");
    }else{

        TLL *aux = lst->next; 
        while(aux != NULL)
        {
            printf("| %d | -> ", aux->info);
            aux = aux->next;

        }
        printf("NULL\n");
    }
}
void clean(TLL *lst){
    // TLL *aux;
    // while (lst != NULL) {
    //     aux = lst;
    //     lst = lst->next;
    //     free(aux);
    // }
    if(!empity(lst))
    {
        TLL *nextNo, *currNo;
        currNo = lst->next;
        while(currNo != NULL)
        {
            nextNo = currNo->next;
            free(currNo);
            currNo = nextNo;
        }
    }
    init(lst);
    printf("\nCLEAR\n");
}