import math
import fractions

# References
# Search term: "smallest denominator fraction between two numbers"
#
# [1] https://math.stackexchange.com/questions/115621/how-to-find-a-simple-fraction-between-two-other-fractions
# The main algorithm reference
#
# [2] https://en.wikipedia.org/wiki/Continued_fraction#Best_rational_within_an_interval
# This suggests a wrong algorithm.
#
# [3] https://en.wikipedia.org/wiki/Stern%E2%80%93Brocot_tree
# This helps understanding why the algorithm works

F = fractions.Fraction

def gcd(a, b):
  """Calculates the gcd of a and b."""
  r0, r1 = abs(a), abs(b)
  while r1 > 0:
    r0, r1 = r1, r0 % r1
  return r0

def extendedGcd(a, b):
  """Computes the extended Euclidean algorithm.

  It returns a tuple `(g, x, y)` satisfying `g = a x + b y = gcd(a, b)`
  """
  r0, r1 = abs(a), abs(b)
  x0, x1 = 1, 0
  y0, y1 = 0, 1
  expansion = []
  while r1 > 0:
    # Invariant formula: r = a x + b y
    # Since r goes to gcd(a, b), the return value (r, x, y) satisfies
    # r = a x + b y = gcd(a, b)
    q = r0 // r1
    if r0 != r1 or len(expansion) == 0:
      expansion.append(q)
    else:
      # Remove the final 1 in the continued fraction
      expansion[-1] += 1
    r0, r1 = r1, r0 - q * r1
    x0, x1 = x1, x0 - q * x1
    y0, y1 = y1, y0 - q * y1
  return (r0, x0, y0, expansion)


class ContinuedFraction():
  def __init__(self, expansion):
    self.expansion = expansion

  @staticmethod
  def fromRational(r):
    expansion = extendedGcd(r.numerator, r.denominator)[3]
    if r.numerator < 0:
      expansion[0] = -expansion[0]
    return ContinuedFraction(expansion)

  def toRational(self):
    rev = self.expansion[::-1]
    n, d = 1, 0
    for t in rev:
      n, d = n * t + d, n
    return F(n, d)

  def __eq__(self, other):
    return self.toRational() == other.toRational()

  def __lt__(self, other):
    return self.toRational() < other.toRational()

  def __gt__(self, other):
    return self.toRational() > other.toRational()

  @staticmethod
  def combine(a, b):
    until = min(len(a.expansion), len(b.expansion))
    common = 0
    for i in range(until):
      if a.expansion[i] == b.expansion[i]:
        common += 1
      else:
        break

    if common < until:
      lastTerm = min(a.expansion[common], b.expansion[common]) + 1
      expected = ContinuedFraction(a.expansion[:common] + [lastTerm])
      if a < expected < b or b < expected < a:
        return expected

      return ContinuedFraction.fromRational(
        F(
          a.toRational().numerator + b.toRational().numerator,
          a.toRational().denominator + b.toRational().denominator
        )
      )

    if common < len(a.expansion):
      return ContinuedFraction(a.expansion[:common] + [a.expansion[common] + 1])

    if common < len(b.expansion):
      return ContinuedFraction(b.expansion[:common] + [b.expansion[common] + 1])


FF = ContinuedFraction


# Each test case
def case(test):
  N = int(input())
  C = []
  J = []
  for _ in range(N):
    Ci, Ji = (int(x) for x in input().split())
    C.append(Ci)
    J.append(Ji)

  lowerSlope = 0
  upperSlope = None

  for i in range(1, N):
    deltaC = C[i] - C[i - 1]
    deltaJ = J[i] - J[i - 1]
    # print(C[i], J[i], '/', deltaC, deltaJ)

    if deltaC <= 0 and deltaJ <= 0:
      print('Case #{}: IMPOSSIBLE'.format(test))
      return
    elif deltaC >= 0 and deltaJ >= 0:
      continue

    slope = F(-deltaC, deltaJ)
    if deltaJ > 0 and slope > lowerSlope:
      lowerSlope = slope
    elif deltaJ < 0 and (upperSlope == None or slope < upperSlope):
      upperSlope = slope
    # print(slope, lowerSlope, upperSlope)

  if upperSlope == None:
    upperSlope = lowerSlope + 2

  if lowerSlope >= upperSlope:
    print('Case #{}: IMPOSSIBLE'.format(test))
    return

  # print('slopes', lowerSlope, upperSlope)

  slope = ContinuedFraction.combine(
    ContinuedFraction.fromRational(lowerSlope),
    ContinuedFraction.fromRational(upperSlope)
  ).toRational()

  # Small

  # n, d = 0, 1
  # while d <= 300:
  #   n = math.floor(lowerSlope * d) + 1
  #   if F(n, d) < upperSlope:
  #     break
  #   d += 1

  print('Case #{}: {} {}'.format(test, slope.denominator, slope.numerator))

# Main

def main():
  T = int(input())

  for test in range(1, T+1):
    case(test)

if __name__ == '__main__':
  main()
