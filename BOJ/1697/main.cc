#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX = 202020;
int N, K, dst[MAX];

bool oob(int x) { return x < 0 || x >= MAX; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;

  if (N == K) {
    cout << 0 << endl;
    return 0;
  }

  fill(dst, dst+MAX, -1);
  queue<int> Q;
  dst[N] = 0;
  Q.push(N);

  while (!Q.empty()) {
    int u = Q.front(); Q.pop();

    for (auto v: {u-1, u+1, u*2}) {
      if (oob(v) || dst[v] != -1) continue;
      dst[v] = dst[u] + 1;
      Q.push(v);

      if (v == K) {
        cout << dst[v] << endl;
        return 0;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
