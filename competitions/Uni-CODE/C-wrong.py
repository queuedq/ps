Q, M = (int(x) for x in input().split())

def matMul(a, b):
  c = [[0, 0], [0, 0]]
  c[0][0] = a[0][0] * b[0][0] + a[0][1] * b[1][0]
  c[0][1] = a[0][0] * b[0][1] + a[0][1] * b[1][1]
  c[1][0] = a[1][0] * b[0][0] + a[1][1] * b[1][0]
  c[1][1] = a[1][0] * b[0][1] + a[1][1] * b[1][1]

  c[0][0] = c[0][0] % M
  c[0][1] = c[0][1] % M
  c[1][0] = c[1][0] % M
  c[1][1] = c[1][1] % M
  return c

def getFib(N):
  mat = [[0, 1], [1, 1]]
  res = [[1, 0], [0, 1]]
  bits = bin(N)[2:]
  for i in bits:
    res = matMul(res, res)
    if i == '1':
      res = matMul(res, mat)
  return res[1][1]

################################################################

def main():
  for q in range(Q):
    N = int(input())
    print(getFib(N))

if __name__ == "__main__":
  main()
