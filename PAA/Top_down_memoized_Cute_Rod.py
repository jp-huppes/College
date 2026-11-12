def memoized_Cute_Rod(p,n):
    r = []
    for _ in range(0, n + 1):
        r.append(-1)

    return memoized_Cute_Rod_aux(p,n,r)


def memoized_Cute_Rod_aux(p,n,r):
    if r[n] >= 0: return r[n]
    if n == 0: return 0
    else:
        q = -1
        for i in range(1,n+1):
            q = max(q, p[i- 1] + memoized_Cute_Rod_aux(p,n - i, r))
        r[n] = q
        return r[n]

def main():
    n = 4
    p = [1,5,8,9,10,17,17,20,24,30]
    print(memoized_Cute_Rod(p,n))

main()