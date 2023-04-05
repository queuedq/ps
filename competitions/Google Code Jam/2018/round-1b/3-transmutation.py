def make(i, formula, G):
  if formula[i][0] != 0 and formula[i][1] != 0:
    G[i] += 1
    G[formula[i][0]] -= 1
    G[formula[i][1]] -= 1
    return 1
  else:
    G[formula[i][0]] == 0:
      



def main():
  T = int(input())
  for test in range(1, T+1):
    M = int(input())
    formula = []
    for i in range(M):
      formula.append( tuple(map(int, input().split())) )
    G = list(map(int, input().split()))

      
    print("Case #{}: {}".format(test, bake(N, P, W, H)))

main()