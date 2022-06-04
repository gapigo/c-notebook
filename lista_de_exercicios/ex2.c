// Escreva um programa que gera a sequência de Fibonacci, e mostre que a razão
// entre um número da sequência e o seu antecessor, tende a aproximar-se do
// número áureo.

#include <stdio.h>

int main() {
    int quantidade = 10;
    int vetor[quantidade];

    // 0 1 1 2 3 5 8 13 21
    int antecessor;
    int atual;
    int antigo_atual;
    for(int i=0; i<quantidade; i++) {
        if(i == 0) {
            antecessor = 0;
            atual = 0;
        }
        else {
            if(i == 1) {
                antecessor = 0;
                atual = 1;
            } 
            else {
                antigo_atual = atual;
                atual += antecessor;
                antecessor = antigo_atual;
            }
        }
        vetor[i] = atual;
    }

    // for(int i=0; i<quantidade; i++) { 
    //     printf("%d ", vetor[i]);
    // }

    float razao;

    for(int i=2; i<quantidade; i++) { 
        razao = ((float) vetor[i] / vetor[i-1]);
        printf("%f ", razao);
    }
}