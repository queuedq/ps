import random
random.seed(0)

G = 20
N = 3*G + 1

print(N)

first = f'1 10000 {G*2}'
L = []
for i in range(G):
  L += [i*3+2, i*3+4]
random.shuffle(L)
for i in range(G*2):
  first += f' {L[i]}'
print(first)

for i in range(G):
  a, b, c = i*3+2, i*3+3, i*3+4
  if random.randint(0, 1):
    print(f'1 100 1 {b}')
    print(f'1 2 1 {c}')
    print(f'1 100 1 {a}')
  else:
    print(f'1 100 1 {c}')
    print(f'1 2 1 {a}')
    print(f'1 100 1 {b}')
