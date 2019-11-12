Q, M = (int(x) for x in input().split())
fib = [0, 1]
fibDigits = []

def getFib():
  while True:
    nextFib = (fib[-1] + fib[-2]) % M
    if (fib[-1] == 0 and nextFib == 1):
      fib.pop()
      break
    else:
      fib.append(nextFib)

def getFibDigits():
  # print(fib)

  for i in range(len(fib)):
    for x in str(fib[i]):
      fibDigits.append(int(x))


################################################################

def main():
  getFib()
  getFibDigits()
  # print(fibDigits)
  for i in range(Q):
    N = int(input())
    nn = N % len(fibDigits)
    print(fibDigits[nn])

if __name__ == "__main__":
  main()
