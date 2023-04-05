import math

def gcd(a, b):
  """Calculates the gcd of a and b."""
  r0, r1 = abs(a), abs(b)
  while r1 > 0:
    r0, r1 = r1, r0 % r1
  return r0

class Rational():
  def __init__(self, a, b):
    if b == 0:
      raise ValueError('Denominator should not be zero')
    if b < 0:
      a = -a
      b = -b

    g = gcd(a, b)
    self.a = a // g
    self.b = b // g

  def __str__(self):
    return '{{a:{}, b:{}}}'.format(self.a, self.b)

  def __eq__(self, other):
    return self.a == other.a and self.b == other.b

  def __hash__(self):
    return hash((self.a, self.b))


# Each test case
def case(test):
  N = int(input())
  C = []
  J = []
  for _ in range(N):
    Ci, Ji = (int(x) for x in input().split())
    C.append(Ci)
    J.append(Ji)

  changes = set()

  for i in range(N):
    for j in range(i):
      deltaC = C[i] - C[j]
      deltaJ = J[i] - J[j]
      # print(C[i], J[i], '/', C[j], J[j], '/', deltaC, deltaJ)
      if deltaC == 0 or deltaJ == 0 or deltaC * deltaJ > 0:
        continue
      changes.add(Rational(deltaC, deltaJ))

  print('Case #{}: {}'.format(test, len(changes) + 1))

# Main

def main():
  T = int(input())

  for test in range(1, T+1):
    case(test)

if __name__ == '__main__':
  main()
