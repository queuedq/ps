import math

T = int(raw_input())
PI = math.pi

for t in xrange(1, T+1):
    N, K = map(int, raw_input().split())
    raw_list = []
    for _ in xrange(N):
        pancake = map(int, raw_input().split())
        raw_list.append(pancake)
    pancakes = sorted(raw_list, key=lambda x: x[0])

    def circle(i):
        return pancakes[i][0]*pancakes[i][0]

    def side(i):
        return 2*pancakes[i][0]*pancakes[i][1]

    score = [[]]  # score[i][j]: last ith, rest j pancakes

    score[0].append(circle(0) + side(0))
    for n in xrange(1, N):
        score.append([])
        # k = 0
        score[n].append(circle(n) + side(n))
        # k > 0
        for k in xrange(1, min(n, K-1)+1):  # k max n or K-1
            max_score = 0
            for prev in xrange(k-1, n):  # prev k-1 to n-1
                new_score = score[prev][k-1] - circle(prev) + circle(n) + side(n)
                if new_score > max_score:
                    max_score = new_score
            score[n].append(max_score)  # score[n][k] = max_score

    result = 0
    for n in xrange(K-1, N):
        if score[n][K-1] > result:
            result = score[n][K-1]
    result = PI*result

    print 'Case #' + str(t) + ': ' + str(result)