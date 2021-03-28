A = input()

cnt = 0
for i in range(len(A)):
  if (A[i] != ' '):
    cnt += 1
if cnt == 1:
  print('proper')
  exit()

A = '(' + A + ')'
S = []

error = False
improper = False

for i in range(len(A)):
  if (A[i] == ' '):
    continue

  elif (A[i] == ')'):
    operand = True
    match = False
    cnt = 0

    while len(S) > 0:
      if S[-1] == '(':
        if operand:
          # print('E0')
          error = True
        match = True
        S.pop()
        break

      if operand:
        if 'a' <= S[-1] <= 'z':
          cnt += 1
        else:
          # print('E1')
          error = True
      else:
        if S[-1] not in '+-*/%':
          # print('E2')
          error = True

      S.pop()
      operand = not operand

    if not match:
      # print('E3')
      error = True
    if cnt != 2:
      improper = True

    S.append('a')

  else:
    S.append(A[i])

if S != ['a']:
  # print('E4')
  error = True

if error:
  print('error')
elif improper:
  print('improper')
else:
  print('proper')
