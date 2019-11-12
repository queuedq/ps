unist = [None, [], [], [], [] ,[]]

for i in range(1, 6):
  for j in range(5 - i + 1):
    unist[i].append("UNIST"[j:i+j])

# print(unist)
# [None, ['U', 'N', 'I', 'S', 'T'], ['UN', 'NI', 'IS', 'ST'], ['UNI', 'NIS', 'IST'], ['UNIS', 'NIST'], ['UNIST']]

N = int(input())
W = []

for i in range(N):
  word = input()
  p = ""
  for j in range(5, 0, -1):
    if word[:j] in unist[j]:
      p = word[:j]
      break
  if p != "":
    W.append((unist[j].index(p), j))

# print(W)

D = [[1, 0, 0, 0, 0, 0]]
for i in range(len(W)):
  D.append(D[-1].copy())
  for j in range(W[i][0] + 1, W[i][0] + W[i][1] + 1):
    D[-1][j] = (D[-1][j] + D[-2][W[i][0]]) % 1000000007

# print(D)
print(D[-1][5])
