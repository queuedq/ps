from collections import deque

def fillWaterBottle(a, b, c, d):
  if not (c == 0 or c == a or d == 0 or d == b): # One of them is full or empty
    return -1

  distance = {(0, 0): 0}
  objectState = (c, d)

  queue = deque()
  queue.append((0, 0))
  while len(queue) > 0:
    start = queue.popleft()
    if start == objectState:
      break
    dist = distance[start]

    emptyA = (0, start[1])
    emptyB = (start[0], 0)
    fillA = (a, start[1])
    fillB = (start[0], b)
    moveAToB = (0, start[0] + start[1]) \
        if start[0] + start[1] <= b \
        else (start[0] + start[1] - b, b)
    moveBToA = (start[0] + start[1], 0) \
        if start[0] + start[1] <= a \
        else (a, start[1] + start[0] - a)

    if emptyA not in distance:
      distance[emptyA] = dist + 1
      queue.append(emptyA)
    if emptyB not in distance:
      distance[emptyB] = dist + 1
      queue.append(emptyB)
    if fillA not in distance:
      distance[fillA] = dist + 1
      queue.append(fillA)
    if fillB not in distance:
      distance[fillB] = dist + 1
      queue.append(fillB)
    if moveAToB not in distance:
      distance[moveAToB] = dist + 1
      queue.append(moveAToB)
    if moveBToA not in distance:
      distance[moveBToA] = dist + 1
      queue.append(moveBToA)

  if objectState in distance:
    return distance[objectState]
  else:
    return -1

a, b, c, d = (int(x) for x in input().split())
print(fillWaterBottle(a, b, c, d))
