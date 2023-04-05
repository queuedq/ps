T = int(raw_input())

for t in xrange(1, T+1):
    AC, AJ = map(int, raw_input().split())
    schedule = []
    for _ in xrange(AC):
        schedule.append(map(int, raw_input().split()) + (0))
    for _ in xrange(AJ):
        schedule.append(map(int, raw_input().split()) + (0))