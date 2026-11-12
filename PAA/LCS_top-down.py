"""
noroeste: 1
norte: 0
oeste: -1

"""

def lcs_lengt (X,Y, i, j, c, b):
    # caso base;
    if (i == 0 or j == 0): return 0

    # se o valor nao esta na matriz, calculamos
    if (c[i][j] == -1):
        # se as letras sao iguais
        if (X[i-1] == Y[j-1]):
            c[i][j] = lcs_lengt(X,Y,i-1,j-1,c,b) + 1
            b[i][j] = 1
        # se as letras sao diferentes
        else:
            # vemos se existem os valores da esquerda e de cima
            top = lcs_lengt(X,Y, i -1, j,c,b)
            left = lcs_lengt(X,Y, i, j -1, c, b)
            # se o valor de cima eh maior propaga-se o de cima
            if (top >= left):
                c[i][j] = top
                b[i][j] = 0
            # caso contrario, propaga-se o de baixo
            else:
                c[i][j] = left
                b[i][j] = -1

    # retornamos o valor de c[i][j]
    return c[i][j]

def print_lcs (b,X,i,j):
    if i == 0 or j == 0: return
    # noroeste
    if b[i][j] == 1:
        print_lcs(b,X,i-1,j-1)
        print(X[i-1], end="")
    # norte
    elif b[i][j] == 0:
        print_lcs(b,X,i-1,j)
    # sul
    else:
        print_lcs(b,X,i,j-1)

X = input("primeira sequencia: ")
Y = input("segunda sequencia: ")

m = len(X); n = len(Y)
c = [[-1 for _ in range(n+1)] for _ in range(m+1)]
b = [[-1 for _ in range(n+1)] for _ in range (m+1)]

max_ = lcs_lengt (X,Y, m, n, c, b)

print("a maior subsequencia de tamanho",max_, "eh: ", end="")
print_lcs(b,X,len(X),len(Y))