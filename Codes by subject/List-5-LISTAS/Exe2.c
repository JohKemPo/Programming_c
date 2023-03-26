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
// void insert_ordered(TLL *lst);
void insert_start(TLL *lst);
void print(TLL *lst);
void clean(TLL *lst);


int main(int argc, char const *argv[])
{
    TLL *lst = (TLL*) malloc(sizeof(TLL));
    if(!lst)exit(1);

    init(lst);
    print(lst);
    insert_start(lst);
    insert_start(lst);
    insert_start(lst);
    // insert_ordered(lst);
    // insert_ordered(lst);
    print(lst);
   
    printf("\nNumber of nodes: %d\n", count_node(lst));


    clean(lst);
    print(lst);

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

void print(TLL *lst)
{
    if(empity(lst)){
        printf("-> NULL\n");
    }else{

        TLL *aux = lst->next; 
        while(aux != NULL)
        {
            printf("\n");
            printf("NAME: %s", aux->name);
            printf("\nCODE: %d", aux->cod);
            printf("\nValue: %.2f", aux->value);
            printf("\n");
    
            aux = aux->next;
        }
        printf(" ----- FIM\n");
    }
}

void clean(TLL *lst)
{
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

// void insert_ordered(TLL *lst)
// {
//     TLL *new = (TLL*) malloc(sizeof(TLL));
//     if(!new)exit(1);

//     printf("\nEnter name: ");
//     scanf("%s", &new->name);
//     printf("Enter code: ");
//     scanf("%d", &new->cod);
//     printf("Enter value: ");
//     scanf("%f", &new->value);

//     if(empity(lst))
//     {
//         printf("Entrou no if null");
//         new->next = lst->next;
//         lst->next = new;
//     }else{
//         TLL *prev = NULL, *curr = lst->next;
//         while (curr->next != NULL && curr->cod < new->cod)
//         {
//             printf("\nlaço para ultimo");
//             prev = curr;
//             curr = curr->next;
//         }

//         if(prev == NULL)// se o primeiro item é maior que o novo
//         {
//             printf("\nPrimeiro no é menor");
//             new->next = lst;
//             lst->next = new;

//         } else {
//             printf("\nInsere na posição correta");

//             new->next = curr;
//             prev->next = new;
//         }        
//     }
// }

void insert_start(TLL *lst)
{

    TLL *new = (TLL*) malloc(sizeof(TLL));
    if(!new)exit(1);

    printf("\nEnter name: ");
    scanf("%s", &new->name);
    printf("Enter code: ");
    scanf("%d", &new->cod);
    printf("Enter value: ");
    scanf("%f", &new->value);

    new->next = lst->next;
    lst->next = new;
}

