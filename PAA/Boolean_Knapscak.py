def Bollean_bag (w,v,n,W):
    # t = matriz com os resultados
    t = [[0 for _ in range (W + 1)] for _ in range(n + 1)] 
    # Y = tamanho do subproblema
    for Y in range(0,W + 1):
        t[0][Y] = 0
        # i = conjunto de itens que podem ser utilizados (i = 1, somente o primeiro item, i = 2 estamos olhando para o segundo item com combinação do segundo)        
        for i in range (1,n + 1):
            # a = tomamos o 
            a = t[i-1][Y]
            # se o peso do item supera Y então nao podemos pega-lo
            if w[i-1] > Y: b = 0
            else:
                # caso o item possa ser pego temos:
                    # v[i-1] = pegamos o valor do item atual
                    # Y - W[i-1] = capacidade que sobra na mochila ao colocar o item
                        # t[i-1][sobra] = melhor resultado que caiba com o peso que sobrou
                b = t[i-1][Y - w[i-1]] + v[i-1]
            t[i][Y] = max(a,b)
    return t

def print_path(t,n,w,W):
    # comecamos com os indices do valor total
    i = n; j = W
    bag = []
    while (i > 0 and j > 0):
        # se o valor acima do valor observado for diferente
            # significa que esse item fez diferença pro valor final
        if (t[i][j] != t[i-1][j]):
            bag.append(i-1)
            # j agora aponta para o resultado em t com o peso sobrando (ou seja, o melhor resultado do subproblema da sobra)
            j = j - w[i-1]

        # agora olhamos para o subconjunto com -1 item
        i = i - 1
    return bag

W = int(input("peso da mochila: "))
n = int(input("num de itens: "))
w = list(map(int,input("peso dos itens: ").split()))
v = list(map(int,input("valor dos itens: ").split()))

t = Bollean_bag(w,v,n,W)

print("Valor max:", t[n][W])
bag = print_path(t,n,w,W)
print("Itens:")
for i in bag:
    print(w[i],v[i])