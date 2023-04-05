T = int(input())

for test in range(1, T+1):
  D, P = input().split()
  D = int(D)

  damage_list = [0]
  current_damage = 0
  total_damage = 0

  for c in P:
    if c == "S":
      damage_list[current_damage] += 1
      total_damage += 2 ** current_damage
    else:
      current_damage += 1
      damage_list.append(0)

  excess = total_damage - D

  inverse_sum = [damage_list[-1]]

  for i in range(1, len(damage_list)):
    sum = inverse_sum[i - 1] + damage_list[len(damage_list) - 1 - i]
    inverse_sum.append(sum)

  # print(inverse_sum)

  hacks = 0

  for i in range(len(inverse_sum) - 1):
    # print(excess, hacks)
    if excess <= 0:
      break
    if inverse_sum[i] * 2 ** (len(inverse_sum) - 2 - i) > excess:
      hacks += -( -excess // 2 ** (len(inverse_sum) - 2 - i) )
      excess = 0
    else:
      hacks += inverse_sum[i]
      excess -= inverse_sum[i] * 2 ** (len(inverse_sum) - 2 - i)

  if excess > 0:
    print("Case #" + str(test) + ": IMPOSSIBLE")
  else:
    print("Case #" + str(test) + ": " + str(hacks))
