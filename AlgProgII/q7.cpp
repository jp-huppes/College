/*
Implemente a função troque2() que faz uso da passagem por
referência com argumentos de referência (específico de C++,
utilizando o operador de referência & a frente dos parâmetros).
Essa função deve realizar a troca dos argumentos a e b
passados por referência. Teste na main se a sua função está
funcionando corretamente.

    R: Utilizando do C++ temos:

*/

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

void troque2(int &x, int &y);
int opcao();

int main()
{
    setlocale(LC_ALL, "");
    int a, b;
    printf("Insira o valor de a e b:\n");
    scanf("%d%d%*c", &a, &b);
    troque2(a, b);
    printf("O valor a: %d\nO valor b: %d", a, b);
    return 0;
}

void troque2(int &x, int &y)
{
    int z = 0;
    if (opcao() == 1)
    {
        z = x;
        x = y;
        y = z;
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
