/*
Escreva um programa que recebe três variáveis do tipo int (a,
b, c) e rotacione os valores de forma que o valor de a vai
para b, o valor de b para c e o valor de c para a. Utilize
chamadas a função troque desenvolvida anteriormente (escolha
uma das duas implementações da função que funciona: troque1
ou troque2).

    R:Usando C ou C++, temos
*/

#include <stdio.h>
#include <stdlib.h>

void troque3(int *X, int *Y);
int opcao();

int main()
{

    int a, b, c, *p, *q, *r;
    printf("Insira o valor de a, b e c:\n");
    scanf("%d%d%d%*c", &a, &b, &c);
    p = &a;
    q = &b;
    r = &c;
    if (opcao())
    {
        troque3(q, r);
        troque3(p, q);
    }

    printf("O valor a: %d\nO valor b: %d\nO valor c: %d\n", a, b, c);
    return 0;
}

void troque3(int *X, int *Y)
{
    int z = 0;
    z = *X;
    *X = *Y;
    *Y = z;
}

int opcao()
{
    char answer;
    printf("Deseja realizar troca(Y/N): ");
    scanf("%c%*c", &answer);
    if (answer == 'Y')
    {
        return 1;
    }
    else
        return 0;
}