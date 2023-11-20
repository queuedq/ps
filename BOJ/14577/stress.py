from subprocess import Popen, PIPE

t = 0

while True:
  p = Popen(['python', 'data.py'], stdout=PIPE, stdin=PIPE)
  data = p.communicate(input=bytes(str(t), 'utf8'))[0]
  # print(str(data, 'utf8'))
  # print()

  p = Popen(['./main'], stdout=PIPE, stdin=PIPE)
  main = p.communicate(input=data)[0]
  # print(str(main)[:20])

  p = Popen(['./naive'], stdout=PIPE, stdin=PIPE)
  naive = p.communicate(input=data)[0]
  # print(str(naive)[:20])

  # print(main == naive)

  if main != naive:
    print(t)
    print()
    print(main)
    print()
    print(naive)
    break

  t += 1
  print(f'{t} tries')
  # if t % 100 == 0:
  #   print(f'{t} tries')
