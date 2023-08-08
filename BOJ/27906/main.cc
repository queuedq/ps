#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 20;
const int MQ = 30;
int N, Q, vis[MN], w1, w2, hats;
vector<int> ask[MQ], res[MQ];
int U[1<<MN], cnt[MN][1<<MN];
// U[m]: parallel universe with hats m exists?
// cnt[i][m]: number of alive universes with (i's + visible) hat pattern m

void update_universe(int m, int v) { // update universe count
  U[m] += v;
  for (int i=0; i<N; i++) cnt[i][m & vis[i]] += v;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // input
  cin >> N;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) { int v; cin >> v; vis[i] |= v<<j; }
    vis[i] |= 1<<i; // my hat
  }
  
  cin >> w1 >> w2;
  string S; cin >> S;
  for (int i=0; i<N; i++) {
    if (S[i] == 'W') hats |= 1<<i;
  }

  // init universes
  for (int m=0; m<1<<N; m++) {
    int p = __builtin_popcount(m);
    if (w1 <= p && p <= w2) update_universe(m, 1);
  }

  // queries
  cin >> Q;
  for (int q=0; q<Q; q++) {
    int k; cin >> k;
    vector<int> ask(k), res(k);
    for (int i=0; i<k; i++) { cin >> ask[i]; ask[i]--; }

    // get answers
    for (int i=0; i<k; i++) {
      int x = ask[i];
      int m1 = (hats ^ 1<<x) & vis[x];
      res[i] = !cnt[x][m1]; // no alternate universe -> yes
    }

    // kill universes
    int kill[1<<MN] = {};
    for (int i=0; i<k; i++) {
      int x = ask[i], r = res[i];

      for (int m=0; m<1<<N; m++) {
        if (!U[m]) continue;
        int m1 = (m ^ 1<<x) & vis[x];
        if ((!cnt[x][m1]) != r) kill[m] = 1; // different response, kill
      }
    }

    for (int m=0; m<1<<N; m++) update_universe(m, -kill[m]);

    // print responses
    for (auto r: res) cout << "NY"[r];
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
