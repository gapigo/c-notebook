#include <stdio.h>

int main(){
    float operando1, operando2;
    float resultado;
    char operacao;

    printf("\nOperando 1: ");
    scanf("%f", &operando1);

    printf("\n Operacao (+, -, *, x, :, /): ");
    scanf(" %c", &operacao);

    printf("\nOperando 2: ");
    scanf("%f", &operando2);

    switch(operacao) {
        case '+':
            resultado = operando1;
            break;
        case '-':
            resultado = operando1 - operando2;
            break;
        case '*':
        case 'x':
            resultado = operando1 * operando2;
            break;
        case '/':
        case ':':
            resultado = operando1 / operando2;
            break;
        default:
            printf("\nOperacao invalida!");
            return 1;
    }
    printf("\n%.2f %c %.2f = %.2f\n", operando1, operacao, operando2, resultado);

    return 0;
}