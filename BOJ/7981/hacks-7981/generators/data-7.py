G = 66_666
N = G*3+1
MX = 1_000_000_000

print(N)
print(f'1 {MX} 1 2')
for i in range(2, G+2):
  if i < G+1:
    print(f'1 {MX} 2 {i+1} {N-i*2+4}')
  else:
    print(f'1 {MX} 1 {N-i*2+4}')
for i in range(G+2, N+1, 2):
  print(f'1 2 1 {i}')
  print(f'1 4 1 {i}')

# 10
# 1 100 1 2
# 1 100 2 3 10
# 1 100 2 4 8
# 1 100 1 6
# 1 2 1 5
# 1 4 1 5
# 1 2 1 7
# 1 4 1 7
# 1 2 1 9
# 1 4 1 9
