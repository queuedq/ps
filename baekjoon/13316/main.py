from random import *

N = 10
zeros = 4
A = []
for i in range(zeros):
  A.append((0, 0))
for i in range(zeros, N):
  A.append((randint(0, 3), randint(0, 3)))

shuffle(A)

print(N)
for i in range(N):
  print(A[i][0], A[i][1])
