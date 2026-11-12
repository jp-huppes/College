/*
Declare duas variáveis x e y do tipo int e duas variáveis p e q do tipo int*. Atribua o
valor 2 para x e 8 para y, o endereço de x para p e o endereço de y para q. Então, imprima
(usando printf) as seguintes informações:
(a) O endereço de x e o valor de x;
(b) O valor de p e o valor de *p;
(c) O endereço de y e o valor de y;
(d) O endereço de p (não o seu conteúdo!).
Obs.: Um endereço deve ser impresso utilizando o especificador de formato %p no printf.

R:*/

#include <stdio.h>
#include <locale.h>
int main()
{
    setlocale(LC_ALL, "");
    int x, y, *p, *q;
    x = 2;
    y = 8;
    p = &x;
    q = &y;
    printf("(a) O endereço de x: %p.\n    O valor de x: %d\n", &x, x);
    printf("(b) O valor de p: %p.\n    O valor de *p: %d\n", p, *p);
    printf("(c)O endereço de y: %p\n    O valor de y: %d\n", &y, y);
    printf("(d) O endereço de p: %p\n", &p);

    return 0;
}
