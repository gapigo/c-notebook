// A partir do código desenvolvido no programa acima, escreva um programa que
// calcula o número de dias entre duas datas quaisquer. Considerando a existência
// de anos bissextos.

#include <stdio.h>

int ehValida(int dia, int mes, int ano) {
    int dia_max;

    if (ano < 1) return 0;
    if (mes < 1 || mes > 12) return 0;
    if(dia < 1) return 0;

    if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12) dia_max = 31;
    else if(mes==4||mes==6||mes==9||mes==11) dia_max = 30;
    else {
        if (ano % 400 == 0)
            dia_max = 29;
        else if (ano % 100 == 0)
            dia_max = 28;
        else if (ano % 4 == 0)
            dia_max = 29;
        else
            dia_max = 28;
    }
    if (dia > dia_max) return 0;
    
    return 1;
}

int ehBissexto(int ano){
    if (ano % 400 == 0)
        return 1;
    if (ano % 100 == 0)
        return 0;
    if (ano % 4 == 0)
        return 1;

    return 0;
}

int transformarDataEmDias(int dia, int mes, int ano) {
    int diasFev;
    if (ehBissexto(ano))
        diasFev = 29;
    else
        diasFev = 28;
    int vetor[] = {31, diasFev, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    printf("\n\nDATA %d/%d \n", dia, mes);
    int dias = 0;
    for(int i=0; i+1<mes; i++) {
        dias += vetor[i];
        printf("Mês %d: ", i+1);
        printf("%d\n", vetor[i]);
    }
    dias += dia;

    return dias;
}

int diasEntreDatasMesmoAno(int dia, int mes, int dia2, int mes2, int ano) {
    // PRIMEIRA DATA É A MAIOR
    // SEGUNDA DATA É A MENOR
    if (mes == mes2) {
        return dia - dia2;
    }
    return transformarDataEmDias(dia, mes, ano) - transformarDataEmDias(dia2, mes2, ano);


}


int main() {
    int maior_ano = 2008;
    int menor_ano = 2005;
    int quantidade = maior_ano - menor_ano - 1;
    int vetor[quantidade];
    int ano_atual = menor_ano + 1;

    for(int i = 0; i < quantidade; i++) {
        vetor[i] = ano_atual;
        ano_atual++;
    }
    for(int i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }
}