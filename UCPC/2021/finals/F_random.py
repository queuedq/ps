import random

N = 20
print(N)
A = [[0, 0] for _ in range(N)]

for i in range(N):
  x = random.randint(1, 20)
  A[i][0] = x
  print(x, end=' ')
print()

for i in range(N):
  y = random.randint(1, 20)
  A[i][1] = y
  print(y, end=' ')
print()

ans = 0
for i in range(N):
  for j in range(N):
    ans += min(abs(A[i][0] - A[j][0]), abs(A[i][1] - A[j][1]))

print(ans)
