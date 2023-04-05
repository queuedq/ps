S = input()
L = int(input())

numbers = []
for i in range(len(S) + 1):
  numbers.append([])
  for j in range(L + 1):
    numbers[i].append([0] * (L + len(S) + 2))

def get_number(s, t, open_parens):
  if open_parens < 0 or s < 0 or t < 0:
    return 0
  if open_parens > s + t:
    return 0
  return numbers[s][t][open_parens]


numbers[0][0][0] = 1

for i in range(len(S) + L + 1):
  for j in range(i + 1):
    s = i - j
    t = j
    if s > len(S) or t > L or (s == 0 and t == 0):
      continue
    for k in range(s + t + 1):
      print(s, t, k)
      if (s == 0 and t == 1 and k == 1):
        print(get_number(s - 1, t, k - 1) + get_number(s, t - 1, k - 1) + get_number(s, t - 1, k + 1))
      if S[s - 1] == '(':
        numbers[s][t][k] = get_number(s - 1, t, k - 1) + get_number(s, t - 1, k - 1) + get_number(s, t - 1, k + 1)
      if S[s - 1] == ')':
        numbers[s][t][k] = get_number(s - 1, t, k + 1) + get_number(s, t - 1, k - 1) + get_number(s, t - 1, k + 1)

for i in range(len(S) + 1):
  for j in range(L + 1):
    print(i, j, numbers[i][j])

print(get_number(len(S), L, 0))
