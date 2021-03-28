import math

N = int(input())
T = [int(x) for x in input().split()]
T.sort()

def possible(interval):
    short_probs = 0
    long_probs_weighted = 0
    for i in range(len(T)):
        if T[i] > interval:
            long_probs_weighted += math.ceil(T[i] / interval) - 2
        else:
            short_probs += 1
    return short_probs >= long_probs_weighted+1


l = 0
r = 10 ** 9 + 1

while l + 1 < r:
    mid = (l + r) // 2
    # print(mid)
    if possible(mid):
        r = mid
    else:
        l = mid

print(r)
