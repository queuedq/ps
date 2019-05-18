class DisjointSet:
  def __init__(self, length):
    self.parent = list(range(length))
    self.size = [1] * length

  def find(self, x):
    # Reursive path compression
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

def mapping(i, j, C):
  return i * C + j

def main():
  R, C = [int(x) for x in input().split()]
  ## R, C = 4, 5
  dream = []
  for i in range(R):
    dream.append([0 if x == "B" else 1 for x in input()]) # W: 1, B: 0
  ## dream = [
    ## [0, 0, 1, 1, 1],
    ## [0, 1, 0, 1, 0],
    ## [1, 1, 1, 1, 1],
    ## [0, 1, 0, 0, 1]
  ## ]

  maxChunkSize = 0
  maxChunkRoot = 0
  maxChunks = None # DisjointSet

  colorPatterns = {0b1010: True, 0b0101: True, 0b1100: True, 0b0011: True,
                   0b1111: True, 0b0000: True} # Always available cases
  for i in range(1, R):
    for j in range(1, C):
      # c1 c2
      # c3 c4
      colorPatterns[(dream[i-1][j-1] << 3) + (dream[i-1][j] << 2) +
                    (dream[i][j-1] << 1) + (dream[i][j] << 0)] = True
  colorPatterns = colorPatterns.keys()

  print([bin(x)[2:] for x in colorPatterns])

  for originX in range(0, R + 1):
    for originY in range(0, C + 1):

      for pattern in colorPatterns:
        chunks = DisjointSet(R * C)
        # c1 c2
        # c3 c4
        c1 = (pattern >> 0) - (pattern >> 1 << 1)
        c2 = (pattern >> 1) - (pattern >> 2 << 1)
        c3 = (pattern >> 2) - (pattern >> 3 << 1)
        c4 = (pattern >> 3) - (pattern >> 4 << 1)
        
        invertedDream = [] # Invert black

        for i in range(0, R):
          invertedDream.append([])

          for j in range(0, C):
            # Invert black
            if i < originX and j < originY:
              invertColor = c1 == 0
            if i >= originX and j < originY:
              invertColor = c2 == 0
            if i < originX and j >= originY:
              invertColor = c3 == 0
            if i >= originX and j >= originY:
              invertColor = c4 == 0
            
            if invertColor:
              invertedDream[i].append(1 - dream[i][j])
            else:
              invertedDream[i].append(dream[i][j])

            if i > 0 and invertedDream[i - 1][j] == invertedDream[i][j] == 1: # Check white
              chunks.union(mapping(i - 1, j, C), mapping(i, j, C))
            if j > 0 and invertedDream[i][j - 1] == invertedDream[i][j] == 1: # Check white
              chunks.union(mapping(i, j - 1, C), mapping(i, j, C))
            
            ## if originX == 2 and originY == 2 and pattern == 0b1001:
              ## for ii in range(0, R):
                ## output = []
                ## for jj in range(0, C):
                  ## output.append(str(chunks.find(mapping(ii, jj, C))))
                ## print(' '.join(output))
              ## print()
        
        ## if originX == 2 and originY == 2 and pattern == 0b1001:
          ## for i in range(0, R):
            ## print(invertedDream[i])
          
          ## for i in range(0, R):
            ## output = []
            ## for j in range(0, C):
              ## output.append(str(chunks.find(mapping(i, j, C))))
            ## print(' '.join(output))

        localMaxChunkSize = 0
        localMaxChunkRoot = -1
        for i in range(0, R):
          for j in range(0, C):
            root = chunks.find(mapping(i, j, C))
            if chunks.size[root] > localMaxChunkSize:
              localMaxChunkSize = chunks.size[chunks.find(mapping(i, j, C))]
              localMaxChunkRoot = root

        if localMaxChunkSize > maxChunkSize:
          maxChunkSize = localMaxChunkSize
          maxChunkRoot = localMaxChunkRoot
          maxChunks = chunks
  
  ## for i in range(0, R):
    ## output = []
    ## for j in range(0, C):
      ## output.append(str(maxChunks.find(mapping(i, j, C))))
    ## print(' '.join(output))

  return maxChunkSize


T = int(input())
## T = 1

for test in range(1, T + 1):
  value = main()
  print('Case #{test}: {value}'.format(test=test, value=value))
