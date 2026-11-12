/* Implemente a função troque() que faz uso da passagem por
valor. Essa função deve realizar a troca dos argumentos a e b.
Teste na main e veja que a função implementada não funciona.
Explique.

    R: Ao criar a função troque() que faz uso de passagem
    por valor, nota-se uma limitação. Utilizando esse método
    seria necessário retornar 2 valores que depois seriam
    atribuídos às variáveis (a e b), o que se prova ser
    impossível em C, já que as funções no C istritamente retornam
    somente 1 valor do tipo da função com este valor ñ podendo ser um vetor.
*/

#include <stdio.h>

int troque(int x, int y);

int main()
{
    int a, b;
    a, b = scanf("%d%d", &a, &b);
    troque(a, b);
}

int troque(int x, int y)
{
    int z;
    z = x;
    x = y;
    y = z;
    return x, y
}