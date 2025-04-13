#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

const int ST = 1<<18;
lld N, Q, A[ST], B[ST], C[ST], ans[ST];
vector<array<lld, 3>> qry;
vector<array<lld, 3>> E1, E2, E3;

struct SegTree {
  lld seg[ST*2];

  void add(int i, lld v) {
    for (int n=i+ST; n>0; n/=2) seg[n] += v;
  }

  lld sum(int l, int r) {
    lld ret = 0;
    for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
      if (l&1) ret += seg[l++];
      if (r&1) ret += seg[--r];
    }
    return ret;
  }
} seg1, seg2, seg3;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i] >> B[i] >> C[i];
    E1.push_back({A[i]-B[i], A[i]-C[i], -1});
    E2.push_back({B[i]-C[i], B[i]-A[i], -1});
    E3.push_back({C[i]-A[i], C[i]-B[i], -1});
  }

  cin >> Q;
  int x = 0, y = 0, z = 0;
  for (int q=0; q<Q; q++) {
    char c; int v; cin >> c >> v;
    if (c == 'A') x += v;
    if (c == 'B') y += v;
    if (c == 'C') z += v;
    E1.push_back({x-y, x-z, q});
    E2.push_back({y-z, y-x, q});
    E3.push_back({z-x, z-y, q});
  }

  sort(all(E1));
  sort(all(E2));
  sort(all(E3));

  for (int i=0; i<Q; i++) {
    auto [x, y, q] = E1[i]; // A largest
    if (q == -1) {
      seg1.add(y, );
    }
  }
  

  return 0;
}
