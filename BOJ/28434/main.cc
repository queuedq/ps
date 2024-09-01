#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int INF = 2e9;
const int ST = 1<<18;
int N, A[ST], B[ST];

////////////////////////////////
// segtree

struct Node {
  int u, v; // cover state by min/max equal range
  int cnt_u, cnt_v, cnt_uv; // cover state cnts

  void merge(Node &X, Node &Y, int len) {
    cnt_u = cnt_v = cnt_uv = 0;
    cnt_u = u ? len : X.cnt_u + Y.cnt_u;
    cnt_v = v ? len : X.cnt_v + Y.cnt_v;
    cnt_uv = u || v ? min(cnt_u, cnt_v) : X.cnt_uv + Y.cnt_uv;
  }

  void update_leaf() {
    cnt_u = !!u;
    cnt_v = !!v;
    cnt_uv = !!(u && v);
  }
};

Node seg[ST*2];

void update(int n, int nl, int nr, int l, int r, int du, int dv) {
  if (nr < l || r < nl) return;
  if (l <= nl && nr <= r) {
    seg[n].u += du, seg[n].v += dv;
  } else {
    int m = (nl+nr)/2;
    update(n*2, nl, m, l, r, du, dv);
    update(n*2+1, m+1, nr, l, r, du, dv);
  }

  if (n < ST) seg[n].merge(seg[n*2], seg[n*2+1], nr-nl+1);
  else seg[n].update_leaf();
}

////////////////////////////////
// range

struct Range {
  int l, r, v;
  bool operator<(const Range &X) const { return v < X.v; }
};

pii find_equal(vector<Range> &S, Range &X) {
  auto it = lower_bound(all(S), X);
  if (it == S.end() || it->v != X.v) return {-1, -1};
  if (X.r < it->l || it->r < X.l) return {-1, -1};
  return {max(X.l, it->l), min(X.r, it->r)};
}

////////////////////////////////

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) cin >> B[i];

  lld ans = 0;

  vector<Range> SA[2], SB[2]; // 0: min stack, 1: max stack (inverted)
  SA[0] = SA[1] = SB[0] = SB[1] = {{0, 0, -INF}};

  for (int i=1; i<=N; i++) {
    for (auto t: {0, 1}) {
      auto &P = SA[t], &Q = SB[t];
      int du = (t == 0), dv = (t == 1);

      { // update stack A
        while (P.back().v >= A[i]) {
          auto [l, r] = find_equal(Q, P.back());
          update(1, 0, ST-1, l, r, -du, -dv); // remove range
          P.pop_back();
        }

        P.push_back({P.back().r+1, i, A[i]});
        auto [l, r] = find_equal(Q, P.back());
        update(1, 0, ST-1, l, r, du, dv); // insert range
      }

      { // update stack B
        while (Q.back().v >= B[i]) {
          auto [l, r] = find_equal(P, Q.back());
          update(1, 0, ST-1, l, r, -du, -dv); // remove range
          Q.pop_back();
        }

        Q.push_back({Q.back().r+1, i, B[i]});
        auto [l, r] = find_equal(P, Q.back());
        update(1, 0, ST-1, l, r, du, dv); // insert range
      }

      A[i] = -A[i];
      B[i] = -B[i];
    }

    ans += seg[1].cnt_uv;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
