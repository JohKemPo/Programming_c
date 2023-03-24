/**
 * @file Exe5.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */
/*
Foi realizada uma pesquisa sobre as características físicas de 50 habitantes de uma certa  região.
De cada habitante foram coletados os seguintes dados: altura, idade e cor dos olhos (A azuis,
V-verdes ou C-castanhos). Faça um programa que leia estes dados e que calcule e mostre: 

•a média das idades;
•a maior e a menor altura;
•a quantidade de pessoas de olhos castanhos que possuam idade acima da média  calculada.
*/

#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct Database
{
    float height;
    int age;
    char colorEyes;

}Data;

int main(int argc, char const *argv[])
{
    Data *db = (Data*) malloc(N * sizeof(Data));
    if(!db)exit(1);

    float average = 0, greater_height = 0, shorter_height = 0;
    int amount, count = 0;
    
    for ( int i = 0; i < N; i++)
    {
        printf("Enter height: ");
        scanf("%f", &db[i].height);
        printf("Enter age: ");
        scanf("%d", &db[i].age);
        printf("Enter color eyes: ");
        scanf("%s", &db[i].colorEyes);

        average += db[i].age;
        if(db[i].height > greater_height)
        {
            greater_height = db[i].height;
        }
        if(db[i].height < shorter_height)
        {
            shorter_height = db[i].height;
        }
        printf("\n");
    }

    // •a média das idades;
    average /= N;
    printf("Average - %.f\n", average);

      

    // •a maior e a menor altura;
    printf("Height - %.2f \nShorter - %.2f\n", greater_height, shorter_height);

    // •a quantidade de pessoas de olhos castanhos que possuam idade acima da média  calculada.
    for ( int i = 0; i < N; i++)
    {
        if(db[i].colorEyes == 'C' && db[i].age > average)count++;
    }  
    printf("number of brown-eyed people older than average: %d", count);

    free(db);
    return 0;
}
