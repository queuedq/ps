T = int(raw_input())

for t in xrange(1, T+1):
	N_raw = raw_input()
	N = map(int, list(N_raw))
	
	current_digit = N[0]
	consec_start = 0
	decreasing = False
	
	for i in xrange(1, len(N)):
		if N[i] > current_digit:
			current_digit = N[i]
			consec_start = i
		elif N[i] < current_digit:
			decreasing = True
			break
	
	if not decreasing:
		print 'Case #' + str(t) + ': ' + str(N_raw)
	else:
		consec_len = len(N) - consec_start
		nondec = str(N_raw[:-consec_len])
		rest = str(current_digit-1) + str('9' * (len(N)-consec_start-1))
		print 'Case #' + str(t) + ': ' + str(int(nondec + rest))
