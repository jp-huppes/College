/*
Crie uma função chamada print_addr(int x) cujo propósito seja
apenas imprimir o conteúdo da variável x e seu endereço.
Declare uma variável x do tipo int na main e inicialize-a com
o valor 3. Imprima seu conteúdo e endereço dentro da main.
Então, chame a função print_addr passando a variável x como
argumento. Compare os resultados. Este comportamento é o
esperado?

    R: Como esperado os valores de saída foram os mesmos tanto dentro da main, quanto na função. Entretanto, os endereços foram diferentes, isso também era esperado pois estamos utilizando uma outra variavel para guardar o valor de int 'x', essa nova tendo o mesmo nome, mas sendo armazenada em outro local (dentro da função).
    */
#include <stdio.h>

void print_addr(int x);

int main()
{
    int x, *p;
    x = 3;
    printf("Print na Main:\nvalor: %d\nendereço:%p\n", x, &x);
    print_addr(x);
    return 0;
}

void print_addr(int x)
{
    printf("Print na função:\nvalor: %d\nendereço:%p\n", x, &x);
}
