#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Classificacao interna, externa
*/

// ETAPA 1 - Geracao das particoes ( apartir de um arq n ordenado )
/*
- Class. interna
-- Leitura de M reg
-- Class. desse reg ( bubble, selecion ,quick, heapsort ) TODOS COM MESMO TAMANHO EXC O ULTIMO TLVZ Q PODE SER MENOR Q OS DEMAIS 
-- Gravacao desses reg
- Selecao com substituicao
- Selecao Natural
*/
// ETAPA 2 - Intercalacao ( Gerando o  arq ordenado )

//
void ss(int *vet, int n){
    if(n <= 1)return;
    int i;
    for(i = 0; i < n; i++){
        int menor = i, j;
        for(j = i+1; j < n; j++){
            if(vet[menor] > vet [j])menor = j;
            if(menor != i){
                int tmp = vet[i];
                vet[i] = vet[menor];
                vet[menor] = tmp;
            }
        }
    }
}

int ci(char *arq, char *parte, int tamMP){
    FILE *fp = fopen(arq, "r");
    if(!fp) exit(1);

    int vet[tamMP], i, resp = 0;

    while(1){
        i = 0, resp++;
        int r = fscanf(fp, "%d", &vet[i]);
        while((r == 1) && ( i < tamMP)){
            i++;
            r = fscanf(fp, "%d", &vet[i]);
        }
        if((i != 0) && (r != 1))break;
        ss(vet , i);

        char nome_patrt[50], aux[5];
        
        strcpy(nome_patrt, parte);
        sprintf(aux, "%d_", resp);
        strcat(nome_patrt, aux);
        strcat(nome_patrt, arq);

        FILE *out = fopen(nome_patrt, "w");
        if(!out) exit(1);
        
        for(int j = 0; j < i; j++)fprintf(out, "%d\n", vet[j]);

        fclose(out);
    }
    fclose(fp);
    return resp;    
}
int main(int argc, char const *argv[])
{
    printf("Particoes - %d", ci("texto.txt", "ci",3));
    
    return 0;
}
