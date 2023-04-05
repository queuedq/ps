T = int(input())

def chrToNum(chr):
  return ord(chr) - ord(0)

def case(test):
  N = input()
  A = ''
  B = ''
  for digit in N:
    if digit == '4':
      A += '2'
      B += '2'
    else:
      A += digit
      B += '0'
  B = B.lstrip('0')

  print('Case #{}: {} {}'.format(test, A, B))

for test in range(1, T+1):
  case(test)
