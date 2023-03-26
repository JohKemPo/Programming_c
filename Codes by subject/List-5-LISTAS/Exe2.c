/**
 * @file Exe2.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
Considere uma lista onde cada nó é composto pelo código, nome e preço de um produto. A lista está
ordenada por ordem crescente do código do produto.

a. Considerando alocação sequencial estática, faça a declaração desta estrutura e uma função que
receba esta lista como parâmetro e que escreva os dados de todos os produtos contidos  na
lista.
b. Considerando uma lista simplesmente encadeada dinâmica, faça a declaração desta  estrutura e
uma função que calcule e retorne a média de preços.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Type_linked_list
{
    int cod;
    char name[40];
    float value;
    struct Type_linked_list *next;
}TLL;

void init(TLL *lst);
int empity(TLL *lst);
int count_node(TLL *lst);
// void insert_start(TLL *lst);
void insert_order(TLL **lst);
void print(TLL *lst);
void clean(TLL *lst);

// void insert_ordered_2(TLL *lst, int cod, char name[], float value);

int main(int argc, char const *argv[])
{
    TLL *lst = (TLL*) malloc(sizeof(TLL));
    if(!lst)exit(1);

    init(lst);
    print(lst);
    insert_order(&lst); 
    insert_order(&lst); 
    // insert_start(lst);
    // insert_start(lst);
    // insert_ordered_2( lst, 1, "a", 2.3);
    // insert_ordered_2( lst, 1, "a", 2.3);

    printf("Number of nodes: %d\n", count_node(lst));
    print(lst);

    clean(lst);

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
// void insert_start(TLL *lst)
// {
//     TLL *new = (TLL*) malloc(sizeof(TLL));
//     if(!new)exit(1);

//     printf("\nEnter name: ");
//     scanf("%s", &new->name);
//     printf("Enter code: ");
//     scanf("%d", &new->cod);
//     printf("Enter value: ");
//     scanf("%f", &new->value);

//     // TLL *aux = lst->next;
//     new->next = lst->next;
//     lst->next = new;

// }
void print(TLL *lst)
{
    
    if(empity(lst)){
        printf("-> NULL\n");
    }else{

        TLL *aux = lst->next; 
        while(aux != NULL)
        {
            // printf("\n--------------------- INFOS ABOUT [ %c ] --------------------- ", aux->name);
            // printf("\n------------------------ COD: %d -----------------------", aux->cod);
            printf("\n");
            printf("NAME: %s", aux->name);
            printf("\nCODE: %d", aux->cod);
            printf("\nValue: %.2f", aux->value);
            printf("\n");
            // printf("--------------------------------------------------------\n\n", aux->cod);

            aux = aux->next;

        }
        printf(" ----- FIM\n");
    }
}
void clean(TLL *lst)
{
    TLL *aux;
    while (lst != NULL) {
        aux = lst;
        lst = lst->next;
        free(aux);
    }
    printf("CLEAR");
}
void insert_order(TLL **lst)
{
    TLL *new = (TLL*) malloc(sizeof(TLL));
    if(!new)exit(1);

    printf("\nEnter name: ");
    scanf("%s", &new->name);
    printf("Enter code: ");
    scanf("%d", &new->cod);
    printf("Enter value: ");
    scanf("%f", &new->value);
    
    // se vazio
    if(empity(*lst) || new->cod < (*lst)->cod)
    {
        new->next = *lst;
        *lst = new;

    }else{
        TLL *aux = *lst;

        while (aux->next != NULL && aux->next->cod <= new->cod)
        {
            aux = aux->next;            
        }
        new->next = aux->next;
        aux->next = new;
        if (new->next == NULL) {
            new->next = NULL;
        }
    }
}

// void insert_ordered_2(TLL *lst, int cod, char name[], float value)
// {
//     TLL *new_node = (TLL*) malloc(sizeof(TLL));
//     if (!new_node) exit(1);
    
//     new_node->cod = cod;
//     strcpy(new_node->name, name);
//     new_node->value = value;
//     new_node->next = NULL;

//     if (lst == NULL || cod < lst->cod) {
//         new_node->next = lst;
//         lst = new_node;
//     }
//     else {
//         TLL *current = lst;
//         while (current->next != NULL && current->next->cod <= cod) {
//             current = current->next;
//         }
//         new_node->next = current->next;
//         current->next = new_node;
//     }
// }







