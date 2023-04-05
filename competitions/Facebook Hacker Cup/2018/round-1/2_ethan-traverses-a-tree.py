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

def traverse(node, left, right, pre, post):
  if node == 0:
    return
  pre.append(node)
  traverse(left[node], left, right, pre, post)
  traverse(right[node], left, right, pre, post)
  post.append(node)


def ethan():
  N, K = (int(x) for x in input().split())
  left, right = [0], [0]
  for node in range(N):
    l, r = (int(x) for x in input().split())
    left.append(l)
    right.append(r)

  pre, post = [], []

  traverse(1, left, right, pre, post)

  ## print(N, K)
  ## print(pre)
  ## print(post)

  labels = DisjointSet(N+1)
  for i in range(N):
    labels.union(pre[i], post[i])

  labelMapping = [None] * (N+1)
  cnt = 0
  for i in range(1, N+1):
    root = labels.find(i)
    if labelMapping[root] is None:
      cnt += 1
      if cnt > K:
        cnt = K
      labelMapping[root] = cnt
      labelMapping[i] = cnt
    else:
      labelMapping[i] = labelMapping[root]

  if cnt < K:
    return 'Impossible'
  else:
    return ' '.join([str(x) for x in labelMapping[1:]])


T = int(input())

for test in range(1, T+1):
  print('Case #{}: {}'.format(test, ethan()))
