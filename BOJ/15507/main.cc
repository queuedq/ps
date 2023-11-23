#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const int MK = 20;
int N, z[MN], vst[MN][MK];
string S;

struct Node { int i, j, c, d; };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> S;
  int l = 0, r = 0;
  for (int i=1; i<N; i++) {
    if (i < r) z[i] = min(z[i-l], r-i);
    while (i+z[i] < N && S[z[i]] == S[i+z[i]]) z[i]++;
    if (i+z[i] > r) l = i, r = i+z[i];
  }

  int ans = INT_MAX;

  for (int k = 0; (1<<k)+1 <= N; k++) {
    // Use C operation k times
    if (N % ((1<<k)+1) != 0) continue;
    int s = N / ((1<<k) + 1);

    // find shortest
    deque<Node> Q = {{0, s, 0, 0}};
    memset(vst, 0, sizeof(vst));
    vst[0][0] = 1;
    int dst = INT_MAX;

    while (!Q.empty()) {
      auto [i, j, c, d] = Q.front(); Q.pop_front();
      if (i == s && j == N) { dst = d; break; }
      if (j == N) continue;

      if (S[i] == S[j] && !vst[i+1][c]) {
        Q.push_back({i+1, j+1, c, d+1});
        vst[i+1][c] = 1;
      }
      if (z[i] >= i && z[j] >= j && !vst[i*2][c+1]) {
        Q.push_back({i*2, j*2, c+1, d+1});
        vst[i*2][c+1] = 1;
      }
    }

    ans = min(ans, dst);
  }

  if (ans == INT_MAX) cout << -1 << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
