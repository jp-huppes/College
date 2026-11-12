#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void qbubble_sort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *));
int bubble_sort_int(const void *x, const void *y);
int bubble_sort_float(const void *x, const void *y);
int bubble_sort_doubble(const void *x, const void *y);
int bubble_sort_char(const void *x, const void *y);
int bubble_sort_string(const void *x, const void *y);
void teste_int();
void teste_float();
void teste_double();
void teste_char();
void teste_string();

int main()
{
    teste_int();
    printf("\n");
    teste_float();
    printf("\n");
    teste_double();
    printf("\n");
    teste_char();
    printf("\n");
    teste_string();
    printf("\n");

    return 0;
}

int bubble_sort_int(const void *x, const void *y)
{
    int a = *(int *)x;
    int b = *(int *)y;
    if (a > b)
        return 1;
    else if (a <= b)
        return 0;
}

int bubble_sort_float(const void *x, const void *y)
{
    float a = *(float *)x;
    float b = *(float *)y;
    if (a > b)
        return 1;
    else if (a <= b)
        return 0;
}

int bubble_sort_doubble(const void *x, const void *y)
{
    double a = *(double *)x;
    double b = *(double *)y;
    if (a > b)
        return 1;
    else if (a <= b)
        return 0;
}

int bubble_sort_char(const void *x, const void *y)
{
    char a = tolower(*(char *)x);
    char b = tolower(*(char *)y);
    if (a > b)
        return 1;
    else if (a <= b)
        return 0;
}

int bubble_sort_string(const void *x, const void *y)
{
    char *a_string = *(char **)x;
    char *b_string = *(char **)y;
    int i = 0;
    while ((a_string[i] != '\0') && (b_string[i] != '\0') && (tolower(a_string[i]) == tolower(b_string[i])))
        i++;
    char a = tolower(a_string[i]);
    char b = tolower(b_string[i]);
    if (a > b)
        return 1;
    else
        return 0;
}

void qbubble_sort(void *base, size_t nitems, size_t size, int (*compare)(const void *, const void *))
{
    char *e1, *e2, temp[size];
    int caso;

    for (int i = 0; i < nitems - 1; i++)
    {
        for (int j = 0; j < nitems - i - 1; j++)
        {
            e1 = (char *)base + j * size;
            e2 = (char *)base + (j + 1) * size;
            caso = (compare(e1, e2));
            if (caso)
            {
                memcpy(temp, e1, size);
                memcpy(e1, e2, size);
                memcpy(e2, temp, size);
            }
        }
    }
}

void teste_int()
{
    int vetor[5] = {1, 2, 3, 4, 5};
    size_t n_valores, tipagem;
    int i = 0;

    tipagem = sizeof(vetor[0]);
    n_valores = sizeof(vetor) / tipagem;

    qbubble_sort(vetor, n_valores, tipagem, bubble_sort_int);
    for (i = 0; i < n_valores; i++)
        printf("%d ", vetor[i]);
}

void teste_float()
{
    float vetor[4] = {3.14f, 2.71f, 1.61f, 9.99f};
    size_t n_valores, tipagem;
    int i = 0;

    tipagem = sizeof(vetor[0]);
    n_valores = sizeof(vetor) / tipagem;

    qbubble_sort(vetor, n_valores, tipagem, bubble_sort_float);
    for (i = 0; i < n_valores; i++)
        printf("%.2f ", vetor[i]);
}

void teste_double()
{
    double vetor[8] = {123456.78, -9.87654, 0.00001, -500.0, 3.141592653, 1.2345e-4, -8.88, 7654.321};
    size_t n_valores, tipagem;
    int i = 0;

    tipagem = sizeof(vetor[0]);
    n_valores = sizeof(vetor) / tipagem;

    qbubble_sort(vetor, n_valores, tipagem, bubble_sort_doubble);
    for (i = 0; i < n_valores; i++)
        printf("%.10lf ", vetor[i]);
}

void teste_char()
{
    char vetor[7] = {'C', 'o', 'd', 'e', ' ', 'C', '!'};
    size_t n_valores, tipagem;
    int i = 0;

    tipagem = sizeof(vetor[0]);
    n_valores = sizeof(vetor) / tipagem;

    qbubble_sort(vetor, n_valores, tipagem, bubble_sort_char);
    for (i = 0; i < n_valores; i++)
        printf("%c ", vetor[i]);
}

void teste_string()
{
    char *vetor[6] = {"Eu", "gosto", "de", "voce", "as", "vezes"};
    size_t n_valores, tipagem;
    int i = 0;

    tipagem = sizeof(vetor[0]);
    n_valores = sizeof(vetor) / tipagem;

    qbubble_sort(vetor, n_valores, tipagem, bubble_sort_string);
    for (i = 0; i < n_valores; i++)
        printf("%s ", vetor[i]);
}