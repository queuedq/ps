import math

N, K = [int(x) for x in input().split()]
array = [int(x) for x in input().split()]

def avg(arr):
  return sum(arr)/len(arr)

def stddev(arr):
  m = avg(arr)
  return math.sqrt(sum([(x - m) ** 2 for x in arr]) / len(arr))

minStddev = 987654321

for l in range(N + 1):
  for r in range(l + K, N + 1):
    d = stddev(array[l:r])
    if d < minStddev:
      minStddev = d

print(minStddev)
