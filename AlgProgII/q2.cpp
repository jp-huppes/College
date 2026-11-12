// Considere o seguinte trecho de código:
#include <stdio.h>

int main()
{
    float *q, b;

    b = 3.14;
    *q = *q + 1;
    printf("*q=%f \n", *q);

    return 0;
}

// Onde está o erro neste código? O que acontecerá se você executá-lo desta maneira?

// R = O erro esta no fato de que o ponteiro (q) nunca recebe um endereço. Assim, ao realizar a adição na linha 9 (*q  + 1) acarreta em um erro pois a referencia ñ foi definida. Entretanto, em alguns compiladores o pograma não terá um erro de sintaxe e sim de lógica (pois *q é preenchido com 'lixo') retornando valores aleatorios.
