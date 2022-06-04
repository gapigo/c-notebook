// Escreva um programa que, ao digitar uma data com dia do mês, número do mês
// e ano, informa se é uma data válida. Considere a existência de anos bissextos.

#include <stdio.h>

int main() {
    int dia, mes, ano;
    printf("Insira uma data:\n");
    
    printf("Dia >> ");
    scanf("%d", &dia);

    printf("Mes >> ");
    scanf("%d", &mes);

    printf("Ano >> ");
    scanf("%d", &ano);

    

    int valido = 1;
    int dia_max;

    if (ano < 1) valido = 0;
    else {
        if (mes < 1 || mes > 12) valido = 0;
        else {
            if(dia < 1) valido = 0;
            else {
                if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)
                    dia_max = 31;
                else if(mes==4||mes==6||mes==9||mes==11)
                    dia_max = 30;
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
                if (dia > dia_max) valido = 0;
            }
        }
    }

    printf("%d/%d/%d é uma ", dia, mes, ano);
    if (valido) printf("data válida");
    else printf("não data válida");

}