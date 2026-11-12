#include <stdio.h>
#include <stdlib.h>

int *double_vector(int *p, int *size);

int main()
{
    int i, *v, *t, num, contador = 0, tamanho = 5;
    *t = tamanho;
    v = (int *)malloc(sizeof(int) * tamanho);
    printf("Insira os valores no vetor:\n");

    while (1)
    {
        scanf("%d", &num);
        if (num == -1)
            break;
        v[contador] = num;
        contador++;
        if (contador == tamanho)
            v = double_vector(v, t);
    }
    for (i = 0; i < contador; i++)
        printf("%d ", v[i]);
    printf("\n");
    free(v);

    return 0;
}

int *double_vector(int *p, int *size)
{
    int *v_dobrado, temp;
    temp = *size;
    *size *= 2;

    v_dobrado = (int *)malloc(sizeof(int) * (*size));
    for (int z = 0; z < temp; z++)
        v_dobrado[z] = p[z];
    free(p);
    return v_dobrado;
}