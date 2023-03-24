/*
Um funcionário recebe um salário fixo mais 6% de comissão sobre suas vendas. Faça um programa
que leia o salário de um funcionário, o valor total de suas vendas e apresente o seu salário final.
Considere N funcionários (use alocação dinâmica).
*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define N 3

typedef struct salary_count{
    float salary, sales, final_salary;
}Salaryc;

int main(int argc, char const *argv[])
{
    Salaryc *db = (Salaryc*) malloc(N * sizeof(Salaryc));
    if(!db)exit(1);

    for( int i = 0; i < N; i++)
    {
        printf("\nEnter %d information -------------\n", i+1);
        printf("Enter salary base: ");
        scanf("%f", &db[i].salary);
        printf("Enter sales: ");
        scanf("%f", &db[i].sales);
        fflush(stdin);
        
        db[i].final_salary = (db[i].sales)*0.06 + db[i].salary;
        printf("FINAL SALARY: %.2f", db[i].final_salary);
        printf("\n");
    }

    free(db);
    return 0;
}
