def TroubleSort(L):
  done = False
  while not done:
    done = True
    for i in range(len(L)-2):
    if L[i] > L[i+2]:
      done = False
      temp = L[i]
      L[i] = L[i+2]
      L[i+2] = temp
