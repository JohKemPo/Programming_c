#include <stdio.h>
#include <stdlib.h>
#include "header_TLL.h"


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

    // TLL *aux = lst->next;
    new->next = lst->next;
    lst->next = new;

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
    TLL *aux;
    while (lst != NULL) {
        aux = lst;
        lst = lst->next;
        free(aux);
    }
    printf("CLEAR");
}