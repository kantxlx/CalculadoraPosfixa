#include <stdio.h>
#include <string.h>
#include "calculadora.h"

int main() {
    char expressao[100];

    printf("Digite a expressão em notação Pós-fixada: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = 0; // remove o caractere de quebra de linha

    // Faz uma cópia da expressão original para avaliação
    char expressaoCopia[100];
    strcpy(expressaoCopia, expressao);

    double resultado = avaliaExpressao(expressaoCopia);
    printf("Resultado: %.2lf\n", resultado);

    // Re-processa a expressão original para converter para notação infixa
    posfixaParaInfixa(expressao);

    // Re-processa a expressão original para converter para notação prefixada
    posfixaParaPrefixa(expressao);

    return 0;
}
