"""
noroeste: 1
norte: 0
oeste: -1

"""

def lcs_lenght (X,Y):
    m = len(X); n = len(Y)
    c = [[0 for _ in range(n+1)] for _ in range(m+1)]
    b = [[0 for _ in range(n+1)] for _ in range (m+1)]
    for i in range (1,m + 1):
        for j in range(1,n + 1):
            # se as letras sao igauis
            if X[i - 1] == Y[j - 1]:
                # add valor da diagonal a esquerda + 1
                c[i][j] = c[i-1][j-1] + 1
                b[i][j] = 1 # noroeste
            # caso contrario, se o valor de cima for maior
            elif c[i-1][j] >= c[i][j-1]:
                # preserva-se o valor de cima
                c[i][j] = c[i-1][j]
                b[i][j] = 0 # norte
            # se o valor da esquerda for maior
            else:
                # preserva-se o valor da esquerda
                c[i][j] = c[i][j-1]
                b[i][j] = -1
    return c, b

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
c,b = lcs_lenght(X,Y)
print("a maior subsequencia de tamanho", c[len(X)][len(Y)], "eh: ", end="")
print_lcs(b,X,len(X),len(Y))
