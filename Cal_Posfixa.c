#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Definição da estrutura da pilha
typedef struct {
    double dados[100]; // array para armazenar os dados
    int topo; // índice do topo da pilha
} Pilha;

// Inicializa a pilha
void initPilha(Pilha *p) {
    p->topo = -1; // inicializa o topo da pilha como -1
}

// Verifica se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == -1; // retorna 1 se a pilha estiver vazia, 0 caso contrário
}

// Verifica se a pilha está cheia
int cheia(Pilha *p) {
    return p->topo == 99; // retorna 1 se a pilha estiver cheia, 0 caso contrário
}

// Empilha um elemento
void empilha(Pilha *p, double valor) {
    if (cheia(p)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    p->topo++; // incrementa o topo da pilha
    p->dados[p->topo] = valor; // armazena o valor no topo da pilha
}

// Desempilha um elemento
double desempilha(Pilha *p) {
    if (vazia(p)) {
        printf("Erro: Pilha vazia.\n");
        return 0;
    }
    double valor = p->dados[p->topo]; // recupera o valor do topo da pilha
    p->topo--; // decrementa o topo da pilha
    return valor;
}

// Avalia a expressão em notação pós-fixada
double avaliaExpressao(char *expressao) {
    Pilha p;
    initPilha(&p); // inicializa a pilha

    char *token = strtok(expressao, " "); // divide a expressão em tokens separados por espaço
    while (token!= NULL) {
        if (isdigit(token[0])) {
            empilha(&p, atof(token)); // empilha o valor numérico
        } else {
            if (strlen(token) == 1) { // operação binária
                double numero2 = desempilha(&p); // desempilha o segundo operando
                double numero1 = desempilha(&p); // desempilha o primeiro operando
                switch (token[0]) {
                    case '+':
                        empilha(&p, numero1 + numero2); // soma
                        break;
                    case '-':
                        empilha(&p, numero1 - numero2); // subtração
                        break;
                    case '*':
                        empilha(&p, numero1 * numero2); // multiplicação
                        break;
                    case '/':
                        if (numero2 == 0) {
                            printf("Erro: Divisão por zero.\n");
                            return 0;
                        }
                        empilha(&p, numero1 / numero2); // divisão
                        break;
                    case '^':
                        empilha(&p, pow(numero1, numero2)); // potência
                        break;
                    default:
                        printf("Erro: Operador inválido.\n");
                        return 0;
                }
            } else { // operação unária
                double numero = desempilha(&p); // desempilha o operando
                switch (token[0]) {
                    case 'l':
                        empilha(&p, log10(numero)); // logaritmo
                        break;
                    case 's':
                        empilha(&p, sin(numero * M_PI / 180)); // seno
                        break;
                    case 'c':
                        empilha(&p, cos(numero * M_PI / 180)); // cosseno
                        break;
                    case 't':
                        empilha(&p, tan(numero * M_PI / 180)); // tangente
                        break;
                    case 'r':
                        empilha(&p, sqrt(numero)); // raiz quadrada
                        break;
                    default:
                        printf("Erro: Operador inválido.\n");
                        return 0;
                }
            }
        }
        token = strtok(NULL, " "); // próximo token
    }

    return desempilha(&p); // retorna o resultado da expressão
}

int main() {
    char expressao[100];

    printf("Digite a expressão em notação Pós-fixada: ");
    fgets(expressao, sizeof(expressao), stdin);
    expressao[strcspn(expressao, "\n")] = 0; // remove o caractere de quebra de linha

    double resultado = avaliaExpressao(expressao);

    printf("Resultado: %.2lf\n", resultado);

    return 0;
}
