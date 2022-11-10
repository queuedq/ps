#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, F[MN], indeg[MN], vst[MN], skip[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { cin >> F[i]; indeg[F[i]]++; }

  // select outside loops
  deque<int> Q;
  for (int i=1; i<=N; i++) {
    if (indeg[i] == 0) Q.push_back(i);
  }

  while (!Q.empty()) {
    int i = Q.front(); Q.pop_front();
    vst[i] = 1;
    if (!skip[i]) skip[F[i]] = 1; // select i if not skip
    if (--indeg[F[i]] == 0) Q.push_back(F[i]);
  }

  // find loops
  for (int i=1; i<=N; i++) {
    if (vst[i]) continue;

    // find skip (as a starting point)
    int s = i;
    do { if (skip[s]) break; s = F[s]; } while (s != i);

    // select inside loop; this also handles no skip case correctly
    int j = s;
    do { vst[j] = 1; if (!skip[j]) skip[F[j]] = 1; j = F[j]; } while (j != s);
  }

  int ans = 0;
  for (int i=1; i<=N; i++) ans += !skip[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
