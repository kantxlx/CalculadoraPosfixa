#ifndef CALCULADORA_H_INCLUDED
#define CALCULADORA_H_INCLUDED

// Definição da estrutura da pilha
typedef struct Pilha Pilha;
typedef struct PilhaStr PilhaStr;

// Declarações das funções
void initPilha(Pilha *p);
void initPilhaStr(PilhaStr *p);
int vazia(Pilha *p);
int vaziaStr(PilhaStr *p);
int cheia(Pilha *p);
int cheiaStr(PilhaStr *p);
void empilha(Pilha *p, double valor);
void empilhaStr(PilhaStr *p, char *valor);
double desempilha(Pilha *p);
char* desempilhaStr(PilhaStr *p);
double avaliaExpressao(char *expressao);
void posfixaParaInfixa(char *expressao);
void posfixaParaPrefixa(char *expressao);

#endif // CALCULADORA_H_INCLUDED
