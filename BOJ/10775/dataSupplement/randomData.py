import random

random.seed(1)

def gen():
  G = 100000
  P = 100000

  inputs = [G, P]

  for i in range(P):
    inputs.append(random.randint(1, G))

  inputs = [str(x) for x in inputs]

  return '\n'.join(inputs)

def main():
  for i in range(5):
    f = open(str(i) + '.in', 'w')
    f.write(gen())

if __name__ == '__main__':
  main()
