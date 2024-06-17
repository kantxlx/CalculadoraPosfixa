# Avaliador de Expressões em Notação Pós-Fixada e Pré-Fixada

Este projeto é um avaliador de expressões matemáticas em notação pós-fixada e pré-fixada. O código é escrito em linguagem C e utiliza uma pilha para avaliar as expressões e converter entre diferentes notações.

## Funcionalidades

- Avalia expressões matemáticas em notação pós-fixada.
- Converte expressões de notação pós-fixada para notação infixada.
- Converte expressões de notação pós-fixada para notação prefixada.
- Suporta operações básicas:
  - Soma
  - Subtração
  - Multiplicação
  - Divisão
  - Potência
  - Raiz quadrada
  - Seno
  - Cosseno
  - Tangente
  - Logaritmo de base 10
- Aceita números decimais.
- Verifica se a pilha está vazia ou cheia.
- Verifica se há divisão por zero.
- Verifica se há operadores inválidos.

## Como usar

Para usar o avaliador de expressões em notação pós-fixada e pré-fixada, siga os seguintes passos:

1. Crie os arquivos `calculadora.h`, `calculadora.c` e `main.c` com os respectivos códigos fornecidos.
2. Compile o código:
    ```sh
    gcc -o calculadora calculadora.c main.c -lm
    ```
3. Execute o programa:
    ```sh
    ./calculadora
    ```
4. Digite a expressão pós-fixada e pressione Enter.
5. O programa exibirá o resultado da expressão e as conversões para notação infixada e prefixada.

## Exemplos

Se você digitar a expressão `3 4 + 5 *`, o programa exibirá:
- Resultado: `35`
- Notação Infixada: `(3 + 4) * 5`
- Notação Prefixada: `* + 3 4 5`

## Observações

- O código assume que a expressão pós-fixada é válida.
- Você pode adicionar outros operadores e funções matemáticas ao código conforme necessário.
- O código não faz validação de entrada para garantir que a expressão seja válida.
- Cada número ou operador deve ser separado por um espaço!

## Créditos

Este projeto foi desenvolvido por Cauã Assunção, Brenda Leal dos Santos Campos e Cássio da Silva Araújo Junior como parte de um trabalho de estrutura de dados. Se você tiver alguma dúvida ou precisar de mais ajuda, basta perguntar.
