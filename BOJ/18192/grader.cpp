// Sample Grader for bogoSort

#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <chrono>
#include <random>
#include <algorithm>

#include "bogoSort.h"

namespace{
	static const int MAX_N = 200;
	static const int MAX_Q = 2500;

	static int copy_called = 0, shuffle_called = 0;
	static std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());

	static int N;
	static std::vector <int> A, B;

	void die(const char *err) { printf("Wrong Answer\n%s\n", err); exit(0); }
}

std::vector <int> copy_array()
{
	if(++ copy_called > MAX_Q) die("copy_array called too much");
	return A;
}

void shuffle_array(int s, int e)
{
	if(++ shuffle_called > MAX_Q) die("shuffle_array called too much");
	if(0 > s || s > e || e >= N) die("invalid s and e");
	std::shuffle(A.begin() + s, A.begin() + e + 1, rng);
}

int main()
{
	assert(1 == scanf("%d", &N));
	assert(1 <= N && N <= MAX_N);
	
	for(int i = 0; i < N; i ++){
		int x;
		assert(1 == scanf("%d", &x));
		assert(0 <= x && x < N);
		A.push_back(x); B.push_back(x);
	}
	
	std::sort(B.begin(), B.end());
	
	for(int i = 0; i < N; i ++){
		assert(B[i] == i);
	}
	
	sort_array(N);
	
	for(int i = 0; i < N; i ++){
		if(A[i] != i) die("array is not sorted");
	}
	
	printf("Accepted\n%d %d\n", copy_called, shuffle_called);
	
	return 0;
}
