/*
Implemente a função troque3() que faz uso da passagem por
referência com argumentos de ponteiro. Esta função deve
realizar a troca dos argumentos a e b passados por referência
(passa-se o endereço neste caso específico). Teste na main
se a sua função está funcionando corretamente.

    R : Utilizando de C ou C++, temos :

*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void troque3(int *X, int *Y);
int opcao();

int main()
{
    setlocale(LC_ALL, "");
    int a, b, *p, *q;
    printf("Insira o valor de a e b:\n");
    scanf("%d%d%*c", &a, &b);
    p = &a;
    q = &b;
    troque3(p, q);
    printf("O valor a: %d\nO valor b: %d", a, b);
    return 0;
}

void troque3(int *X, int *Y)
{
    int z = 0;
    if (opcao() == 1)
    {
        z = *X;
        *X = *Y;
        *Y = z;
    }
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
