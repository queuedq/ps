N = int(input())

def money(a, b, c):
  if a == b and b == c:
    return 10000 + a * 1000
  if a == b:
    return 1000 + a * 100
  if b == c or c == a:
    return 1000 + c * 100
  return max(a, b, c) * 100

exp = {}

def getexp(a, b, c, n):
  if n == 0:
    return money(a, b, c)
  total = 0
  for d in range(1, 7):
    total += exp[(b, c, d, n-1)]
  return max(money(a, b, c), total / 6)


for n in range(N - 2):
  for a in range(1, 7):
    for b in range(1, 7):
      for c in range(1, 7):
        exp[(a, b, c, n)] = getexp(a, b, c, n)

total = 0
for a in range(1, 7):
  for b in range(1, 7):
    for c in range(1, 7):
      total += exp[(a, b, c, N - 3)]

print(total / (6 * 6 * 6))
