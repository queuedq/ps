# total 2^(N-2) zeros
# 01 -> 1001 reduces # 0-group by one
# which is equal to the previous # 0-groups

N = int(input())

ans = 0
for i in range(2, N+1):
    ans = pow(2, i-2) - ans
    
print(ans)
