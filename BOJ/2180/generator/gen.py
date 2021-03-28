from random import *

N = int(input())
s = input()  # seed
seed(s)
mx = 40000

# Generate
A = []
for i in range(N//2):
  A.append((0, 0))
for i in range(N//2, N*3//4):
  A.append((randint(1, mx), randint(1, mx)))
for i in range(N*3//4, N*7//8):
  A.append((0, randint(1, mx)))
for i in range(N*7//8, N):
  A.append((randint(1, mx), 0))

assert(len(A) == N)
shuffle(A)

# Print
print(N)
for i in range(N):
  print(A[i][0], A[i][1])
