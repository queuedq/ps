from math import *
from decimal import *

getcontext().prec = 20

A, B, C = [Decimal(x) for x in input().split(" ")]

N = int(input())
M = Decimal(0)
P = {}
F = A
cur = "Taxi Garage."

eps = Decimal("0.00000000000001")

D = {}
E = {}

def f(a, b):
    return Decimal(abs(D[a][0] - D[b][0]) + abs(D[a][1] - D[b][1]))

for i in range(N):
    S = input().split(" ")
    d = ' '.join(S[:-2])+"."
    x = Decimal(S[-2])
    y = Decimal(S[-1])
    D[d] = (x, y)

for i in range(3):
    S = input().split(" ")
    d = ' '.join(S[:-1])+"."
    y = Decimal(S[-1])
    E[d] = y

K = int(input())

for i in range(K):
    S = input().split(" ")
    if ' '.join(S[:2]) == "Go to":
        if f(cur, ' '.join(S[2:len(S)])) - F * C > -eps:
            print("OUT OF GAS")
            exit(0)
        dest = ' '.join(S[2:len(S)])
        dist = f(cur, dest)
        F -= Decimal(dist / C)
        for d in P:
            for x in range(len(P[d])):
                P[d][x] += dist
        if (dest in P):
            for p in P[dest]:
                M += Decimal(p * B)
            del P[dest]
        if dest in E:
            Q = Decimal(E[dest])
            if M - Decimal(floor((A - F) * Q + eps)) > -eps:
                T = Decimal(floor((A - F) * Q + eps))
                F = Decimal(A)
                M -= T
            else:
                F += M / Q
                M = Decimal(0)
        cur = dest
        continue

    if ' '.join(S[:5]) == "Pickup a passenger going to":
        dest = ' '.join(S[5:len(S)])
        if dest not in P:
            P[dest] = []
        P[dest].append(Decimal(0))
        j = 0
        for x in P:
            j += len(P[x])

        if j > 3:
            print("CAPACITY FULL")
            exit(0)

if cur != "Taxi Garage.":
    print("NOT IN GARAGE")
    exit(0)
j = 0
for x in P:
    j += len(P[x])
if j != 0:
    print("REMAINING PASSENGER")
    exit(0)

print(M)