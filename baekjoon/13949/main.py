from collections import deque

K, N = [int(x) for x in input().split()]

Q = deque([(0, 0, 1)])
vst = {(0, 0, 1)}
used = set()
ans = []

while N > 0:
  a, b, c = Q.popleft()
  if all(x > 0 and x not in used for x in [a, b, c]):
    if a != b and b != c and c != a:
      ans.append((a, b, c))
      used.update([a, b, c])
      N -= 1
  aa = K * (b+c) - a
  bb = K * (c+a) - b
  cc = K * (a+b) - c
  for x in [(aa, b, c), (a, bb, c), (a, b, cc)]:
    x = tuple(sorted(x))
    if x in vst or x[0] < 0: continue
    Q.append(x)
    vst.add(x)

for (a, b, c) in ans:
  print(a, b, c)
