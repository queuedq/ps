import math

class Point():
  def __init__(self, x, y):
    self.x = x
    self.y = y

  def __str__(self):
    return '{{x:{}, y:{}}}'.format(self.x, self.y)

  def distanceFromOrigin(self):
    return math.sqrt(self.x ** 2 + self.y ** 2)

# Each test case
def case(test):
  N, K = (int(x) for x in input().split())

  pass

  print('Case #{}: {} {}'.format(test, N, K))

# Main

def main():
  T = int(input())

  for test in range(1, T+1):
    case(test)

if __name__ == '__main__':
  main()
