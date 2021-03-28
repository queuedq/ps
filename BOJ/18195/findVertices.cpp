#include "findVertices.h"

using namespace std;

void find(int N) {
	int s = 0, d = 0; // s = A^B, d = any position of bit 1 in s

	for (int b=1; b<N; b*=2) {
		vector<int> L, R, U, V;
		for (int i=0; i<N; i++) {
			if (!(i & b)) L.push_back(i+1);
			else R.push_back(i+1);
		}
		if (L.empty() || R.empty()) continue;
		for (int i=0; i<L.size()-1; i++) {
			U.push_back(L[i]);
			V.push_back(L[i+1]);
		}
		for (int i=0; i<R.size()-1; i++) {
			U.push_back(R[i]);
			V.push_back(R[i+1]);
		}

		if (query(U, V, L[0], R[0])) {
			s ^= b;
			d = b;
		}
	}

	int A = 0; // A & d = 0, B & d = d

	for (int b=1; b<N; b*=2) {
		if (b == d) continue;

		vector<int> L, R, U, V;
		for (int i=0; i<N; i++) {
			if (!(i & d)) {
				if (i & b) L.push_back(i+1);
			} else {
				if ((i^s) & b) R.push_back(i+1);
			}
		}
		if (L.empty() || R.empty()) continue;
		for (int i=0; i<L.size()-1; i++) {
			U.push_back(L[i]);
			V.push_back(L[i+1]);
		}
		for (int i=0; i<R.size()-1; i++) {
			U.push_back(R[i]);
			V.push_back(R[i+1]);
		}

		if (query(U, V, L[0], R[0])) {
			A ^= b;
		}
	}

	answer(A+1, (A^s)+1);
}
