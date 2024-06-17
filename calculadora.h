#ifndef CALCULADORA_H
#define CALCULADORA_H

typedef struct {
    char posFixa[512];     // Expressão na forma pós-fixa, como 3 12 4 + *
    char inFixa[512];      // Expressão na forma infixa, como 3 * (12 + 4)
    char preFixa[512];     // Expressão na forma prefixa, como + * 3 12 4
    float valor;           // Valor numérico da expressão  
} Expressao;

char *getFormaInFixa(char *Str);    // Retorna a forma infixa de Str (pós-fixa)
char *getFormaPreFixa(char *Str);   // Retorna a forma prefixa de Str (pós-fixa)
float getValor(char *Str);          // Calcula o valor de Str (na forma pós-fixa)

#endif
