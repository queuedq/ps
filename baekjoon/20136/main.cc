#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
int N, K, A[MN], vst[MN], nxt[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<K; i++) cin >> A[i];

  fill(vst, vst+K+1, K+1);
  for (int i=K-1; i>=0; i--) {
    nxt[i] = vst[A[i]];
    vst[A[i]] = i;
  }

  int ans = 0;
  set<pii> S;
  for (int i=0; i<K; i++) {
    auto it = S.find({i, A[i]});
    if (it != S.end()) {
      S.erase({i, A[i]});
      S.insert({nxt[i], A[i]});
      continue;
    }
    if (S.size() < N) {
      S.insert({nxt[i], A[i]});
      continue;
    }
    
    S.erase(prev(S.end()));
    S.insert({nxt[i], A[i]});
    ans++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
