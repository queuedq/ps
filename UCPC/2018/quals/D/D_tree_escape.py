# Wrong code, don't know why

from collections import deque

N = int(input())
edge = [[] for _ in range(N+1)]

for _ in range(N-1):
  a, b = (int(x) for x in input().split())
  edge[a].append(b)
  edge[b].append(a)

# DFS
stack = [(1, 0)] # (node, distance)
visited = [False for _ in range(N+1)]

win = False

while(len(stack) > 0):
  node, distance = stack.pop()
  cnt_unvisited = 0
  for adjacent in edge[node]:
    if not visited[adjacent]:
      stack.append((adjacent, distance + 1))
      visited[adjacent] = True
      cnt_unvisited += 1
  if cnt_unvisited == 0: # Leaf node
    ## print('({}, {})'.format(node, distance))
    win ^= (distance % 2 == 1)

if win:
  print('Yes')
else:
  print('No')
