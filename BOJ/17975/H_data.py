from random import *

# seed(1)
n1 = randint(1, 1000)
n2 = randint(1, 1000)
c1 = randint(1, 10000)
c2 = randint(1, 10000)

N = n1 + n2
xs = []
ys = []

for i in range(N):
  x = randint(-1e9, 1e9)
  while x in xs:
    x = randint(-1e9, 1e9)
  xs.append(x)

  y = randint(-1e9, 1e9)
  while y in ys:
    y = randint(-1e9, 1e9)
  ys.append(y)


print(n1)
for i in range(n1):
  print(xs[i], ys[i])

print(n2)
for i in range(n1, n1+n2):
  print(xs[i], ys[i])
  
print(c1, c2)
