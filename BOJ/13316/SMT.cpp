#include<stdio.h>
#include<algorithm>
#include<vector>
#include<stdlib.h>
#include<cassert>

using namespace std;

typedef pair<int,int> pii;

int main()
{
	int N, a, b;
	assert(scanf("%d", &N) == 1);
	assert(2 <= N && N <= 1000);

	vector<pii> G;
	for(int i = 1; i <= N; i++){
		assert(scanf("%d%d", &a, &b) == 2);
		assert(0 <= a && a <= 1000 && 0 <= b && b <= 1000);
		G.push_back(pii(a, b));
	}
	sort(G.begin(), G.end(), [](const pii &l, const pii &r){ return l.first * r.second < l.second * r.first; });

	bool ch = false;
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			ch |= G[i].first * G[j].second > G[i].second * G[j].first;
		}
	}
	assert(ch);
	return 0;
}
