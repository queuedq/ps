N = int(input())

def transform(S):
  if S[-1] == 'a':
    return S[:-1] + 'as'
  if S[-1] == 'i' or S[-1] == 'y':
    return S[:-1] + 'ios'
  if S[-1] == 'l':
    return S[:-1] + 'les'
  if S[-1] == 'n':
    return S[:-1] + 'anes'
  if S[-2:] == 'ne':
    return S[:-2] + 'anes'
  if S[-1] == 'o':
    return S[:-1] + 'os'
  if S[-1] == 'r':
    return S[:-1] + 'res'
  if S[-1] == 't':
    return S[:-1] + 'tas'
  if S[-1] == 'u':
    return S[:-1] + 'us'
  if S[-1] == 'v':
    return S[:-1] + 'ves'
  if S[-1] == 'w':
    return S[:-1] + 'was'

  return S + 'us'


for i in range(N):
  S = input()
  print(transform(S))
