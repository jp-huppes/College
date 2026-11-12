/*
O seguinte trecho de código calcula a soma dos n primeiros números naturais.

int main(){
    int n, soma;

    soma = 0;

    scanf("%d", &n);

    while(n > 0)
    {
        soma = soma + n;
        n −= 1;
    }

    printf("A soma dos %d primeiros numeros e : %d", n, soma);

    return 0;
}

Reescreva o código utilizando duas funções. Uma função deve calcular a soma utilizando
passagem por referência e a segunda função exibe o resultado utilizando passagem por
valor.

    R: Usando C ou C++, temos:

*/

#include <stdio.h>

void soma(int *sum, int *num);
void imprimir(int X);

int main()
{
    int n, s, *p, *q;
    s = 0;
    scanf("%d%*c", &n);
    p = &s;
    q = &n;
    soma(p, q);
    imprimir(s);
}
void soma(int *sum, int *num)
{
    while (*num > 0)
    {
        *sum += *num;
        *num -= 1;
    }
}
void imprimir(int X)
{
    printf("A soma eh igual a : %d", X);
}
