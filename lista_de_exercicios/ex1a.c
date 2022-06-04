// EX: Escreva um programa que solicita um número inteiro ao usuário e exibe na tela
// a sequência de todos os números primos inferiores a esse número

#include <stdio.h>
#include <locale.h>

int main() {
    int numero = 25;
    setlocale(LC_ALL, "Portuguese");
    printf("Informe um número: ");
    scanf("%d", &numero);

    int ehPrimo;
    for(int i=0; i < numero; i++) {
        if (i > 1) {
            ehPrimo = 1;

            for(int j=2; j < i; j++) {
                if (i % j == 0) {
                    ehPrimo = 0;
                }
            }
            if (ehPrimo) {
                printf("%d, ", i);
            }
        }
    }
    return 0;
}