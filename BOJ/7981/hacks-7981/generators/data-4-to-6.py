import random
random.seed(0)

# 4.in
N = 51_638
MX = 1_000_000_000

# 5.in
N = 100
MX = 1_000_000

# 6.in
N = 200_000
MX = 1_000_000_000

print(N)

first = f'1 {MX} {N//2}'
L = []
for i in range(2, N+2, 2):
  L.append(i)
random.shuffle(L)
for x in L:
  first += f' {x}'
print(first)

for i in range(2, N+1):
  if i%2 == 0:
    if 2 < i < N:
      print(f'1 {MX} 2 {i-2} {i+1}')
    elif i == 2:
      print(f'1 {MX} 1 {i+1}')
    else:
      print(f'1 {MX} 1 {i-2}')
  else:
    print(f'1 2 1 {i+1}')

