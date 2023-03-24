
/*
Foi feita uma estatística em 20 estados brasileiros para coletar dados sobre acidentes de
trânsito. Foram informados dados como: a sigla do estado, o número de veículos, e a quantidade de
acidentes. Faça um programa que calcule e mostre:

•a sigla do estado que possui maior número de carros;

•considerando o número de acidentes e o número de carros que circulam no estado, informar o estado com menor índice de acidentes de trânsito;

•o número total de acidentes de trânsito computado.

*/
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define N 27
typedef struct statistics
{
    char state[3];
    int vehicles, incident; 
}Sttcs;


int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "Portuguese");

    Sttcs *db = (Sttcs*) malloc(N * sizeof(Sttcs));
    if(!db) exit(1);

    int highest_vehicles = 0, sum_incidents = 0;
    float num_incidents = 0, tmp_num_incidents = 0;
    char highest_vehicles_state[3], highest_incident_state[3];

    char states[N][3] = {
        "AC", "AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS",
        "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
        "SP", "SE", "TO"
    };

    for (int i = 0; i < N; i++){
        strcpy(db[i].state, states[i]);

        printf("\nEnter %s information -------------\n", states[i]);
        printf("Enter vehicles number: ");
        scanf("%d", &db[i].vehicles);
        printf("Enter vehicles incidents  number: ");
        scanf("%d", &db[i].incident);

        // •a sigla do estado que possui maior número de carros;
        if( highest_vehicles < db[i].vehicles)
        {
            highest_vehicles = db[i].vehicles;
            strcpy(highest_vehicles_state, db[i].state);

        }


        // •considerando o número de acidentes e o número de carros que circulam no estado, informar o estado com menor índice de acidentes de trânsito;
        num_incidents =  (float)db[i].vehicles / (float)db[i].incident;
        /* printf("\nTotal number of incidents: %.2f", num_incidents); */

        if( tmp_num_incidents < num_incidents)
        {
            strcpy(highest_incident_state, db[i].state);
            
        }
        tmp_num_incidents = num_incidents;

        // •o número total de acidentes de trânsito computado.

        sum_incidents += db[i].incident;

    }
    printf("\nstate with the largest number of vehicles: %s", highest_vehicles_state);
    printf("\nstate with the largest number of incidents: %s", highest_incident_state);
    printf("\nTotal number of incidents: %d", sum_incidents);
    printf("\n");

    free(db);

    return 0;
}


/*
, "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS",
        "MG", "PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC",
        "SP", "SE", "TO"
*/