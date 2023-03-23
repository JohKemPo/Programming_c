/*
A prefeitura de uma cidade fez uma pesquisa com seus habitantes, coletando dados sobre salário,
idade e número de filhos. Faça um programa que leia os dados de 20 pessoas, e que calcule e
mostre:

•a média de salário da população;
•a média do número de filhos;
•o maior salário.
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define N 4

typedef struct Banco_de_dados
{
    int age, num_children;
    float salary;
}BDados;



void print()
{

}

float average_salary(float average, int n)
{   
    average = average/n;
    return average;
}

float average_children(float average, int n)
{   
    average = average/n;
    return average;
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    BDados *search = (BDados*) malloc(N * sizeof(BDados));
    if(!search)exit(1);
    float average_salary_city = 0, highest_salary = 0;
    int average_children_city;


    for( int i = 1; i <= N; i++)
    {
        printf("\nEnter %d interview  information -------------\n", i);
        printf("Enter %d interview  age: ", i);
        scanf("%d", &search[i].age);
        printf("Enter %d interview  number of children: ", i);
        scanf("%d", &search[i].num_children);
        printf("Enter %d interview  salary: ", i);
        scanf("%f", &search[i].salary);

        average_salary_city += search[i].salary;
        average_children_city += search[i].num_children;

        if (search[i].salary > highest_salary)
        {
            highest_salary = search[i].salary;
        }
    }   

    // •a média de salário da população;
    printf("Average salary of city: $ %.2f", average_salary(average_salary_city, N));

    // •a média do número de filhos;
    printf("\nAverage children of city: $ %.f", average_children(average_children_city, N));

    // •o maior salário.
    printf("\nAverage salary of city: $ %.2f", highest_salary);

    
    return 0;
}
