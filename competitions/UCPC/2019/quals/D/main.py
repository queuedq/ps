mod = 10 ** 9 + 7

N = int(input())

words = []
prefixes = {}

for i in range(N):
  w = input()
  words.append(w)
  for c in range(len(w)):
    pre = w[:c + 1]
    if pre in prefixes:
      prefixes[pre] += 1
    else:
      prefixes[pre] = 1

sentence = input()

counts = [1]  # num of cases of length i

for end in range(1, len(sentence) + 1):
  cnt = 0
  for start in range(max(0, end - 300), end):
    mul = 0
    pre = sentence[start:end]
    if pre in prefixes:
      mul = prefixes[pre]
      # print(mul, pre, prefixes)
    cnt += (counts[start] * mul) % mod

  counts.append(cnt % mod)

# print(counts)
print(counts[-1])
