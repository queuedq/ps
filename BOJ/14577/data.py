from random import seed, randint

seed(input())
MX = 10**9

def aprint(arr):
  for a in arr:
    print(a, end=' ')
  print()

N = 50
M = 1000
S = [randint(0, MX) for i in range(N)]

print(N, M)
aprint(S)

for i in range(M):
  q = randint(1, 4)
  if q == 1:
    i = randint(1, N)
    x = randint(0, MX)
    print(q, i, x)
    S[i-1] += x
  if q == 2:
    q = 1
    i = randint(1, N)
    x = randint(0, min(S[i-1], MX))
    print(q, i, x)
    S[i-1] -= x
  if q == 3:
    l = randint(0, MX)
    r = randint(0, MX)
    if (l > r): l, r = r, l
    print(q, l, r)
  if q == 4:
    print(q, randint(1, N))
