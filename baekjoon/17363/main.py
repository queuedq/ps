N, M = (int(x) for x in input().split())

pic = []
mapping = {'.': '.', 'O': 'O', '-': '|', '|': '-', '/': '\\', '\\': '/', '^': '<', '<': 'v', 'v': '>', '>': '^'}
for i in range(N):
  pic.append(input())

newpic = []
for i in range(M):
  newpic.append([])
  for j in range(N):
    newpic[i].append(mapping[pic[j][M - i - 1]])
  print(''.join(newpic[i]))

