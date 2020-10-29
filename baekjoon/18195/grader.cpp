#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <queue>

#include "findVertices.h"

namespace{
	static const int MAX_T = 500;
	static const int MAX_N = 100;
	static const int MAX_M = 5000;
	static const int MAX_Q = 13;

	static int query_called, answer_called;
	static int answer_a = -1, answer_b = -1;
	static int chk[111][111], P[111];
	
	static int par(int p) { return p == P[p]? p : P[p] = par(P[p]); }

	static int T, N, A, B;
}

void die(const char *err) { printf("Wrong Answer : %s\n", err); exit(0); }

int query(const std::vector<int> &U, const std::vector<int> &V, int p, int q)
{
	if(++ query_called > MAX_Q) die("query called too much");
	
	if(U.size() != V.size()) die("the size of U and V must be same");
	int m = U.size();
	if(0 > m || m > MAX_M) die("the size of U and V must be in range [0, 5000]");
	
	if(1 > p || 1 > q || p > N || q > N || p == q) die("invalid pair of (p, q)");
	
	for(int i = 1; i <= N; i ++){
		P[i] = i;
	}
	
	for(int i = 0; i < m; i ++){
		if(U[i] < 1 || U[i] > N || V[i] < 1 || V[i] > N){
			die("U[i] and V[i] must be in range [1, n]");
		}
		if(U[i] == V[i]) die("U[i] and V[i] must be diffrent");
		if(chk[U[i]][V[i]]) die("the edges must be distinct");
		
		chk[U[i]][V[i]] = chk[V[i]][U[i]] = 1;
		P[par(U[i])] = par(V[i]);
	}
	
	P[par(A)] = par(B);
	
	for(int i = 0; i < m; i ++){
		chk[U[i]][V[i]] = chk[V[i]][U[i]] = 0;
	}
	
	return par(p) == par(q);
}

void answer(int a, int b)
{
	if(++ answer_called > 1) die("answer must be called exactly once");
	answer_a = a; answer_b = b;
}

int main()
{
	assert(1 == scanf("%d", &T));
	assert(1 <= T && T <= MAX_T);
	
	for(; T --; ){
		assert(1 == scanf("%d", &N));
		assert(1 == scanf("%d", &A));
		assert(1 == scanf("%d", &B));	
		assert(2 <= N && N <= MAX_N);
		assert(1 <= A && A <= N);
		assert(1 <= B && B <= N);
		assert(A != B);
		
		query_called = 0;
		answer_called = 0;
		
		find(N);

		if(answer_called != 1) die("answer must be called exactly once");
		
		printf("%d %d\n", answer_a, answer_b);
	}
	
	return 0;
}
