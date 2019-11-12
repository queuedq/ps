N = int(input())
stops = [0] * N

for i in range(N - 1):
  a, b = (int(x) for x in input().split())
  stops[a] += 1
  stops[b] += 1

leaves = 0

for i in range(N):
  if stops[i] == 1:
    leaves += 1

print((leaves + 1) // 2)
