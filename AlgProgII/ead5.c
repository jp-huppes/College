#include <stdio.h>
#include <stdlib.h>

struct cell
{
    int conteudo;
    struct cell *seg, *ant;
};
typedef struct cell celula;

void insira(celula *p, int y);
void imprima(celula const *p);
void bubble_sort(celula *p);
void merge_sort(celula *P);
void selection_sort(celula *p);

int main()
{
    char choice;
    celula c, *lst;
    c.ant = &c;
    c.seg = &c;
    lst = &c;
    insira(lst, 12);
    insira(lst, 360);
    insira(lst, 13);
    insira(lst, 4);
    insira(lst, 15);
    insira(lst, 69);
    insira(lst, 360);
    imprima(lst);
    printf("b = bubble | s = sellection\n");
    scanf("%c%*c", &choice);
    switch (choice)
    {
    case 'b':
        bubble_sort(lst);
        break;
    case 'c':
        selection_sort(lst);
        break;
    defaul:
        break;
    }
    imprima(lst);
    return 0;
}

void insira(celula *p, int y)
{

    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = y;
    nova->seg = p->seg;
    nova->ant = p;
    p->seg->ant = nova;
    p->seg = nova;

    return;
}

void imprima(celula const *p)
{
    celula *temp = p->seg;
    printf("cabeca -> ");
    for (; temp != p; temp = temp->seg)
        printf("%d -> ", temp->conteudo);
    printf("celula\n");
    return;
}

void bubble_sort(celula *p)
{
    // usamos um algoritmo que move as próprias células, no lugar de seus conteudos.
    int trocou = 1;
    celula *j, *aux;

    while (trocou)
    {
        trocou = 0;

        for (j = p->seg; j->seg != p; j = j->seg)
        {
            aux = j->seg;

            if (j->conteudo > aux->conteudo)
            {
                j->ant->seg = aux;
                aux->seg->ant = j;

                j->seg = aux->seg;
                aux->ant = j->ant;

                aux->seg = j;
                j->ant = aux;

                j = aux->ant;
                trocou = 1;
            }
        }
    }
    return;
}

void selection_sort(celula *p)
{
    // Trocamos somente os conteudos de lugar ,pois para celula eh um algoritmo muito complexo não recomendado.

    celula *i, *j, *aux; // aux = menor valor;
    int temp;
    for (i = p->seg; i != p; i = i->seg)
    {
        aux = i;
        for (j = i->seg; j != p; j = j->seg)
        {
            if (j->conteudo < aux->conteudo)
            {
                aux = j;
            }
        }
        if (aux != i)
        {
            temp = i->conteudo;
            i->conteudo = aux->conteudo;
            aux->conteudo = temp;
        }
    }
}