N = int(input())

effect = [[] for _ in range(N)]
color = [[] for _ in range(N)]

for i in range(N):
  for row in range(4):
    effect[i].append([int(i) for i in input().split()])

  for row in range(4):
    color[i].append([int(i) for i in input().split()])

def calculate_score(i, j, k, pos_i, pos_j, pos_k):
  pot_effect = [[None for _ in range(5)] for _ in range(5)]
  pot_color = [[None for _ in range(5)] for _ in range(5)]
  for x in range(5):
    for y in range(5):
      pot_effect[x][y] +=


max_score = 0

for i in range(N):
  for j in range(N):
    if (j == i):
      break
    for k in range(N):
      if (k == i or k == j):
        break
      for pos_i in [(0, 0), (0, 1), (1, 0), (1, 1)]:
        for pos_j in [(0, 0), (0, 1), (1, 0), (1, 1)]:
          for pos_k in [(0, 0), (0, 1), (1, 0), (1, 1)]:
            score = calculate_score(i, j, k, pos_i, pos_j, pos_k)
            if (score > max_score):
              max_score = score

print(max_score)
