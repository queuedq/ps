def main():
  T = int(input())
  for test in range(1, T+1):
    S = int(input())
    D, A, B, M, N = [], [], [], [], []
    for i in range(S):
      d, a, b = tuple(map(int, input().split()))
      D.append(d)
      A.append(a)
      B.append(b)
      M.append(d+a)
      N.append(d-b)

    # print(M)
    # print(N)
    longestA = [(1, -1)] # Length, N-depending position
    longestB = [(1, -1)] # Length, M-depending position
    longest = [1]

    for i in range(1, S):
      prevA = longestA[i-1][0]
      dependingN = longestA[i-1][1]
      prevB = longestB[i-1][0]
      dependingM = longestB[i-1][1]
      m = M[i]
      n = N[i]
      if m == M[i-1]:
        longestA.append((prevA+1, dependingN))
      else:
        if dependingM == -1 or M[dependingM] == m:
          longestA.append((prevB+1, i-1))
        else:
          longestA.append((i-dependingM, i-1))

      if n == N[i-1]:
        longestB.append((prevB+1, dependingM))
      else:
        if dependingN == -1 or N[dependingN] == n:
          longestB.append((prevA+1, i-1))
        else:
          longestB.append((i-dependingN, i-1))

      # print(longestA[i], N[longestA[i][1]], longestB[i], M[longestB[i][1]])
      longest.append(max(longestA[i][0], longestB[i][0]))

    maxLength = max(longest)
    count = longest.count(maxLength)
    # print(maxLength, count)
      
    print("Case #{}: {} {}".format(test, maxLength, count))

main()