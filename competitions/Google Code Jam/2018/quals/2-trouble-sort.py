T = int(input())

for test in range(1, T+1):
  N = int(input())
  V = list(map(int, input().split()))
  even = V[::2]
  odd = V[1::2]

  even.sort()
  odd.sort()
  # print(even, odd)

  ok = True

  for i in range(N - 1):
    index = i // 2

    if i % 2 == 0:
      current_num = even[index]
      next_num = odd[index]
    else:
      current_num = odd[index]
      next_num = even[index + 1]

    if current_num > next_num:
      ok = False
      break

  if ok:
    print("Case #{}: OK".format(test))
  else:
    print("Case #{}: {}".format(test, i))
