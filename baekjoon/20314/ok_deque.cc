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

  deque<pll> dq;
  int j = 1;
  lld t = 0;
  for (int i=1; i<=N; i++) {
    while (t > H[i]) {
      while (dq.front().second < j) dq.pop_front();
      D[j] = dq.front().first;
      t -= T[j];
      j++;
    }
    t += T[i];
    while (!dq.empty() && dq.back().first <= H[i]) dq.pop_back();
    dq.push_back({H[i], i});
  }
  while (j <= N) {
    while (dq.front().second < j) dq.pop_front();
    D[j] = dq.front().first;
    t -= T[j];
    j++;
  }

  dq = deque<pll>();
  j = N;
  t = 0;
  for (int i=N; i>=1; i--) {
    while (t > H[i]) {
      while (dq.front().second > j) dq.pop_front();
      D[j] = max(D[j], dq.front().first);
      t -= T[j-1];
      j--;
    }
    t += T[i-1];
    while (!dq.empty() && dq.back().first <= H[i]) dq.pop_back();
    dq.push_back({H[i], i});
  }
  while (j >= 1) {
    while (dq.front().second > j) dq.pop_front();
    D[j] = max(D[j], dq.front().first);
    t -= T[j-1];
    j--;
  }

  for (int i=1; i<=N; i++) cout << D[i] << " ";

  return 0;
}
