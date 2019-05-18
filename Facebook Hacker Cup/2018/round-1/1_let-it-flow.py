def flow():
  N = int(input())
  cells = []
  for _ in range(3):
    cells.append(list(input()))

  if N % 2 == 1:
    return 0

  if cells[0][0] == '#' or cells[1][0] == '#':
    return 0

  if cells[1][-1] == '#' or cells[2][-1] == '#':
    return 0

  exponent = 0

  for i in range(1, N-1, 2):
    if cells[0][i] == '.' and cells[1][i] == '.' and cells[2][i] == '.' and \
        cells[0][i+1] == '.' and cells[1][i+1] == '.' and cells[2][i+1] == '.':
      exponent += 1
    elif cells[0][i] == '.' and cells[1][i] == '.' and \
        cells[0][i+1] == '.' and cells[1][i+1] == '.':
      pass
    elif cells[1][i] == '.' and cells[2][i] == '.' and \
        cells[1][i+1] == '.' and cells[2][i+1] == '.':
      pass
    else:
      return 0

  return 2**exponent % 1000000007


T = int(input())

for test in range(1, T+1):
  print('Case #{}: {}'.format(test, flow()))
