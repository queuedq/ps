S = input()
N = len(S)
Q = int(input())
queries = []
for i in range(Q):
  queries.append(input())


# solve
sid = [1] * N
last_sid = 1

for i in range(Q):
  q = int(queries[i][0])
  if q == 1:
    _, x, y = queries[i].split()
    x, y = int(x)-1, int(y)-1
    # if sid[x] == sid[y]:
    #   print("YES")
    # else:
    #   print("NO")

  elif q == 2:
    _, x, word = queries[i].split()
    x = int(x)-1
    s = sid[x]
    last_sid += 1
    for i in range(N):
      if sid[i] == s and S[i] in word:
        sid[i] = last_sid

  elif q == 3:
    _, x, y, word = queries[i].split()
    x, y = int(x)-1, int(y)-1
    last_sid += 1
    for i in range(x, y+1):
      if S[i] in word:
        sid[i] = last_sid
  
  elif q == 4:
    _, x, y = queries[i].split()
    x, y = int(x)-1, int(y)-1
    sx, sy = sid[x], sid[y]
    s = min(sid[x], sid[y])
    for i in range(N):
      if sid[i] == sx or sid[i] == sy:
        sid[i] = s
  
  elif q == 5:
    pass

  print(' '.join(str(s) for s in sid))
