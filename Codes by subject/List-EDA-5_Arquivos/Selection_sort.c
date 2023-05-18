#include <stdio.h>
#include <stdlib.h>

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

void ss_arq(char *arq){
    FILE *fp = fopen(arq, "rb+");
    if(!fp)exit(1);

    int r1, r2, elem_i, elem_menor, elem_j, i = 0, j, menor;
    while(1){
        r1 = fread(&elem_i, sizeof(int), 1, fp);
        if(r1 != 1){
            fclose(fp);
            return;
        }
        elem_menor = elem_i;
        menor = i;
        i =+ sizeof(int);
        j = i + sizeof(int);
    }
}
int main(int argc, char const *argv[])
{
    
    
    return 0;
}
