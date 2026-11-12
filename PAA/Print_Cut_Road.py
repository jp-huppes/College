def bottom_up_Cute_Rod(p,n):
    r = []; s = []
    for _ in range(n + 1):
        r.append(0)
        s.append(0)

    for j in range (1, n + 1):
        q = -1
        for i in range (1, j + 1):
            if q < p[i - 1] + r[j - i]:
                q = p[i - 1] + r[j - i]
                s[j] = i
        r[j] = q

    return r, s

def Print_Cut_Road(p,n):
    r,s = bottom_up_Cute_Rod(p,n)
    print ("max: ", r[n])
    while n > 0:
        print(s[n])
        n = n - s[n]

def main():
    n = 4
    p = [1,5,8,9,10,17,17,20,24,30]
    print(Print_Cut_Road(p,n))

main()