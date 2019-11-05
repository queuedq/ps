import math

N = int(input())
k, p = [int(x) for x in input().split()]
p = p

def current_level(p):
  return math.floor(math.log(p, 2))

def num_ancestors(p):
  return current_level(p)

def is_ancestor(p, q):
  while p <= q:
    if p == q:
      return True
    else:
      q = q // 2
  return False

order = [None] * (N + 1)

def fill_ancestors(k, p):
  anc = num_ancestors(p)
  p //= 2
  i = anc
  if k <= i:
    return -1
  while p > 0:
    order[p] = i
    p //= 2
    i -= 1
  return anc

def fill_subtree(k, p):
  l = p
  r = p
  i = k
  while l <= N:
    for pos in range(l, min(r, N) + 1):
      order[pos] = i
      i += 1
    l = l * 2
    r = r * 2 + 1

  if i > N + 1:
    return -1
  else:
    return i

def next(i, k, sub):
  if i + 1 >= k and i + 1 < sub:
    return sub
  else:
    return i + 1

def fill_none(anc, k, sub):
  i = next(anc, k, sub)
  for pos in range(1, N + 1):
    if order[pos] == None:
      order[pos] = i
      i = next(i, k, sub)

def main():
  anc = fill_ancestors(k, p)
  sub = fill_subtree(k, p)
  if anc > -1 and sub > -1:
    fill_none(anc, k, sub)
  else:
    return -1

  return '\n'.join(map(str, order[1:]))

print(main())
