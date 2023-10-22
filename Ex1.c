#include <stdio.h>
/* Cálculo da sequência de Fibonacci usando uma função recursiva */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main() {
    int n;
    printf("Digite um número inteiro para calcular o termo de Fibonacci: ");
    scanf("%d", &n);

    int resultado = fibonacci(n);
    printf("O termo de Fibonacci em %d é %d\n", n, resultado);

    return 0;
}
