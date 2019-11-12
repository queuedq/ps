T = int(input())

for test in range(T):
  h, m, s = (int(x) for x in input().split())
  hh = h * 30 + m / 2 + s / 120
  mm = m * 6 + s / 10
  ss = s * 6
  a = abs(hh - mm)
  b = abs(mm - ss)
  c = abs(ss - hh)
  a = min(a, 360 - a)
  b = min(b, 360 - b)
  c = min(c, 360 - c)

  print(min(a, b, c))
