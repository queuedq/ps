#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505;
int N, M, K, D[MN][MN], cnt[MN][MN][26], ans[MN][MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      char c; cin >> c;
      D[i][j] = c - 'A';
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cnt[i%K][j%K][D[i][j]]++;
    }
  }

  int re = 0;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      ans[i][j] = max_element(cnt[i%K][j%K], cnt[i%K][j%K]+26) - cnt[i%K][j%K];
      re += D[i][j] != ans[i][j];
    }
  }

  cout << re << endl;
  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) {
      cout << char(ans[i][j] + 'A');
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
