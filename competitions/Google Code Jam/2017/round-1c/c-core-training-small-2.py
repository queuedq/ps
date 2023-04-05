T = int(raw_input())

def make_flat(U, P):
    P.append(100)
    u = 0
    i = 1
    while True:
        u += (P[i]-P[i-1]) * i
        i += 1
        if u > U:
            i -= 1
            u -= (P[i]-P[i-1]) * i
            break
    
    s = (U - u) / i + P[i-1]
    r = 0
    if s > 1:
        r = (s - 1) * i
        s = 1.
    for j in xrange(i):
        P[j] = s
    P.pop()
    return r

for t in xrange(1, T+1):
    N, K = map(int, raw_input().split())
    U = float(raw_input())
    P = sorted(map(float, raw_input().split()))

    if K == N:
        make_flat(U, P)

        prob = 1
        for p in P:
            prob *= p
    else:
        P_large = P[N-K:]
        P_small = P[:N-K]
        rest = make_flat(U, P_large)
        make_flat(rest, P_small)
        P = [None] + P_small + P_large
        
        plist = [[1]]  # plist[n][k] | n >= k >= 1
        for n in xrange(1, N+1):
            plist.append([plist[n-1][0]*(1-P[n])])
            for k in xrange(1, n+1):
                # plist[n][k] = plist[n-1][k-1]*P[k] + plist[n-1][k]*(1-P[k])
                if k < n:
                    plist[n].append(plist[n-1][k-1]*P[n] + plist[n-1][k]*(1-P[n]))
                else:  # k == n
                    plist[n].append(plist[n-1][k-1]*P[n])
        
        prob = sum(plist[N][K:])
    
    print 'Case #' + str(t) + ': ' + str(prob)
