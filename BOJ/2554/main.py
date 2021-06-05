N = int(input())

two = 0
i = 2
while i <= N:
  two += N//i
  i *= 2

five = 0
j = 5
while j <= N:
  five += N//j
  j *= 5

three = 0
seven = 0
nine = 0

def count_last(x, digit):
  return (x-digit)//10 + 1

i = 1
while i <= N:
  j = 1
  while i*j <= N:
    x = (N//i//j)
    three += count_last(x, 3)
    seven += count_last(x, 7)
    nine += count_last(x, 9)

    j *= 5
  i *= 2

ans = pow(2, two-five, 10)
ans *= pow(3, three, 10)
ans *= pow(7, seven, 10)
ans *= pow(9, nine, 10)
print(ans % 10)
