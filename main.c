#include <stdio.h>
#include <string.h>
#include "calculadora.h"

int main() {
    char expressao[100];

    printf("Digite a expressao em notacao Posfixa: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = 0; // remove o caractere de quebra de linha

    // Faz uma cópia da expressão original para avaliação
    char expressaoCopia[100];
    strcpy(expressaoCopia, expressao);

    double resultado = getValor(expressaoCopia);
    printf("Resultado: %.2lf\n", resultado);

    // Re-processa a expressão original para converter para notação infixa
    getFormaInFixa(expressao);

    // Re-processa a expressão original para converter para notação prefixada
    getFormaPreFixa(expressao);

    return 0;
}
