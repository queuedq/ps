def tourist():
  N, K, V = (int(x) for x in input().split())
  A = [input() for _ in range(N)]
  start = K * (V - 1) % N
  indicies = [i % N for i in range(start, start + K)]
  indicies.sort()
  return ' '.join([A[i] for i in indicies])

def main():
  T = int(input())
  for test in range(1, 1+T):
    print('Case #{}: {}'.format(test, tourist()))

main()
