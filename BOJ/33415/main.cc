#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, M, Q;
vector<int> A, B;

struct DSU {
  int par[MN];
  int sum[MN]; // xor sum
  int cnt; // num points with nonzero xor

  int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
  }

  void merge(int u, int v) {
    u = find(u), v = find(v);
    par[v] = u;
  }

  void connect(int L, vector<int> &X) {
    assert(L > 0);

    int g = 0, d = 0;
    vector<int> Y;

    for (auto x: X) {
      if (x <= L/2) g = gcd(g, x);
      else if (!d) d = x;
      else Y.push_back(x-d);
    }

    // 1. connect dist g (gcd below L/2)
    if (g) for (int i=0; i<=L-g; i++) merge(i, i+g);

    // 2. connect dist d (min over L/2)
    if (d) for (int i=0; i<=L-d; i++) merge(i, i+d);

    // 3. connect dist > d
    // Since [0, L-d] is equiv to [d, L] each, we can treat dist x as x-d
    if (sz(Y)) connect(L-d, Y);
  }

  void add(int u) {
    u = find(u);
    sum[u] ^= 1;
    cnt += sum[u] ? 1 : -1;
  }

  bool valid() { // can make all zero?
    return cnt - sum[find(0)] == 0; // flipping at 0 can be done anytime
  }
};
DSU dsu[2];

set<pii> P; // internal points with nonzero xor

void add(int x, int y) {
  if (x == N) dsu[1].add(y);
  else if (y == M) dsu[0].add(x);

  if (0 < x && x < N && 0 < y && y < M) {
    if (!P.count({x, y})) P.insert({x, y});
    else P.erase({x, y});
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;

  int S; cin >> S; A.resize(S);
  for (int i=0; i<S; i++) cin >> A[i];
  sort(all(A));

  int T; cin >> T; B.resize(T);
  for (int i=0; i<T; i++) cin >> B[i];
  sort(all(B));

  // find components
  for (int i=0; i<=N; i++) dsu[0].par[i] = i;
  for (int i=0; i<=M; i++) dsu[1].par[i] = i;

  dsu[0].connect(N, A);
  dsu[1].connect(M, B);

  // query
  cin >> Q;

  for (int q=0; q<Q; q++) {
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
    sx--, sy--;

    add(sx, sy); add(sx, ey);
    add(ex, sy); add(ex, ey);

    // check ans
    bool ans = dsu[0].valid() && dsu[1].valid();

    // also try flipping whole rect along each axis!!!!!!
    dsu[0].add(N); dsu[1].add(M);
    ans |= dsu[0].valid() && dsu[1].valid();
    dsu[0].add(N); dsu[1].add(M);

    // no interior nonzero points
    ans &= P.empty();

    cout << (ans ? "Y" : "N");
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
