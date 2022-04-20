#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////
const int MN = 1e6+5;
lld M, cnt[MN], D[MN];

vector<lld> find_minimum_costs(int N, vector<int> A, vector<int> B) {
  if (N == 1) return {0};
  M = A.size();

  priority_queue<pll, vector<pll>, greater<pll>> pq; // (next cost, index)
  for (int i=0; i<M; i++) pq.push({(lld)A[i] + B[i], i});
  
  auto [cost1, j1] = pq.top(); pq.pop();
  auto [cost2, j2] = pq.top(); pq.pop();
  
  D[2] = cost2;
  cnt[j1]++; cnt[j2]++;
  pq.push({(lld)A[j1] * 2 + B[j1] + D[2], j1});
  pq.push({(lld)A[j2] * 2 + B[j2] + D[2], j2});

  for (int i=3; i<=N; i++) {
    auto [cost, j] = pq.top(); pq.pop();

    D[i] = cost;
    cnt[j]++;
    pq.push({(lld)A[j] * (cnt[j]+1) + B[j] + D[cnt[j]+1], j});
  }

  vector<lld> ans;
  for (int i=1; i<=N; i++) ans.push_back(D[i]);
  return ans;
}
