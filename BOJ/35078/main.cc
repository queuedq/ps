#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<19;
int N, A[ST];
int seg[ST*2];

struct Interval {
  int t, id, s, e; // t=0: inner interval, t=1: outer interval
};
vector<Interval> I;
vector<int> D; // interval nesting depth

void update(int i, int x) {
  i += ST;
  seg[i] = max(seg[i], x);
  for (i/=2; i>0; i/=2) seg[i] = max(seg[i*2], seg[i*2+1]);
}

int query(int s, int e) {
  int res = 0;
  for (s+=ST, e+=ST+1; s<e; s/=2, e/=2) {
    if (s&1) res = max(res, seg[s++]);
    if (e&1) res = max(res, seg[--e]);
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];

  // get valid intervals when fixing A[i]
  vector<Interval> I;
  for (int i=0; i<N; i++) {
    int len = N-A[i];

    int s = i-len, e = i; // left interval
    if (0 <= s) {
      I.push_back({0, i*2, s, e});
      I.push_back({1, i*2, s, e+1});
    }

    s = i+1, e = i+len+1; // right interval
    if (e <= N) {
      I.push_back({0, i*2+1, s, e});
      I.push_back({1, i*2+1, s-1, e});
    }
  }

  // sort by decreasing s, and then increasing e, outer intervals first
  sort(all(I), [](Interval a, Interval b) {
    return make_tuple(-a.s, a.e, -a.t) < make_tuple(-b.s, b.e, -b.t);
  });

  // get deepest interval nesting
  D.resize(N*2);
  int mx = 0;

  for (auto [t, i, s, e]: I) {
    if (t == 0) {
      D[i] = query(0, e) + 1;
      mx = max(mx, D[i]);
    } else {
      update(e, D[i]);
    }
  }

  cout << N - mx << endl;

  ////////////////////////////////
  return 0;
}
