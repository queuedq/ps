#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 55;
int N, M, K, know[MAXN];
vector<int> party[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;

  for (int i=0; i<K; i++) {
    int x; cin >> x;
    know[x] = true;
  }

  for (int i=0; i<M; i++) {
    int num; cin >> num;
    party[i].resize(num);
    for (int j=0; j<num; j++) cin >> party[i][j];
  }

  for (int t=0; t<M; t++) {
    for (int i=0; i<M; i++) {
      bool b = false;
      for (int j=0; j<party[i].size(); j++) {
        if (know[party[i][j]]) { b = true; break; }
      }

      if (b) {
        for (int j=0; j<party[i].size(); j++) know[party[i][j]] = true;
      }
    }
  }

  int ans = 0;
  for (int i=0; i<M; i++) {
    if (party[i].empty() || !know[party[i][0]]) ans++;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
