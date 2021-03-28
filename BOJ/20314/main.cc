#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pll = pair<lld, lld>;

const int MN = 300'005;
lld N, H[MN], T[MN], D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  for (int i=1; i<=N; i++) cin >> H[i];
  for (int i=1; i<=N-1; i++) cin >> T[i];

  priority_queue<pll> pq;
  int j = 1;
  lld t = 0;
  for (int i=1; i<=N; i++) {
    while (t > H[i]) {
      while (pq.top().second < j) pq.pop();
      D[j] = pq.top().first;
      t -= T[j];
      j++;
    }
    t += T[i];
    pq.push({H[i], i});
  }
  while (j <= N) {
    while (pq.top().second < j) pq.pop();
    D[j] = pq.top().first;
    t -= T[j];
    j++;
  }

  pq = priority_queue<pll>();
  j = N;
  t = 0;
  for (int i=N; i>=1; i--) {
    while (t > H[i]) {
      while (pq.top().second > j) pq.pop();
      D[j] = max(D[j], pq.top().first);
      t -= T[j-1];
      j--;
    }
    t += T[i-1];
    pq.push({H[i], i});
  }
  while (j >= 1) {
    while (pq.top().second > j) pq.pop();
    D[j] = max(D[j], pq.top().first);
    t -= T[j-1];
    j--;
  }

  for (int i=1; i<=N; i++) cout << D[i] << " ";

  return 0;
}
