import math

N = int(input())

output = N

N = N - 1
for i in range(1, int(math.sqrt(N)) + 1):
  output += (N // i - i) * 2

output += int(math.sqrt(N))
print(output)
