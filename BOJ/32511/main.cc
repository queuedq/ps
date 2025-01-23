#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, Q;

struct Interval {
  int s, e;
  bool operator<(const Interval &I) const { return e < I.e; }
};

vector<Interval> I;
vector<vector<Interval>> qry;
vector<int> xs;
vector<array<int, 20>> nxt; // sparse array

inline void compress(int &x) { x = lower_bound(all(xs), x) - xs.begin(); }

void solve(int test) {
  // input
  cin >> N;
  for (int i=0; i<N; i++) {
    int s, e; cin >> s >> e;
    I.push_back({s, e});
    xs.push_back(s); xs.push_back(e);
  }
  sort(all(I));

  cin >> Q;
  for (int q=0; q<Q; q++) {
    int R; cin >> R;
    vector<Interval> I;
    for (int i=0; i<R; i++) {
      int s, e; cin >> s >> e;
      I.push_back({s, e});
      xs.push_back(s); xs.push_back(e);
    }
    sort(all(I));
    qry.push_back(I);
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  int X = sz(xs);

  for (auto &[s, e]: I) compress(s), compress(e);
  for (auto &I: qry) for (auto &[s, e]: I) compress(s), compress(e);

  // sparse
  nxt.resize(X+1);
  I.push_back({X, X}); // mark end
  for (int i=0, j=0; i<X; i++) {
    while (j < N && I[j].s < i) j++;
    nxt[i][0] = I[j].e;
  }
  nxt[X][0] = X;

  for (int k=1; k<20; k++)
    for (int i=0; i<=X; i++)
      nxt[i][k] = nxt[nxt[i][k-1]][k-1];

  // query
  cout << "Case #" << test << endl;

  for (auto &I: qry) {
    I.push_back({X, X});
    int i = 0, cnt = 0;

    for (auto [s, e]: I) {
      if (s < i) continue;
      for (int k=19; k>=0; k--) { // skip until s
        if (nxt[i][k] <= s && nxt[i][k] < X) i = nxt[i][k], cnt += 1<<k;
      }
      if (e < nxt[i][0] && e < X) i = e, cnt++; // Use (s, e) if better
    }

    cout << cnt << endl;
  }
  
  // reset
  I.clear(), qry.clear(), xs.clear(), nxt.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
