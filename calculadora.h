#ifndef CALCULADORA_H
#define CALCULADORA_H

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
void initPilha(Pilha *p);

// Inicializa a pilha de strings
void initPilhaStr(PilhaStr *p);

// Verifica se a pilha está vazia
int vazia(Pilha *p);

// Verifica se a pilha de strings está vazia
int vaziaStr(PilhaStr *p);

// Verifica se a pilha está cheia
int cheia(Pilha *p);

// Verifica se a pilha de strings está cheia
int cheiaStr(PilhaStr *p);

// Empilha um elemento
void empilha(Pilha *p, double valor);

// Empilha um elemento na pilha de strings
void empilhaStr(PilhaStr *p, char *valor);

// Desempilha um elemento
double desempilha(Pilha *p);

// Desempilha um elemento da pilha de strings
char* desempilhaStr(PilhaStr *p);

// Avalia a expressão em notação pós-fixada
double avaliaExpressao(char *expressao);

// Converte uma expressão em notação pós-fixada para notação infixa
void posfixaParaInfixa(char *expressao);

// Converte uma expressão em notação pós-fixada para notação prefixada
void posfixaParaPrefixa(char *expressao);

#endif
