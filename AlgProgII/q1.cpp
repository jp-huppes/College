// Considere o seguinte trecho de código:

#include <stdio.h>

int main()
{
    int *p, a;

    a = 10;
    p = &a;
    *p = *p * 2;
    printf(" a = %d\n", a);

    return 0;
}

// Qual o valor da variável a ao final da execução? (Tente primeiro responder apenas analisando o código. Confirme a sua resposta compilando e executando o código.).

// R = O valor da varável 'a' no final da execução sera igual a '20'! Pois, ao utilizar *p estamos acessando o conteudo do endereço em que a variavel ponteiro 'p' esta "apontando", sendo este o conteudo de 'a', entao multiplicamos este valor por 2: 10 * 2 = 20 :D
