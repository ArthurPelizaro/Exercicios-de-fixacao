#include <stdio.h>
/* Simulação de uma calculadora */
float adicao(float a, float b) {
    return a + b;
}

float subtracao(float a, float b) {
    return a - b;
}

float multiplicacao(float a, float b) {
    return a * b;
}

float divisao(float a, float b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Erro: divisão por zero!\n");
        return 0.0;
    }
}

int main() {
    float num1, num2;
    char operacao;

    printf("Digite um número: ");
    scanf("%f", &num1);
    printf("Digite uma operação (+, -, *, /): ");
    scanf(" %c", &operacao);
    printf("Digite outro número: ");
    scanf("%f", &num2);

    float resultado;

    switch (operacao) {
        case '+':
            resultado = adicao(num1, num2);
            break;
        case '-':
            resultado = subtracao(num1, num2);
            break;
        case '*':
            resultado = multiplicacao(num1, num2);
            break;
        case '/':
            resultado = divisao(num1, num2);
            break;
        default:
            printf("Operação inválida!\n");
            return 1;
    }

    printf("Resultado: %.2f\n", resultado);

    return 0;
}
