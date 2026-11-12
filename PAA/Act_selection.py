def GREEDY_ACTIVITY_SELECTOR(s, f, n):
    list_act = []
    # juntamos tudo em uma lista de tuplas
    for i in range (len(s)): list_act.append((i, s[i], f[i]))

    # ordena-se com base o tepo de fim
    list_act.sort(key=lambda x:x[2])

    # armazenamos a primeira escolha (sempre o que termina mais cedo)
    A = []; A.append(list_act[0])
    k = 0
    for i in range (1,len(list_act)):
        # se o tempo de inicio atual é depois do tempo final da ultima att escolhida
        if list_act[i][1] >= list_act[k][2]:
            # escolhe-se essa atividade
            A.append(list_act[i])
            k = i
    
    return A

start = list(map(int,input("inicio das atividades: ").split()))
finish = list(map(int,input("fim das atividades: ").split()))
answer = GREEDY_ACTIVITY_SELECTOR(start, finish, len(start))

for i in range (len(answer)): print(answer[i][1], answer[i][2])

