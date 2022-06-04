// EX: Escreva um programa que solicita um número inteiro ao usuário e exibe na tela
// a sequência de todos os números primos inferiores a esse número

#include <stdio.h>
#include <locale.h>

int ehPrimo(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i=2; i < num; i++){
        if (num%i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int numero;
    setlocale(LC_ALL, "Portuguese");
    printf("Informe um número: ");
    scanf("%d", &numero);

    for(int i=0; i < numero; i++) {
        if(ehPrimo(i)){
            printf("%d, ", i);
        }
    }
    return 0;
}
