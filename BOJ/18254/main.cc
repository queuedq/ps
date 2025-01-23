#include <algorithm>
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MX = 202020;
const int B = 1<<9;
int N, M, Q, A[MX], psum[MX];

struct Operation { int x, v; }; // A[x..N] ^= v
Operation op[MX];
vector<int> op_idx[MX]; // op point indicies at x
int delta[MX]; // delta: change in psum after M operations. op affects every second pos after them

struct Query { int q, y, v, x; }; // q=1: op[1..y] ^= v / q=2: xor A[1..x]
Query qry[MX];
int ans[MX];

void bulk_update(int s, int e) { // (M+N) * Q/B
  vector<int> upd(M*2+1);

  // change ops
  for (int k=s; k<=e; k++) {
    auto [q, y, v, x] = qry[k];
    if (q == 1) upd[y] ^= v;
  }

  for (int i=M*2, dv=0; i>=1; i--) {
    dv ^= upd[i];
    op[i].v ^= dv;
  }

  // change delta
  for (int i=1, da=0, db=0; i<=N; i++) {
    for (auto j: op_idx[i]) da ^= op[j].v;
    delta[i] = da;
    swap(da, db);
  }
}

vector<int> xs, ys;
int op_bx[MX], op_by[MX], qry_bx[MX], qry_by[MX];
int cnt[B+5][B+5][2];

void prepare(int s, int e) { // (M+N + B^2) * (Q/B)
  xs.clear(), ys.clear();
  for (int k=s; k<=e; k++) {
    auto [q, y, v, x] = qry[k];
    if (q == 1) ys.push_back(y);
    else xs.push_back(x);
  }
  xs.push_back(0), ys.push_back(0);
  sort(all(xs)), xs.erase(unique(all(xs)), xs.end());
  sort(all(ys)), ys.erase(unique(all(ys)), ys.end());

  // precompute query by, bx
  for (int k=s; k<=e; k++) {
    auto [q, y, v, x] = qry[k];
    if (q == 1) qry_by[k] = lower_bound(all(ys), y) - ys.begin();
    else qry_bx[k] = lower_bound(all(xs), x) - xs.begin();
  }

  // precompute op by, bx
  for (int y=1, i=0; y<=M*2; y++) {
    while (i < sz(ys) && ys[i] < y) i++;
    op_by[y] = i;
  }
  for (int x=1, i=0; x<=N+1; x++) {
    while (i < sz(xs) && xs[i] < x) i++;
    for (auto k: op_idx[x]) op_bx[k] = i;
  }

  // get op points in each block (splitted by xs, ys)
  memset(cnt, 0, sizeof(cnt));
  for (int i=1; i<=M*2; i++) {
    int by = op_by[i], bx = op_bx[i];
    cnt[by][bx][op[i].x%2]++;
  }

  // 2d prefix sum
  for (int y=1; y<=sz(ys); y++) {
    for (int x=1; x<=sz(xs); x++) {
      for (int b: {0, 1})
        cnt[y][x][b] += cnt[y-1][x][b] + cnt[y][x-1][b] - cnt[y-1][x-1][b];
    }
  }
}

// answer e-th query, given that qry[0..s) is already processed
int query(int s, int e) { // B * Q
  int x = qry[e].x;
  int bx = qry_bx[e];

  int ans = psum[x] ^ delta[x];
  for (int k=s; k<e; k++) {
    auto [q, y, v, _] = qry[k];
    if (q == 1) {
      int by = qry_by[k];
      if (cnt[by][bx][x%2] % 2) ans ^= v;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> Q;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    psum[i] = psum[i-1] ^ A[i];
  }

  for (int i=1; i<=M; i++) {
    int s, e, v; cin >> s >> e >> v;
    op[i*2-1] = {s, v}, op_idx[s].push_back(i*2-1);
    op[i*2] = {e+1, v}, op_idx[e+1].push_back(i*2);
  }

  for (int k=0; k<Q; k++) {
    int q, l, r, v=0; cin >> q;
    if (q == 1) {
      cin >> l >> r >> v;
      qry[k*2] = {q, (l-1)*2, v, 0};
      qry[k*2+1] = {q, r*2, v, 0};
    } else {
      cin >> l >> r;
      qry[k*2] = {q, 0, 0, l-1};
      qry[k*2+1] = {q, 0, 0, r};
    }
  }

  // sqrt decomp
  for (int i=0; i<Q*2; i++) {
    if (i%B == 0) {
      bulk_update(max(i-B, 0), i-1);
      prepare(i, min(i+B-1, Q*2-1));
    }
    auto [q, y, v, x] = qry[i];
    if (q == 2) ans[i] = query(i/B*B, i);
  }

  for (int i=0; i<Q; i++) {
    if (qry[i*2].q == 2) cout << (ans[i*2] ^ ans[i*2+1]) << endl;
  }

  ////////////////////////////////
  return 0;
}
