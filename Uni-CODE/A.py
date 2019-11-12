T = int(input())

def calc():
  s = input()

  if len(s) != 7:
    return 0

  first = s[0]
  second = s[2]

  if first == second:
    return 0

  if (s[0] == first and s[1] == first and s[4] == first):
    if (s[2] == second and s[3] == second and s[5] == second and s[6] == second):
      return 1

  return 0

for t in range(T):
  print(calc())
