def case(test):
  N, K = (int(x) for x in input().split())
  C = [int(x) for x in input().split()]
  D = [int(x) for x in input().split()]



  fair = 0
  for l in range(N):
    for r in range(l, N):
      if abs(maxC[l][r] - maxD[l][r]) <= K:
        fair += 1

  print('Case #{}: {}'.format(test, fair))

T = int(input())

for test in range(1, T+1):
  case(test)
