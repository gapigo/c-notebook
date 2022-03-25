#include <stdio.h>

/*
A copa do undo e as olimpiadas ocorrem a cada 4 anos. Sendo que normalmente as olimpiadas
acontecem nos anos que sao multiplos de 4. ja a copa do mundo e realizada nosnos anos pares qwue 
nao sao multiplos de 4. Escreva um programa que solicita o ano ao usuario, e informa se
e um ano de olimpiadas, copa do mundo, ou nenhum dos dois

Dica:
operador modulo (resto): %
operadores logicos
&& e
|| ou
! negacao

operadores relacionais
== testa igualdade
!= testa a diferenca */

int main() {
    int ano;
    printf("Entre com um ano (yyyy): ");
    scanf("%d", &ano);

    /*
    if (ano % 2 != 0)
        printf("%d nao tem evento nenhum", ano);
    else
        if (ano % 4 == 0)
            printf("Este eh ano de olimpiada");
        else
            printf("Este eh ano de copa do mundo");
    printf("\n");  */
    
    if (ano % 2 != 0) printf("%d nao tem evento nenhum", ano);
    if (ano % 4 == 0) printf("%d eh ano de olimpiada", ano);
    if (ano % 2 == 0 && ano % 4 != 0) printf("%d eh ano de copa do mundo", ano);
    printf("\n");
    return 0;
}
