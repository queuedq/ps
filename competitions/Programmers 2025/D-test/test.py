import random

ALPHA = 'abcdefgh'
N = 10
Q = 10

S = ''.join(random.choice(ALPHA) for _ in range(N))
print(S)
print(Q)

for i in range(Q-1):
  q = random.randint(1, 4)
  x = random.randint(1, N)
  y = random.randint(1, N)
  word = ''.join(random.sample(ALPHA, random.randint(1, len(ALPHA))))

  if q == 1:
    print(q, x, y)
  elif q == 2:
    print(q, x, word)
  elif q == 3:
    if x > y: x, y = y, x
    print(q, x, y, word)
  elif q == 4:
    print(q, x, y)
  
print(5)
