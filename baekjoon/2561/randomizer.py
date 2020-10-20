import random
import subprocess

exe = input('Executable name: ')
if exe == '': exe = 'main'


def main():
  # Generate input
  N = random.randint(5, 20)
  A = list(range(1, N+1))
  flips = []

  for i in range(3):
    a = random.randint(1, N)
    b = random.randint(1, N)
    if (a > b): a, b = b, a
    A[a-1:b] = A[a-1:b][::-1]
    flips.append(a)
    flips.append(b)

  B = A.copy()

  # Run program
  p = subprocess.run(
    ['./' + exe],
    stdout=subprocess.PIPE,
    text=True,
    input=str(N) + '\n' + ' '.join([str(x) for x in A])
  )

  # Check output
  res = [int(x) for x in p.stdout.split()]
  if (len(res) != 6): return (False, N, A, flips, res)

  for i in range(3):
    a = res[i*2]
    b = res[i*2+1]
    B[a-1:b] = B[a-1:b][::-1]

  if B == list(range(1, N+1)): return (True, N, A, flips, res)
  else: return (False, N, A, flips, res)


tries = 5000
for i in range(tries):
  ok, N, A, flips, res = main()
  if not ok:
    print(N)
    print(' '.join([str(x) for x in A]))
    print('========')
    print(flips)
    print(res)
    break

  if i == tries-1: print('All done')
