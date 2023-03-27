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
void insert_start(TLL **lst);
void print(TLL *lst);
void clean(TLL *lst);



int main()
{
    TLL *lst;

    init(lst);
    print(lst);
    insert_start(&lst);
    insert_start(&lst);
    // insert_ordered(lst);
    // insert_ordered(lst);
    // insert_ordered(lst);
    print(lst);
   
    printf("\nNumber of nodes: %d\n", count_node(lst));


    clean(lst);
    print(lst);

    free(lst);
    return 0;
}


void init(TLL *lst)
{
    lst = NULL;
}

int empity(TLL *lst)
{
    if(!lst)return 1;
    return 0;
}

int count_node(TLL *lst)
{
   int count = 0 ;
   TLL *aux = lst;

   if(empity(lst))
   {
        return count;       
   }else{
        while(aux->next != NULL)
        {
            count++;
            aux = aux->next;
        }
   }
   return count; 
}


void print(TLL *lst)
{
    if(empity(lst)){
        printf("-> NULL\n");
    }else{

        TLL *aux = lst; 
        while(aux)
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
    TLL *nextNo, *currNo = lst;

    while( currNo != NULL)
    {
        nextNo = currNo->next;
        free(currNo);
        currNo = nextNo;
    }

    init(lst);
    printf("\nCLEAR\n");
}


void insert_start(TLL **lst)
{
    TLL *new = (TLL*) malloc(sizeof(TLL));
    if(!new)exit(1);

    printf("\nEnter name: ");
    scanf("%s", new->name);
    // gets(new->name);
    printf("Enter code: ");
    scanf("%d", &new->cod);
    printf("Enter value: ");
    scanf("%f", &new->value);

    new->next = *lst;
    *lst = new;
    
}

