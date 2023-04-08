/**
 * @file Exe01.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-04-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */

/*
Escreva um programa que implemente a Peneira de Eratosthenes. Você deve ler o valor n e
mostrar todos os números primos encontrados.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Portuguese");

    int n;
    printf("Digite um número inteiro n: ");
    scanf("%d", &n);
    
    // criando um vetor para armazenar se um número é primo ou não
    int *primo = malloc((n+1) * sizeof(int));
    
    // inicializando o vetor com todos os valores iguais a true (assumindo que todos os números são primos)
    for (int i = 2; i <= n; i++) {
        primo[i] = 1;
    }
    
    // aplicando a peneira
    for (int i = 2; i*i <= n; i++) {
        if (primo[i]) {
            for (int j = i*i; j <= n; j += i) {
                primo[j] = 0;
            }
        }
    }
    
    // mostrando os números primos encontrados
    printf("Os números primos entre 2 e %d são:\n", n);
    for (int i = 2; i <= n; i++) {
        if (primo[i]) {
            printf("%d ", i);
        }
        
    }
    printf("\n");
    
    free(primo);
    return 0;
}
