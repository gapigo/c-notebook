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

    int dias = 0;
    for(int i=0; i+1<mes; i++) {
        dias += vetor[i];
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
    int dia, mes, ano;
    int dia2, mes2, ano2;
    printf("Insira uma data:\n");
    
    printf("Dia >> ");
    scanf("%d", &dia);
    printf("Mes >> ");
    scanf("%d", &mes);
    printf("Ano >> ");
    scanf("%d", &ano);

    
    if(!ehValida(dia, mes, ano)) {
        printf("%d/%d/%d não é uma data válida. ", dia, mes, ano);
        printf("Por favor, reinicie o programa e insira uma data válida");
        return 1;
    }

    printf("\n\nInsira uma nova data:\n");
    
    printf("Dia >> ");
    scanf("%d", &dia2);
    printf("Mes >> ");
    scanf("%d", &mes2);
    printf("Ano >> ");
    scanf("%d", &ano2);

    if(!ehValida(dia2, mes2, ano2)) {
        printf("%d/%d/%d não é uma data válida. ", dia2, mes2, ano2);
        printf("Por favor, reinicie o programa e insira uma data válida");
        return 1;
    }

    printf("Números de dias entre os anos: ");
    int resultado;
    int maior_dia, maior_mes, maior_ano;
    int menor_dia, menor_mes, menor_ano;
    if(ano == ano2){
        resultado = diasEntreDatasMesmoAno(dia, mes, dia2, mes2, ano);
        if (resultado < 0) {
            resultado = -resultado;
        }
        printf("%d", resultado);
    }
    else {
        if(ano2 < ano){
            menor_dia = dia2;
            menor_mes = mes2;
            menor_ano = ano2;
            maior_dia = dia;
            maior_mes = mes;
            maior_ano = ano;
        }
        else{
            menor_dia = dia;
            menor_mes = mes;
            menor_ano = ano;
            maior_dia = dia2;
            maior_mes = mes2;
            maior_ano = ano2;
        }

        int quantidade = maior_ano - menor_ano - 1;
        int vetor[quantidade];
        int ano_atual = menor_ano + 1;

        for(int i = 0; i < quantidade; i++) {
            vetor[i] = ano_atual;
            ano_atual++;
        }
        
        int dias = 0;
        for(int i = 0; i < quantidade; i++) {
            if(ehBissexto(vetor[i]))
                dias += 366;
            else
                dias += 365;
        }

        // INTERVALO MENOR ANO
        dias += diasEntreDatasMesmoAno(31, 12, menor_dia, menor_mes, menor_ano) + 1;

        // INTERVALO MAIOR ANO
        dias += diasEntreDatasMesmoAno(maior_dia, maior_mes, 1, 1, maior_ano);
        printf("%d", dias);
    } 
}
