def case(test):
  N, K = (int(x) for x in input().split())
  C = [int(x) for x in input().split()]
  D = [int(x) for x in input().split()]

  maxC = []
  maxD = []
  for i in range(N):
    maxC.append([None] * N)
    maxD.append([None] * N)

  for l in range(N):
    maxC[l][l] = C[l]
    maxD[l][l] = D[l]
    for r in range(l + 1, N):
      maxC[l][r] = max(maxC[l][r - 1], C[r])
      maxD[l][r] = max(maxD[l][r - 1], D[r])

  fair = 0
  for l in range(N):
    for r in range(l, N):
      if abs(maxC[l][r] - maxD[l][r]) <= K:
        fair += 1

  print('Case #{}: {}'.format(test, fair))

T = int(input())

for test in range(1, T+1):
  case(test)
