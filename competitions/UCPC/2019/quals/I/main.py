N = int(input())

grid = [None] * 100
for i in range(100):
  grid[i] = [None] * 100
  for j in range(100):
    grid[i][j] = False

def move(ant, d):
  (i, j) = ant
  if i % 2 == 0:
    if d == 0:
      return (i + 1, j)
    if d == 1:
      return (i - 1, j)
    if d == 2:
      return (i - 1, j - 1)
  else:
    if d == 0:
      return (i - 1, j)
    if d == 1:
      return (i + 1, j)
    if d == 2:
      return (i + 1, j + 1)

def count(moves, ant, d):
  # print('count', moves, ant, d)
  (i, j) = ant

  if moves > N:
    return 0

  if grid[i][j]:
    if moves == N:
      return 1
    else:
      return 0

  subcount = 0
  grid[i][j] = True

  for dd in range(3):
    if dd == d:
      continue
    subcount += count(moves + 1, move(ant, dd), dd)

  grid[i][j] = False

  return subcount


grid[50][50] = True
initant = (50, 50)

print(count(0, move((50, 50), 0), 0))
