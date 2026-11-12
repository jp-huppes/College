#include <stdio.h>
#include <stdlib.h>

struct cell
{
    int conteudo;
    struct cell *ant, *seg;
};
typedef struct cell celula;

void insira(celula *p, int x);
int retire_ultimo(celula *p);
int retire_primeiro(celula *p);
void mostre(celula *p);

int main()
{
    celula c, *lst;
    // modo 1: lst = (celula*) malloc(sizeoff(celulla)); lst->seg = lst; lst->ant = lst;
    c.ant = &c;
    c.seg = &c;
    lst = &c;
    insira(lst, 1);
    insira(lst, 2);
    insira(lst, 3);
    insira(lst, 4);
    insira(lst, 5);
    insira(lst, 6);
    mostre(lst);
    retire_ultimo(lst);
    retire_primeiro(lst);
    mostre(lst);
    return 0;
}

void insira(celula *p, int x)
{
    celula *nova = (celula *)malloc(sizeof(celula));
    nova->conteudo = x;
    nova->ant = p;
    nova->seg = p->seg;

    p->seg = nova;
    nova->seg->ant = nova;

    return;
}

int retire_ultimo(celula *p)
{
    if (p->ant == p && p->seg == p)
        return -1;
    else
    {
        celula *temp = p->seg;
        int num = temp->conteudo;
        p->seg = temp->seg;
        temp->seg->ant = p;
        temp->seg = temp->ant = NULL;

        free(temp);
        return num;
    }
}

int retire_primeiro(celula *p)
{
    if (p->ant == p && p->seg == p)
        return -1;
    else
    {
        celula *temp = p->ant;
        int num = temp->conteudo;

        p->ant = temp->ant;
        temp->ant->seg = p;
        temp->seg = temp->ant = NULL;
        free(temp);
        return num;
    }
}

void mostre(celula *p)
{
    celula *sent = p;
    p = p->seg;
    printf("Cabeca -");
    for (; p != sent; p = p->seg)
    {
        printf("%d -", p->conteudo);
    }
    printf(" Cabeca\n");
    return 0;
}