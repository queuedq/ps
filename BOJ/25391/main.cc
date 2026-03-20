#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

const int MN = 202020;
lld N, M, K;
pll A[202020];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M >> K;
  for (int i=0; i<N; i++) cin >> A[i].first >> A[i].second;
  sort(A, A+N, [](pll a, pll b) { return a.second > b.second; });
  sort(A+K, A+N, [](pll a, pll b) { return a.first > b.first; });

  lld sum = 0;
  for (int i=0; i<K+M; i++) sum += A[i].first;
  cout << sum << endl;

  return 0;
}
