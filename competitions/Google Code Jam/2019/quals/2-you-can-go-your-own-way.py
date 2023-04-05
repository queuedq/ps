T = int(input())

def case(test):
  N = input()
  moves = input()
  result = []
  for move in moves:
    if move == 'S':
      result.append('E')
    else:
      result.append('S')

  print('Case #{}: {}'.format(test, ''.join(result)))

for test in range(1, T+1):
  case(test)
