#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
const int MA = 10101;
lld M, N, A[MN], D[MA];
// D[i]: min loss to make i mod K

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> M >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);
  int K = A[N-1];

  // 0-1 bfs
  fill(D, D+K, LLONG_MAX);
  D[0] = 0;
  deque<pii> Q = {{0, 0}};

  while (!Q.empty()) {
    auto [d, u] = Q.front(); Q.pop_front();
    if (d > D[u]) continue;

    for (int i=0; i<N-1; i++) {
      if (u+A[i] < K) {
        int v = u+A[i];
        if (d+1 >= D[v]) continue;
        D[v] = d+1;
        Q.push_back({d+1, v});
      } else {
        int v = u+A[i]-K;
        if (d >= D[v]) continue;
        D[v] = d;
        Q.push_front({d, v});
      }
    }
  }

  // answer
  cout << (M/K + D[M%K]) << endl;

  ////////////////////////////////
  return 0;
}
