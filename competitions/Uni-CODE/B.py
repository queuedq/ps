N = int(input())
nodes = {'Baba': []}
result = []
visited = {}

def getInput():
  for i in range(N):
    s = input()
    ss = s.split()
    p = ss[0]
    q = ss[2]
    if p in nodes:
      nodes[p].append(q)
    else:
      nodes[p] = [q]
    if q not in nodes:
      nodes[q] = []

def DFS():
  stack = ['Baba']
  while len(stack) > 0:
    current = stack.pop()
    if current in visited:
      continue
    visited[current] = True
    if current != 'Baba':
      result.append(current)
    for nextNode in nodes[current]:
      stack.append(nextNode)

################################################################

def main():
  getInput()
  DFS()
  result.sort()
  for i in result:
    print(i)

if __name__ == "__main__":
  main()
