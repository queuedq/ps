T = int(input())

def get_bitcoin(max_coin, rest_bit, A, B, t):
    coin = max_coin - t * B
    bit = rest_bit + t * A
    return max(min(coin, bit), 0)

def get_max_bitcoin(max_coin, rest_bit, A, B, t):
    return max(
        get_bitcoin(max_coin, rest_bit, A, B, t),
        get_bitcoin(max_coin, rest_bit, A, B, t + 1)
    )

for test in range(T):
    P, Q, A, B, C, D = [int(x) for x in input().split()]

    max_coin = P // A * B + Q // C * D
    rest_bit = P - P // A * A

    t = (max_coin - rest_bit) // (A + B)

    print(get_max_bitcoin(max_coin, rest_bit, A, B, t))
