#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 998'244'353;
const lld MOD2 = 1e9 + 7;
int N, M, X, Y;
lld inv[125];

lld modpow(lld x, lld e) {
  if (e < 0) return modpow(modpow(x, MOD-2), -e);
  lld r = 1;
  while (e) {
    if (e&1) r = r*x % MOD;
    x = x*x % MOD;
    e /= 2;
  }
  return r;
}

// State
struct State {
  int n, m, p; // n rangaroses left / m minions left / p player hits left
  vector<int> cnt; // cnt[i]: minions with i hits left (i=0..n)

  bool operator==(const State &S) const { return tie(p, cnt) == tie(S.p, S.cnt); }
  
  lld hash() { return hash(MOD) * MOD2 + hash(MOD2); }
  lld hash(lld mod) {
    lld H = n*37 + p;
    for (int i=1; i<=n; i++) H = (H*37 + cnt[i]) % mod;
    return H;
  }

  void hit(int i) {
    if (i > 0) { // hit minion
      cnt[i]--, cnt[i-1]++;
      if (i == 1) m--;
    } else { // hit player
      p--;
    }

    cnt[n-1] += cnt[n];
    cnt.pop_back();
    n--;
  }
};

// DP
unordered_map<lld, lld> D[25][25];

lld dp(State &S) {
  if (S.p > S.n) return 0; // cannot kill player
  if (S.p == 0) return 1; // player is dead

  lld hash = S.hash();
  if (D[S.n][S.p].count(hash)) return D[S.n][S.p][hash];
  auto &ret = D[S.n][S.p][hash];
  
  for (int i=0; i<=S.n; i++) {
    if (i > 0 && S.cnt[i] == 0) continue;

    lld prob = (i > 0 ? S.cnt[i] : 1) * inv[S.m+1] % MOD; // hit probability

    State T = S; T.hit(i);
    ret = (ret + dp(T) * prob) % MOD;
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  // input
  cin >> N >> M >> X >> Y;
  vector<int> cnt(N+1);

  for (int i=0; i<M; i++) {
    int H; cin >> H;
    int h = H/X + (H%X != 0);
    h = min(h, N);
    cnt[h]++;
  }

  int p = Y/X + (Y%X != 0);
  p = min(p, N+1);

  // calc inv
  for (int i=1; i<=M+1; i++) inv[i] = modpow(i, -1);

  // DP
  State S = {N, M, p, cnt};
  lld prob = dp(S);
  cout << prob << endl;

  ////////////////////////////////
  return 0;
}
