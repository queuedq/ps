T = int(raw_input())

for t in xrange(1, T+1):
	pdict = {'-': True, '+': False}
	pancakes, K = raw_input().split()
	pancakes = map(pdict.get, list(pancakes))
	K = int(K)

	flips = 0

	for i in xrange(len(pancakes)-K+1):
		if pancakes[i]:
			flips += 1
			for j in xrange(K):
				pancakes[i+j] = not pancakes[i+j]
	
	if reduce(lambda x, y: x or y, pancakes[-K:]):
		flips = 'IMPOSSIBLE'
		
	print 'Case #' + str(t) + ': ' + str(flips)

