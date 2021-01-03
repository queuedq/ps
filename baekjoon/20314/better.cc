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
  for (int i=2; i<=N; i++) { cin >> T[i]; T[i] += T[i-1]; }

  int j = 1;
  deque<pll> dq;
  for (int i=1; i<=N; i++) {
    while (j <= N && T[j] - T[i] <= H[j]) {
      while (!dq.empty() && dq.back().first <= H[j]) dq.pop_back();
      dq.push_back({H[j], j});
      j++;
    }
    while (!dq.empty() && dq.front().second < i) dq.pop_front();
    D[i] = dq.front().first;
  }

  j = N;
  dq.clear();
  for (int i=N; i>=1; i--) {
    while (j >= 1 && T[i] - T[j] <= H[j]) {
      while (!dq.empty() && dq.back().first <= H[j]) dq.pop_back();
      dq.push_back({H[j], j});
      j--;
    }
    while (!dq.empty() && dq.front().second > i) dq.pop_front();
    D[i] = max(D[i], dq.front().first);
  }

  for (int i=1; i<=N; i++) cout << D[i] << " ";

  return 0;
}
