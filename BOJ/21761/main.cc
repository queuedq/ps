#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, K, L[4], idx[4];
vector<lld> card[4];
vector<pll> ans;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  cin >> L[0] >> L[1] >> L[2] >> L[3];
  for (int i=0; i<N; i++) {
    char c; lld d; cin >> c >> d;
    card[c-'A'].push_back(d);
  }
  for (int i=0; i<4; i++) {
    sort(all(card[i]));
    reverse(all(card[i]));
    card[i].push_back(0);
  }
  
  for (int k=0; k<K; k++) {
    lld p = 1, q = 1, b = 0;
    for (int i=0; i<4; i++) {
      // (L+card) / L > p / q
      if ((L[i] + card[i][idx[i]]) * q > p * L[i]) {
        p = L[i] + card[i][idx[i]];
        q = L[i];
        b = i;
      }
    }

    ans.push_back({b, card[b][idx[b]]});
    L[b] += card[b][idx[b]];
    idx[b]++;
  }

  for (auto [c, d]: ans) {
    cout << (char)(c+'A') << " " << d << endl;
  }

  ////////////////////////////////
  return 0;
}
