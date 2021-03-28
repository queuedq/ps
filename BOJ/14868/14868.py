## def print2d(arr):
##   print('[')
##   for e in arr:
##     print(e)
##   print(']')

class DisjointSet:
  def __init__(self, size):
    self.parent = list(range(size)) # Root is pointing itself
    self.size = [1] * size # For union by size

  def find(self, x):
    while x != self.parent[x]:
      self.parent[x] = self.parent[self.parent[x]]
      x = self.parent[x]
    return x

  def union(self, x, y):
    xRoot, yRoot = self.find(x), self.find(y)
    if xRoot == yRoot:
      return
    # Union by size
    if self.size[xRoot] < self.size[yRoot]:
      xRoot, yRoot = yRoot, xRoot
    self.parent[yRoot] = xRoot
    self.size[xRoot] = self.size[xRoot] + self.size[yRoot]

# Input
N, K = (int(x) for x in input().split())
x, y = [], []
for i in range(K):
  xx, yy = (int(x) for x in input().split())
  x.append(xx)
  y.append(yy)

def mapping(x, y): # Map to index of DisjointSet
  return (x-1) * N + (y-1)

def unmapping(index):
  return index % N + 1, index // N + 1

civilSet = DisjointSet(N * N) # Unified civil
year = 0
currentCivil = [] # Current year's new civil
isCivilized = [[False] * (N+2) for _ in range(N+2)]
for i in range(N+2):
  # Out of bound
  isCivilized[i][0] = None
  isCivilized[i][N+1] = None
  isCivilized[0][i] = None
  isCivilized[N+1][i] = None

for i in range(K):
  isCivilized[x[i]][y[i]] = True  # Initial civilization
  currentCivil.append((x[i], y[i]))

while True:
  # Unify civilizations
  for civ in currentCivil:
    civX = civ[0]
    civY = civ[1]
    if isCivilized[civX-1][civY]:
      civilSet.union(mapping(civX-1, civY), mapping(civX, civY))
    if isCivilized[civX+1][civY]:
      civilSet.union(mapping(civX+1, civY), mapping(civX, civY))
    if isCivilized[civX][civY-1]:
      civilSet.union(mapping(civX, civY-1), mapping(civX, civY))
    if isCivilized[civX][civY+1]:
      civilSet.union(mapping(civX, civY+1), mapping(civX, civY))

  ## print2d(isCivilized)
  ## civilView = [[civilSet.find(mapping(i, j)) for j in range(1, N+1)] for i in range(1, N+1)]
  ## print2d(civilView)

  # Count civilizations
  uniqueCivil = None
  for civ in currentCivil:
    civX = civ[0]
    civY = civ[1]
    if uniqueCivil is None:
      uniqueCivil = civilSet.find(mapping(civX, civY))
    elif uniqueCivil != civilSet.find(mapping(civX, civY)):
      uniqueCivil = -1
      break

  if uniqueCivil != -1:
    break

  # Prepare next year
  year += 1
  nextCivil = []
  for civ in currentCivil:
    civX = civ[0]
    civY = civ[1]
    if isCivilized[civX-1][civY] is not None and not isCivilized[civX-1][civY]:
      isCivilized[civX-1][civY] = True
      nextCivil.append((civX-1, civY))
    if isCivilized[civX+1][civY] is not None and not isCivilized[civX+1][civY]:
      isCivilized[civX+1][civY] = True
      nextCivil.append((civX+1, civY))
    if isCivilized[civX][civY-1] is not None and not isCivilized[civX][civY-1]:
      isCivilized[civX][civY-1] = True
      nextCivil.append((civX, civY-1))
    if isCivilized[civX][civY+1] is not None and not isCivilized[civX][civY+1]:
      isCivilized[civX][civY+1] = True
      nextCivil.append((civX, civY+1))

  currentCivil = nextCivil

print(year)
