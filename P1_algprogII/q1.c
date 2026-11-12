// Atividade 01
#include <stdio.h>
#define SYZE 10

struct produto
{
    int codigo;
    char desc[100];
    float preco;
};

int main()
{
    int n, i, j, qt, num;
    float total = 0;
    struct produto novo, cardapio[10];
    printf("Insira a qt de produtos a serem adicionados: ");
    scanf("%d%*c", &n);
    for (i = 0; i < n; i++)
    {
        printf("Insira o codigo do novo produto: ");
        scanf("%d%*c", &novo.codigo);
        printf("Insira uma descricao do produto de codigo %d: \n", novo.codigo);
        scanf("%[^\n]99s%*c", novo.desc);
        printf("Insira o valor do produto %d de descrevido como \"%s\": ", novo.codigo, novo.desc);
        scanf("%f", &novo.preco);
        cardapio[i] = novo;
    }
    printf("Insira o codigo do produto pedido, e insira 0 para finalizar o pedido:\n");

    int pedidos[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (1)
    {
        printf("Insira o codigo, seguido pela qt:\n");
        scanf("%d%*c", &num);
        if (num == 0)
            break;
        scanf("%d%*c", &qt);
        for (j = 0; j < i; j++)
        {
            if (num == cardapio[j].codigo)
            {
                pedidos[j] += qt;
                total += cardapio[j].preco * qt;
            }
        }
    }

    printf("PEDIDO FINALIZADO\n");
    for (j = 0; j < i; j++)
        printf("%d X %s\n", pedidos[j], cardapio[j].desc);
    printf("TOTAL R$ %.2f \n", total);

    return 0;
}