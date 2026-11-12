/*
Escreva um programa que solicite ao usuário o número de notas a serem fornecidas e
aloque dinamicamente um vetor com a dimensão especificada para armazenar as entradas.
Solicite as notas e chame uma função que retorne a média aritmética das notas. Após
imprimir a média o programa deve liberar a memória dinâmica que fora alocada.

Se você já viu o modificador const, o utilize no parâmetro que recebe as notas, a fim de
garantir que o seu conteúdo não será alterado


R:      */

#include <stdio.h>
#include <stdlib.h>
double media(const double *VETOR, int TAMANHO);

int main()
{
    int alunos;
    double num;
    double *notas;
    printf("Insira quantidade de notas a serem lidas: ");
    scanf("%d%*c", &alunos);
    notas = (double *)malloc(alunos * sizeof(int));
    for (int i = 0; i < alunos; i++)
    {
        scanf("%lf", &num);
        notas[i] = num;
    }
    double med = media(notas, alunos);
    printf("A media da turma foi: %.2lf", med);
    free(notas);
    return 0;
}

double media(const double *VETOR, int TAMANHO)
{
    double soma = 0;
    for (int i = 0; i < TAMANHO; i++)
    {
        soma += VETOR[i];
    }
    return soma / TAMANHO;
}
