from random import seed, randint

seed(0)

N = randint(1, 2000000)
K = randint(1, 500000)
A = [randint(0, 9) for _ in range(N)]
B = [randint(1, 10 ** 18) for _ in range(N)]

print(N, K)
for i in range(N):
  print(A[i], B[i])
