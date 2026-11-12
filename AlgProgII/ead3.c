#include <stdio.h>
#include <stdlib.h>

int enfileirar(int *f, int next);
int retirar(int *f, int start, int next);
void imprima(int *f, int start, int next);

int main()
{
    int *fila, s, t, T, action;

    printf("Insira um valor T, referente a quantidade de acoes que deseja tomar: ");
    scanf("%d%*c", &T);
    fila = (int *)malloc(sizeof(int) * T);
    s = t = 0;

    while (T > 0)
    {
        printf("1)enfileirar\n2)retirar\n3)imprimir\nacao: ");
        scanf("%d%*c", &action);
        switch (action)
        {
        case 1:
            t = enfileirar(fila, t);
            break;
        case 2:
            s = retirar(fila, s, t);
            break;
        case 3:
            imprima(fila, s, t);
            break;
        default:
            T++;
            break;
        }

        T--;
    }
    return 0;
}

int enfileirar(int *f, int next)
{
    int num;
    printf("Valor inserido\n");
    scanf("%d%*c", &num);
    f[next] = num;

    return next += 1;
}

int retirar(int *f, int start, int next)
{
    if (start == next)
        printf("Fila ja esta vazia\n");
    else
    {
        f[start] = -1;
        start += 1;
    }
    return start;
}

void imprima(int *f, int start, int next)
{
    if (start == next)
        printf("Fila vazia!\n");
    else
        printf("Primeiro valor na fila: %d\n", f[start]);
    return;
}