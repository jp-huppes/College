#include <stdio.h>
#define TAMANHO 250

int main()
{

    int contador = 1;
    FILE *par, *impar, *recuperado;
    char copia[TAMANHO], *verificador;

    par = fopen("lotr_cap1_even.txt", "r");
    impar = fopen("lotr_cap1_odd.txt", "r");
    recuperado = fopen("lotr_cap1_recovered.txt", "w");
    if (par == NULL || impar == NULL || recuperado == NULL)
    {
        perror("Error ao abrir o arquivo");
        return 1;
    }
    while (1)
    {
        if (contador % 2 != 0)
        {
            verificador = fgets(copia, TAMANHO, impar);
            if (verificador == NULL)
            {
                verificador = fgets(copia, TAMANHO, par);
                if (verificador == NULL)
                    break;
            }
        }
        if (contador % 2 == 0)
        {
            verificador = fgets(copia, TAMANHO, par);
            if (verificador = NULL)
            {
                verificador = fgets(copia, TAMANHO, impar);
                if (verificador == NULL)
                    break;
            }
        }
        fprintf(recuperado, "%s", copia);
        contador++;
    }

    fclose(impar);
    fclose(par);
    fclose(recuperado);

    return 0;
}