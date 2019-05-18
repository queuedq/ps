def main():
  T = int(input())
  for test in range(1, T+1):
    N, P = tuple(map(int, input().split()))
    languages = tuple(map(int, input().split()))
    for i in range(N):
      
    print("Case #{}: {}".format(test, bake(N, P, W, H)))

main()