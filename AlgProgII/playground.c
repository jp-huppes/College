#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int dado;
    struct No *prox;
} No;

No *insere_no_inicio(No *cabeca, int valor);
void imprima(No *cabeca);
No *remove_do_fim(No *cabeca);

int main()
{
    No *lst = NULL;

    lst = insere_no_inicio(lst, 3);
    lst = insere_no_inicio(lst, 2);
    lst = insere_no_inicio(lst, 1);

    return 0;
}

No *insere_no_inicio(No *cabeca, int valor)
{
    No *nova = (No *)malloc(sizeof(No));

    nova->dado = valor;
    nova->prox = cabeca;

    return nova;
}

No *remove_do_fim(No *cabeca)
{
    if (cabeca = NULL)
        printf("Lista vazia\n");
    else if (cabeca->prox == NULL)
    {
        printf("Ultimo elemento removido");
        free(cabeca);
        return NULL;
    }
    else
    {
        No *atual, *new_last;
        for (atual = cabeca->prox; atual->prox->prox != NULL; atual = atual->prox)
            ;

        new_last = atual;
        atual = atual->prox;
        free(atual);
        new_last->prox = NULL;
    }

    return cabeca;
}

void imprima(No *cabeca)
{
    No *i = cabeca;
    printf("cabeca -> ");
    for (; i != NULL; i = i->prox)
        printf("%d -> ", &i->dado);
    printf("NULL\n");
    return;
}