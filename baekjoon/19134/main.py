def solve(n, b):
  if (n <= 3):
    return n*b
  return solve((n-2)//2, 1-b) + (n - (n-2)//2 if b else 0)

n = int(input())
print(solve(n, 1))
