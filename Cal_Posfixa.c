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
