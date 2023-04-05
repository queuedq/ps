class DisjointSet:
  def __init__(self, totalSize):
    self.parent = list(range(totalSize))
    self.size = [1] * totalSize

  def find(self, x):
    while x != self.parent[x]:
      x = self.parent[x]
      self.parent[x] = self.parent[self.parent[x]]
    return x

  def union(self, x, y):
    xRoot = self.find(x)
    yRoot = self.find(y)

    if self.size[xRoot] < self.size[yRoot]:
      xRoot, yRoot = yRoot, xRoot

    self.parent[yRoot] = xRoot
    self.size[xRoot] = self.size[xRoot] + self.size[yRoot]

  def __str__(self):
    return str(self.parent)

mod = 1000000007

def add(a, b):
  return (a + b) % mod

def mul(a, b):
  return (a * b) % mod

def inv(a):
  m0 = mod
  y = 0
  x = 1

  while (a > 1) :
    q = a // mod

    t = mod

    mod = a % mod
    a = t
    t = y

    y = x - q * y
    x = t

  if (x < 0) :
    x = x + m0

  return x

def div(a, b):
  return mul(a, inv(b))

def stripHeight(h, a, b):
  if h < a:
    return a
  if h > b:
    return b
  return h


def zombie():
  N, M = (int(x) for x in input().split())
  A, B = [], []
  zombies = [0] * N

  for i in range(N-1):
    a, b = (int(x) for x in input().split())
    A.append(a)
    B.append(b)
  for i in range(M):
    y, h = (int(x) for x in input().split())
    prevHeight = zombies[y - 1]
    if h > prevHeight:
      zombies[y - 1] = h

  ## print(zombies)

  visibleZombieHeights = []  # array of stacks, decreasing
  lastYard = 0  # first visible zombie position
  probsTallerZombies = []  # yard array of "array of prob of some zombies taller than visible zombie being able to reach that yard"
  # TODO: case 0

  for i in range(1, N):  # iterate through yard
    if zombies[i] == 0:  # no zombie
      heights = visibleZombieHeights[i-1]
      probs = probsTallerZombies[i-1]
      intervals = []  # decreasing height
      if len(heights) == 0:
        intervals.append(B[i] - A[i] + 1)
      if len(heights) > 0:
        intervals.append( B[i] - stripHeight(heights[0]) )
        for v in range(len(heights) - 1):
          intervals.append( stripHeight(heights[v]) - stripHeight(heights[v+1]) )
        intervals.append( stripHeight(heights[-1]) - A[i] + 1 )

      assert(len(heights) + 1 == len(intervals))
      assert(len(probs) == len(intervals))

      intervalProbs = []
      for v in range(len(intervals)):
        intervalProbs.append( div(intervals[v], B[i] - A[i] + 1) )

      assert(len(intervalProbs) == len(intervals))

      newHeights = heights

      newProbs = []
      for v in range(len(intervals)):  # TODO: un-naive-ify
        newProbs.append(0)
        for t in range(len(intervals)):
          if t < v:
            newProbs = add( newProbs[v], mul(probs[v], intervalProbs[t]) )
          else:
            newProbs = add( newProbs[v], mul(probs[v], intervalProbs[v]) )

      visibleZombieHeights.append(newHeights)
      probsTallerZombies.append(newProbs)

    else:
      newZombie = zombies[i]

      heights = [ z for z in visibleZombieHeights[i-1] if z > newZombie ]
      probs = probsTallerZombies[i-1][:len(heights)]
      intervals = []  # decreasing height
      if len(heights) == 0:
        intervals.append(B[i] - A[i] + 1)
      if len(heights) > 0:
        intervals.append( B[i] - stripHeight(heights[0]) )
        for v in range(len(heights) - 1):
          intervals.append( stripHeight(heights[v]) - stripHeight(heights[v+1]) )
        intervals.append( stripHeight(heights[-1]) - A[i] + 1 )

      assert(len(heights) + 1 == len(intervals))
      assert(len(probs) == len(intervals))

      intervalProbs = []
      for v in range(len(intervals)):
        intervalProbs.append( div(intervals[v], B[i] - A[i] + 1) )

      assert(len(intervalProbs) == len(intervals))

      newHeights = heights

      newProbs = []
      for v in range(len(intervals)):  # TODO: un-naive-ify
        newProbs.append(0)
        for t in range(len(intervals)):
          if t < v:
            newProbs = add( newProbs[v], mul(probs[v], intervalProbs[t]) )
          else:
            newProbs = add( newProbs[v], mul(probs[v], intervalProbs[v]) )

      visibleZombieHeights.append(newHeights)
      probsTallerZombies.append(newProbs)

      blockProbs = [None] * i
      for j in range(i, lastYard + 1, -1):







T = int(input())

for test in range(1, T+1):
  print('Case #{}: {}'.format(test, zombie()))
