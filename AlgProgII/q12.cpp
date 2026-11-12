/*

Crie um programa que use ponteiro para função a fim de
executar diferentes operações aritméticas baseado na
entrada do usuário.Crie quatro funções simples: adicione,
subtraia, multiplique e divida. Cada função deve receber
dois argumentos int e retornar um int como resultado. A
função divida deve tratar divisão por zero a fim de
prevenir erros em tempo de execução. Declare um ponteiro
para função que possa apontar para qualquer uma dessas
quatro funções. A assinatura do ponteiro deve casar com as
assinaturas das funções (ou seja, int (*ptr) (int, int)).

Entrada:
• Solicite ao usuário entrar com dois inteiros;
• Solicite ao usuário escolher uma operação (por exemplo,
  ’a’ para adicionar, ’s’ para subtrair, ’m’ para multiplicar e ’d’ para dividir).

Atribuir e chamar:
• Baseado na escolha do usuario, atribua o endereço da
  função correspondente para oponteiro para função;
• Chame a função escolhida usando ponteiro para função,
  passando os dois inteiros de entrada como argumentos;
• Imprima o resultado da operação.

    R: */

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void calculadora(int x, int y, int (*operacao)(int a, int b));
int adicao(int a, int b);
int subtracao(int a, int b);
int divisao(int a, int b);
int multiplicacao(int a, int b);
int opcoes();

int main()
{
    setlocale(LC_ALL, "");
    int op, X, Y;
    printf("Insira dois valores X e Y:\n");
    scanf("%d%d%*c", &X, &Y);
    op = opcoes();
    switch (op)
    {
    case 1:
        calculadora(X, Y, adicao);
        break;
    case 2:
        calculadora(X, Y, subtracao);
        break;
    case 3:
        calculadora(X, Y, multiplicacao);
        break;
    case 4:
        calculadora(X, Y, divisao);
        break;
    default:
        printf("Opção invalida!\n");
        break;
    }
    return 0;
}
int opcoes()
{
    char choice;
    printf("Escolha que tipo de operação deseja fazer:\nAdição(a)\nSubtração(s)\nMultiplicação(m)\nDivisão(d)\n");
    scanf("%c%*c", &choice);
    if (choice == 'a')
    {
        printf("\nEscolhido: ADIÇÃO!");
        return 1;
    }
    else if (choice == 's')
    {
        printf("\nEscolhido: SUBTRAÇÃO!");
        return 2;
    }
    else if (choice == 'm')
    {
        printf("\nEscolhido: MULTIPLICAÇÃO!");
        return 3;
    }
    else if (choice == 'd')
    {
        printf("\nEscolhido: DIVISAO!");
        return 4;
    }
    return 72;
}

void calculadora(int x, int y, int (*operacao)(int a, int b))
{
    printf("O Resultado é: %d", operacao(x, y));
}

int adicao(int a, int b)
{
    return a + b;
}
int subtracao(int a, int b)
{
    return a - b;
}
int multiplicacao(int a, int b)
{
    return a * b;
}
int divisao(int a, int b)
{
    if (b != 0)
        return a / b;
    else
        printf("ERRO! DIVISÃO POR 0!");
    exit(1);
}
