T = int(input())

for _ in range(T):
  a, b = [int(x) for x in input().split()]
  prizesA = [[0], [500] * 1, [300] * 2, [200] * 3, [50] * 4, [30] * 5, [10] * 6]
  prizesA = [x for l in prizesA for x in l ]
  prizesB = [[0], [512] * 1, [256] * 2, [128] * 4, [64] * 8, [32]* 16]
  prizesB = [x for l in prizesB for x in l ]

  if a < len(prizesA):
    prizeA = prizesA[a]
  else:
    prizeA = 0
  if b < len(prizesB):
    prizeB = prizesB[b]
  else:
    prizeB = 0

  print((prizeA + prizeB) * 10000)
