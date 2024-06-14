# Avaliador de Expressões em Notação Pós-Fixa

Este projeto é um avaliador de expressões matemáticas em notação pós-fixada. O código é escrito em linguagem C e utiliza uma pilha para avaliar as expressões.

## Funcionalidades

- Avalia expressões matemáticas em notação pós-fixada
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
- Aceita números decimais
- Verifica se a pilha está vazia ou cheia
- Verifica se há divisão por zero
- Verifica se há operadores inválidos

## Como usar

Para usar o avaliador de expressões em notação pós-fixada, siga os seguintes passos:

1. Salve o código como `CalculadoraPosfixa.c`.
2. Compile o código:
    ```sh
    gcc CalculadoraPosfixa.c -o CalculadoraPosfixa -lm
    ```
3. Execute o programa:
    ```sh
    ./CalculadoraPosfixa
    ```
4. Digite a expressão pós-fixada e pressione Enter.
5. O programa exibirá o resultado da expressão.

## Exemplos

Se você digitar a expressão `3 4 + 5 *`, o programa exibirá o resultado `35`.

## Observações

- O código assume que a expressão pós-fixada é válida.
- Você pode adicionar outros operadores e funções matemáticas ao código conforme necessário.
- O código não faz validação de entrada para garantir que a expressão seja válida.
- A cade numero ou operador colocado de um espaço para separar!!!

## Créditos

Este projeto foi desenvolvido por Cauã Assunção, Brenda Leal dos Santos Campos e Cássio da Silva Araújo Junior como parte de um trabalho de esstrutura de dados. Se você tiver alguma dúvida ou precisar de mais ajuda, basta perguntar.
