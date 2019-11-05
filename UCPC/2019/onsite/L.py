import math

N = int(input())

if N == 1:
    print('#')
    exit(0)

def least_exponent(n):
    return math.ceil(math.log2(n))

e = least_exponent(N)
empty = 2 ** e - N

def get_slots(exponent, digit):
    if digit == 1:
        return ['#'] * (2 ** exponent) + ['.'] * (2 ** exponent)
    else:
        return ['#'] * (2 ** (exponent + 1))

def set_slots(new_slots, pos):
    for i in range(len(new_slots)):
        slots[pos + i] = new_slots[i]

slots = ['#'] * (2 ** e)
digits = []

for exponent in range(e - 1):
    digits.append(empty % 2)
    empty = empty >> 1

mid = 2 ** (e - 1)
# print(e)
for exponent in range(e - 2, -1, -1):
    # print(exponent, slots)
    if digits[exponent] == 1:
        set_slots(get_slots(exponent, digits[exponent]), mid)
        mid = mid - 2 ** exponent
    else:
        set_slots(get_slots(exponent, digits[exponent]), mid - 2 ** (exponent + 1))
        mid = mid + 2 ** exponent

print(''.join(slots))
