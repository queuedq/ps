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
    for j in xrange(i):
        P[j] = s

for t in xrange(1, T+1):
    N, K = map(int, raw_input().split())
    U = float(raw_input())
    P = sorted(map(float, raw_input().split()))

    make_flat(U, P)

    prob = 1
    for p in P[:-1]:
        prob *= p
    
    print 'Case #' + str(t) + ': ' + str(prob)
