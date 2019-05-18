def case(test):
  print(200, flush=True)
  total = int(input())
  R4 = total // 2**50
  R5 = (total - R4 * 2**50) // 2**40
  R6 = (total - R4 * 2**50 - R5 * 2**40) // 2**33

  print(50, flush=True)
  total = int(input())
  total -= R4 * 2**12 + R5 * 2**10 + R6 * 2**8
  R1 = total // 2**50
  R2 = (total - R1 * 2**50) // 2**25
  R3 = (total - R1 * 2**50 - R2 * 2**25) // 2**16

  print(R1, R2, R3, R4, R5, R6)
  result = int(input())
  if (result != 1):
    exit()

T, W = (int(x) for x in input().split())

for test in range(1, T+1):
  case(test)
