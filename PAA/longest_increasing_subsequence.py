def longest_increasing_subsequence(X):
    n = len(X)
    # todo elemento sozinho ja eh uma subsequencia de tamanho 1
    L = [1] * n

    # tentanoms encontrar a maior subcadeia que acaba em X[i]
    for i in range(n):
        # verificamos agora os elementos anteriores a i
        for j in range(i-1,-1,-1):
            if X[i] > X[j]: L[i] = max(L[i],L[j] + 1)
    return max(L)


X = input("sequencia: ")
print(longest_increasing_subsequence(X))