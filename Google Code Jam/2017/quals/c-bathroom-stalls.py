T = int(raw_input())

for t in xrange(1, T+1):
	N, K = raw_input().split()
	N = int(N)
	K = int(K)
	
	shift_len = (K).bit_length() - 1
	longest = (N+1) >> shift_len
	
	residue = (N+1) & ((1 << shift_len) - 1)
	rest_people = K - (1 << shift_len) + 1
	
	if rest_people <= residue:
		longest += 1
	
	print 'Case #' + str(t) + ':',
	print (longest >> 1) - 1 + (longest & 1), (longest >> 1) - 1
