tokens = 0

while True:
  try:
    tokens += len(input().split())
  except EOFError:
    break

print(tokens)
