import random

print(1)

N = 100
C = 10
AB = [None] * C
P = [None] * N

print(N, C)

for i in range(C):
  A = random.randint(0, 10)
  B = random.randint(0, 10)
  if (A > B): A, B = B, A
  AB[i] = (A, B)
  print(AB[i][0], AB[i][1])

for i in range(N):
  P[i] = random.randint(1, C)
  print(P[i], end=' \n'[i==N-1])
