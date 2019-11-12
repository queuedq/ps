import math

def isprime(N):
  if N < 2:
    return False
  for i in range(2, math.floor(math.sqrt(N)) + 1):
    if N % i == 0:
      return False

  return True

p = []

for i in range(10000000, 0, -1):
  if isprime(i):
    p.append(i)
    if len(p) == 2:
      break

print(p)
