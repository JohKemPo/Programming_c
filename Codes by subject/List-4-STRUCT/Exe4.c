/**
 * @file Exe4.c
 * 
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
Faça um programa que leia as informações sobre as N ordens de serviço de um oficina mecânica. Os
seguintes dados serão lidos: número da OS, valor, tipo de serviço e nome do cliente. O programa
deve apresentar no final:

•a média de preço dos serviços prestados,
•os nomes dos clientes que pagaram por serviços acima da média calculada; 
•o nome do cliente que pagou pelo serviço mais caro.
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3

typedef struct OS_generate
{
    char name[40], type[40];
    int os_num;
    float value_os;
}OSG;

void print(OSG *os)
{
    printf("\n--------------------- OS INFORMATION ----------------------\n" );
    
    printf("\nName: %s          OS Number: %d           Type: %s", os->name, os->os_num, os->type);
    printf("\n                      Value: R$ %.2f                       ", os->value_os);
    printf("\n\n");
    printf("-----------------------------------------------------------");
    
}

void highest_value(OSG *os, float average)
{
    for(int i = 0; i < N; i++)
    {
        if(os[i].value_os > average)
        {
            printf("\nName: %s", os[i].name);
        }
    }
}
int main(int argc, char const *argv[])
{
    OSG *db = (OSG*) malloc(N * sizeof(OSG));
    if(!db)exit(1);
    float average = 0;

    for( int i = 0; i < N; i++)
    {

        setlocale(LC_ALL,"portuguese");

        printf("\nEnter OS information name %d or enter 'end' for finish. -------------\n", i+1);
        printf("Enter info: ");
        scanf("%s", &db[i].name);

        if(strcmp(db[i].name, "end") == 0)
        {
            break;
        }
        
        printf("Enter type of service: ");
        scanf("%s", &db[i].type);
        printf("Enter number of OS: ");
        scanf("%d", &db[i].os_num);

        // db[i].os_num = i + 1;

        printf("Enter value of OS: ");
        scanf("%f", &db[i].value_os);

        average += db[i].value_os;

        print(db);
        printf("\n");
        
    }
    // •a média de preço dos serviços prestados,
    printf("Average: %.2f", average/N);

    // •os nomes dos clientes que pagaram por serviços acima da média calculada; 
    highest_value(db, average);

    free(db);
    return 0;
}
