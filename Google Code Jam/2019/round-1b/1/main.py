class Person():
  def __init__(self, x, y, direction):
    self.x = x
    self.y = y
    self.direction = direction

  def __str__(self):
    return '{{x:{}, y:{}, d:{}}}'.format(self.x, self.y, self.direction)

  def hKey(self):
    if self.direction == 'W':
      return (self.x, 0)
    elif self.direction == 'E':
      return (self.x + 1, 1)
    else:
      raise Exception('Only sort horizontal people')

  def vKey(self):
    if self.direction == 'S':
      return (self.y, 0)
    elif self.direction == 'N':
      return (self.y + 1, 1)
    else:
      raise Exception('Only sort vertical people')

def case(test):
  P, Q = (int(x) for x in input().split())
  people = []
  hPeople = []
  vPeople = []
  for person in range(P):
    rawPerson = input().split() # X_i, Y_i, D_i
    x = int(rawPerson[0])
    y = int(rawPerson[1])
    d = rawPerson[2]
    people.append(Person(x, y, d))
    if d == 'W' or d == 'E':
      hPeople.append(Person(x, y, d))
    else:
      vPeople.append(Person(x, y, d))

  hPeople.sort(key=lambda p: p.hKey())
  vPeople.sort(key=lambda p: p.vKey())


  hMaxPos = 0
  hMaxValue = 0
  hRight = 0
  for p in hPeople:
    if p.direction == 'W':
      hMaxValue += 1
    else:
      hRight += 1
      if (hRight > hMaxValue):
        hMaxPos = p.x + 1
        hMaxValue = hRight

  vMaxPos = 0
  vMaxValue = 0
  vUp = 0
  for p in vPeople:
    if p.direction == 'S':
      vMaxValue += 1
    else:
      vUp += 1
      if (vUp > vMaxValue):
        vMaxPos = p.y + 1
        vMaxValue = vUp

  print('Case #{}: {} {}'.format(test, hMaxPos, vMaxPos))

T = int(input())

for test in range(1, T+1):
  case(test)
