#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 151;
int prime[MN];
vector<int> P;

void solve() {
  int N, M; cin >> N >> M;
  int pcnt = 0; // primes <= N/2
  for (auto p: P) pcnt += p <= N/2;
  int S = 1<<pcnt;

  int free = 0; // free moves
  vector<int> vp(N+1), vm(S), moves;
  for (int i=0; i<M; i++) {
    int x; cin >> x;
    if (x == 1) {
      free++;
    } else if (x > N/2 && prime[x]) {
      if (!vp[x]) free++;
      vp[x] = 1;
    } else {
      int m = 0;
      for (int i=0; i<pcnt; i++) m |= (x%P[i] == 0) << i;
      if (!vm[m]) moves.push_back(m);
      vm[m] = 1;
    }
  }

  // dp
  vector<int> D(S), vg(sz(moves)+1);
  for (int s=1; s<S; s++) {
    for (auto m: moves) if ((s&m) == m) vg[D[s^m]] = s;
    for (int g=0;; g++) if (vg[g] != s) { D[s] = g; break; } // mex
  }

  // game sum
  int game = D[S-1] ^ (free&1);
  if (game) cout << "amsminn" << endl;
  else cout << "bnb2011" << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  fill(prime+2, prime+MN, 1);
  for (int i=2; i<MN; i++) if (prime[i]) {
    for (int j=i*2; j<MN; j+=i) prime[j] = 0;
    P.push_back(i);
  }

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
