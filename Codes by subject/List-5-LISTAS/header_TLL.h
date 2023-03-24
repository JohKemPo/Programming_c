#ifndef HEADER_TLL_H
#define HEADER_TLL_H

typedef struct Type_linked_list
{
    int info;
    struct Type_linked_list *next;
}TLL;


void init(TLL *lst);
int empity(TLL *lst);
int count_node(TLL *lst);
void insert_start(TLL *lst);
void print(TLL *lst);
void clean(TLL *lst);

#endif