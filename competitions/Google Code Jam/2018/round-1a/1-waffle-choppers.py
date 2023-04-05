def chop(R, C, H, V, chips, chips_row_count):
  # print(chips) # debug
  # print(chips_row_count) # debug
  all_chips = sum(chips_row_count)

  possible_divisibility = all_chips % (H+1) == 0 and\
                          all_chips % (V+1) == 0 and\
                          all_chips % ((H+1) * (V+1)) == 0

  if all_chips == 0:
    # print("Zero chips") # debug: result
    return "POSSIBLE"
  if not possible_divisibility:
    # print("Not divisible") # debug: result
    return "IMPOSSIBLE"

  h_cuts = []
  cnt = 0
  possible_h = True

  for i in range(R):
    cnt += chips_row_count[i]
    if cnt == all_chips // (H + 1):
      h_cuts.append(i)
      cnt = 0
    elif cnt > all_chips // (H + 1):
      possible_h = False
      break

  if not possible_h:
    # print("Horizontal cut is impossible") # debug: result
    return "IMPOSSIBLE"

  # assert(len(h_cuts) == H + 1)
  if not len(h_cuts) == H + 1: # assertion
    # print("Error: Not H horizontal cuts") # debug: result
    return "IMPOSSIBLE"

  # Last horizontal cut should be at last row
  h_cuts[-1] = R - 1

  v_cuts = []
  cnt = [0] * (H + 1)
  possible_v = True

  for i in range(C):
    current_h_cut = 0

    # Count chips in each horizontal divisions until column i
    for j in range(R):
      # print(current_h_cut, j, h_cuts) # debug
      if chips[j][i]:
        cnt[current_h_cut] += 1
      if j == h_cuts[current_h_cut]:
        current_h_cut += 1
        if current_h_cut >= H + 1: # assertion
          current_h_cut = H

    # Check whether vertical cut should be made at column i
    v_cut_finish = True

    for h_cut in range(H + 1):
      if cnt[h_cut] < all_chips // ((H+1) * (V+1)):
        v_cut_finish = False
        continue
      elif cnt[h_cut] == all_chips // ((H+1) * (V+1)):
        continue
      elif cnt[h_cut] > all_chips // ((H+1) * (V+1)):
        possible_v = False
        break

    if not possible_v:
      break

    if v_cut_finish:
      v_cuts.append(i)
      cnt = [0] * (H + 1)

    # print(i, cnt) # debug

  if not possible_v:
    # print("Vertical cut is impossible") # debug: result
    return "IMPOSSIBLE"

  # assert(len(v_cuts) == (V + 1))
  if not len(v_cuts) == (V + 1): # assertion
    # print("Error: Not V vertical cuts") # debug: result
    return "IMPOSSIBLE"

  # print("Dividable") # debug: result
  # print("Horizontal: " + str(h_cuts)) # debug: result
  # print("Vertical: " + str(v_cuts)) # debug: result
  return "POSSIBLE"

def main():
  T = int(input())
  for test in range(1, T+1):
    R, C, H, V = tuple(map(int, input().split()))
    chips = []
    chips_row_count = []
    for i in range(R):
      row_chips = list(map(lambda x: x=="@", list(input())))
      chips.append(row_chips)
      chips_row_count.append(row_chips.count(True))

    print("Case #" + str(test) + ": " + chop(R, C, H, V, chips, chips_row_count))

main()
