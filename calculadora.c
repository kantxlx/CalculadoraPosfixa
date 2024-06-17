#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

// Definição da estrutura da pilha
typedef struct {
    double dados[100]; // array para armazenar os dados
    int topo; // índice do topo da pilha
} Pilha;

typedef struct {
    char dados[100][100]; // array para armazenar os dados
    int topo; // índice do topo da pilha
} PilhaStr;

// Inicializa a pilha
void initPilha(Pilha *p) {
    p->topo = -1; // inicializa o topo da pilha como -1
}

// Inicializa a pilha de strings
void initPilhaStr(PilhaStr *p) {
    p->topo = -1; // inicializa o topo da pilha como -1
}

// Verifica se a pilha está vazia
int vazia(Pilha *p) {
    return p->topo == -1; // retorna 1 se a pilha estiver vazia, 0 caso contrário
}

// Verifica se a pilha de strings está vazia
int vaziaStr(PilhaStr *p) {
    return p->topo == -1; // retorna 1 se a pilha estiver vazia, 0 caso contrário
}

// Verifica se a pilha está cheia
int cheia(Pilha *p) {
    return p->topo == 99; // retorna 1 se a pilha estiver cheia, 0 caso contrário
}

// Verifica se a pilha de strings está cheia
int cheiaStr(PilhaStr *p) {
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

// Empilha um elemento na pilha de strings
void empilhaStr(PilhaStr *p, char *valor) {
    if (cheiaStr(p)) {
        printf("Erro: Pilha cheia.\n");
        return;
    }
    p->topo++; // incrementa o topo da pilha
    strcpy(p->dados[p->topo], valor); // armazena o valor no topo da pilha
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

// Desempilha um elemento da pilha de strings
char* desempilhaStr(PilhaStr *p) {
    if (vaziaStr(p)) {
        printf("Erro: Pilha vazia.\n");
        return "";
    }
    return p->dados[p->topo--]; // recupera o valor do topo da pilha e decrementa o topo
}

// Avalia a expressão em notação pós-fixada
double avaliaExpressao(char *expressao) {
    Pilha p;
    initPilha(&p); // inicializa a pilha

    char *token = strtok(expressao, " "); // divide a expressão em tokens separados por espaço
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilha(&p, atof(token)); // empilha o valor numérico
        } else {
            if (strcmp(token, "log") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "sqrt") == 0) {
                double numero = desempilha(&p); // desempilha o operando
                double pi = 3.14159265358979323846;
                if (strcmp(token, "log") == 0) {
                    empilha(&p, log10(numero)); // logaritmo
                } else if (strcmp(token, "sen") == 0) {
                    empilha(&p, sin(numero * pi / 180)); // seno
                } else if (strcmp(token, "cos") == 0) {
                    empilha(&p, cos(numero * pi / 180)); // cosseno
                } else if (strcmp(token, "tan") == 0) {
                    empilha(&p, tan(numero * pi / 180)); // tangente
                } else if (strcmp(token, "sqrt") == 0) {
                    empilha(&p, sqrt(numero)); // raiz quadrada
                }
            } else {
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
            }
        }
        token = strtok(NULL, " "); // próximo token
    }

    return desempilha(&p); // retorna o resultado da expressão
}

// Converte uma expressão em notação pós-fixada para notação infixa
void posfixaParaInfixa(char *expressao) {
    PilhaStr p;
    initPilhaStr(&p); // inicializa a pilha de strings

    char expressaoCopia[100];
    strcpy(expressaoCopia, expressao); // faz uma cópia da expressão

    char *token = strtok(expressaoCopia, " "); // divide a expressão em tokens separados por espaço
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
            empilhaStr(&p, token); // empilha o valor numérico
        } else {
            if (strcmp(token, "log") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "sqrt") == 0) {
                char operando[100];
                strcpy(operando, desempilhaStr(&p)); // desempilha o operando

                char novaExpr[100];
                snprintf(novaExpr, sizeof(novaExpr), "(%s %s)", token, operando); // combina operador unário e operando
                empilhaStr(&p, novaExpr); // empilha a nova expressão
            } else {
                char operando2[100];
                char operando1[100];
                strcpy(operando2, desempilhaStr(&p)); // desempilha o segundo operando
                strcpy(operando1, desempilhaStr(&p)); // desempilha o primeiro operando

                char novaExpr[100];
                snprintf(novaExpr, sizeof(novaExpr), "(%s %s %s)", operando1, token, operando2); // combina operador e operandos em notação infixa
                empilhaStr(&p, novaExpr); // empilha a nova expressão
            }
        }
        token = strtok(NULL, " "); // próximo token
    }

    printf("Expressão Infixa: %s\n", desempilhaStr(&p)); // exibe a expressão infixa
}

// Converte uma expressão em notação pós-fixada para notação prefixada
void posfixaParaPrefixa(char *expressao) {
    PilhaStr p;
    initPilhaStr(&p); // inicializa a pilha de strings

    char expressaoCopia[100];
    strcpy(expressaoCopia, expressao); // faz uma cópia da expressão

    char *token = strtok(expressaoCopia, " "); // divide a expressão em tokens separados por espaço
    while (token != NULL) {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            empilhaStr(&p, token); // empilha o valor numérico
        } else {
            if (strcmp(token, "log") == 0 || strcmp(token, "sen") == 0 || strcmp(token, "cos") == 0 || strcmp(token, "tan") == 0 || strcmp(token, "sqrt") == 0) {
                char operando[100];
                strcpy(operando, desempilhaStr(&p)); // desempilha o operando

                char novaExpr[100];
                snprintf(novaExpr, sizeof(novaExpr), "%s %s", token, operando); // combina operador unário e operando
                empilhaStr(&p, novaExpr); // empilha a nova expressão
            } else {
                char operando2[100];
                char operando1[100];
                strcpy(operando2, desempilhaStr(&p)); // desempilha o segundo operando
                strcpy(operando1, desempilhaStr(&p)); // desempilha o primeiro operando

                char novaExpr[100];
                snprintf(novaExpr, sizeof(novaExpr), "%s %s %s", token, operando1, operando2); // combina operador e operandos em notação prefixada
                empilhaStr(&p, novaExpr); // empilha a nova expressão
            }
        }
        token = strtok(NULL, " "); // próximo token
    }

    printf("Expressão Prefixa: %s\n", desempilhaStr(&p)); // exibe a expressão prefixada
}

