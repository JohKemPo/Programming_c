/**
 * @file Exe6.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2023-03-24
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdio.h>

struct dma {
    int dia;
    int mes;
    int ano;
};

int dias_entre_datas(struct dma data1, struct dma data2) {
    // número de dias em cada mês
    int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dias = 0;

    // calcula a diferença entre os anos
    int dif_anos = data2.ano - data1.ano;

    // calcula o número de dias em anos completos
    dias = dif_anos * 365;

    // corrige o número de dias em anos bissextos
    for (int i = data1.ano; i < data2.ano; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
            dias++;
        }
    }

    // calcula o número de dias nos meses
    for (int i = 0; i < data1.mes - 1; i++) {
        dias -= dias_mes[i];
    }
    for (int i = 0; i < data2.mes - 1; i++) {
        dias += dias_mes[i];
    }

    // corrige o número de dias em anos bissextos
    if ((data1.ano % 4 == 0 && data1.ano % 100 != 0) || data1.ano % 400 == 0) {
        if (data1.mes <= 2) {
            dias++;
        }
    }
    if ((data2.ano % 4 == 0 && data2.ano % 100 != 0) || data2.ano % 400 == 0) {
        if (data2.mes > 2 || (data2.mes == 2 && data2.dia == 29)) {
            dias++;
        }
    }

    // calcula o número de dias nos dias
    dias += data2.dia - data1.dia;

    return dias;
}

int main() {
    // exemplo de uso da função
    struct dma data1 = {20, 3, 2022};
    struct dma data2 = {28, 3, 2023};
    int dif_dias = dias_entre_datas(data1, data2);
    printf("Dias entre %02d/%02d/%04d e %02d/%02d/%04d: %d\n", data1.dia, data1.mes, data1.ano, data2.dia, data2.mes, data2.ano, dif_dias);
    return 0;
}
