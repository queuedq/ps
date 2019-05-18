import random

N = 500000
print(N)
nodes = [i for i in range(1, N+1)]
visited = []
random.shuffle(nodes)

visited.append(nodes.pop())

for _ in range(N-1):
  nextNode = nodes.pop()
  print('{} {}'.format(random.choice(visited), nextNode))
  visited.append(nextNode)
