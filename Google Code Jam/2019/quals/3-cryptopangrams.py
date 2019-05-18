T = int(input())

def gcd(a, b):
  r, old_r = b, a

  while r != 0:
    r, old_r = old_r % r, r

  return old_r

def case(test):
  N, L = input().split(' ')
  L = int(L)
  cipher = [int(x) for x in input().split(' ')]
  messagePrimes = [None] * (L + 1)
  message = []
  primes = set()
  alphabets = {}

  # get message primes
  pivot = 0
  for i in range(len(cipher) - 1):
    if cipher[i] != cipher[i + 1]:
      pivot = i
      messagePrimes[i + 1] = gcd(cipher[i], cipher[i + 1])
      break

  for i in range(pivot, -1, -1):
    messagePrimes[i] = cipher[i] // messagePrimes[i + 1]

  for i in range(pivot + 2, L + 1):
    messagePrimes[i] = cipher[i - 1] // messagePrimes[i - 1]


  # decrypt
  for p in messagePrimes:
    primes.add(p)

  sortedPrimes = sorted(primes)

  for i in range(26):
    alphabets[sortedPrimes[i]] = chr(i + ord('A'))

  for p in messagePrimes:
    message.append(alphabets[p])

  print('Case #{}: {}'.format(test, ''.join(message)))

for test in range(1, T+1):
  case(test)
