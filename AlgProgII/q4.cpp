// Discuta, passo a passo, o efeito do seguinte fragmento de código:

int *v;
v = (int *)malloc(10 * sizeof(int));

/*   R: A linha 01 define uma variavel do tipo int* (ou seja,
    um ponteiro para variaveis do tipo int), em seguida na
    linha 02 ele define uma "alocação dinamica" utilizando a
    funçao "maloc()", nesse caso ele reserva um espaço de 10
    endereços na memoria do tipo int* (mesmo que a função malloc
    retorne um vetor tipo void* que automaticamente seria já convertido para int*)
    e relaciona o primeiro endereço da sequencia na variavel ponteiro V (similar a
    criar um vetor de tamanho 10). Seria recomendado utilizar
    da função free(v) após o fim do programa para liberar a
    memoria reservada pela função maloc().
    */