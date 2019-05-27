T = int(raw_input())

for t in xrange(1, T+1):
    D, N = raw_input().split()
    D = float(D)
    N = int(N)

    max_time = None
    for i in xrange(N):
        K, S = raw_input().split()
        K = float(K)
        S = float(S)
        time = (D-K) / S
        if not max_time or time > max_time:
            max_time = time

    speed = D / max_time
    print "Case #" + str(t) + ": " + str(speed)
