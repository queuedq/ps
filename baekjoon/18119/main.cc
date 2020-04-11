#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e4+5;
int N, M, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    for (auto c: s) {
      A[i] = A[i] | 1<<(c-'a');
    }
  }

  int know = (1<<26) - 1;
  for (int i=0; i<M; i++) {
    int q; char alpha; cin >> q >> alpha;
    if (q == 1 && know & (1 << alpha-'a')) {
      know -= 1 << alpha-'a';
    } else {
      know = know | (1 << alpha-'a');
    }

    int ans = 0;
    for (int j=0; j<N; j++) {
      if ((know & A[j]) == A[j]) ans++;
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
