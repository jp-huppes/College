def bottom_up_Cut_Road(p,n):
    r = []
    for i in range(n+1):
        r.append(0)
    
    for j in range (1, n + 1):
        q = -1
        for i in range(1, j + 1):
            q = max(q, p[i - 1] + r[j - i])
        r[j] = q

    return r[j]

def main():
    n = 4
    p = [1,5,8,9,10,17,17,20,24,30]
    print(bottom_up_Cut_Road(p,n))

main()