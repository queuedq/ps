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
// take plates one by one, find min number of switches between stacks
const int MN = 55;
const int MX = 10005;
int N, X, cnt[MN][MX], tot[MX], D[MX][MN];
vector<int> diam[MN], xs; 

bool solve(int test) {
  cin >> N;
  if (cin.fail()) return false;

  for (int i=0, h; i<N; i++) {
    cin >> h;
    for (int j=0, d; j<h; j++) {
      cin >> d;
      diam[i].push_back(d);
      xs.push_back(d);
    }
  }

  // compress
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  X = sz(xs);

  for (int i=0; i<N; i++) {
    for (auto &d: diam[i]) d = lower_bound(all(xs), d) - xs.begin() + 1;
  }

  // get groups
  for (int i=0; i<N; i++) {
    for (int j=0; j<sz(diam[i]); j++) {
      int d = diam[i][j];
      if (!cnt[i][d]) tot[d]++;
      cnt[i][d] = 1;
    }
  }

  // DP
  // D[d][i]: min switches where we take plates of size 1..d and last plate is from stack i
  for (int d=1; d<=X; d++) {
    for (int i=0; i<N; i++) {
      D[d][i] = INT_MAX;
      for (int j=0; j<N; j++) {
        int save = 0;
        if (cnt[j][d]) save++; // initial switch
        if ((tot[d]==1 ? i==j : i!=j) && cnt[i][d]) save++; // final switch
        D[d][i] = min(D[d][i], D[d-1][j] + (tot[d]+1) - save);
      }
    }
  }

  int num = INT_MAX;
  for (int i=0; i<N; i++) num = min(num, D[X][i]);
  int ans = (num-(N-1)) + num;

  cout << "Case " << test << ": " << ans << endl;
  return true;
}

void reset() {
  for (int i=0; i<N; i++) for (int d=1; d<=X; d++) cnt[i][d] = 0;
  for (int d=1; d<=X; d++) tot[d] = 0;
  for (int i=0; i<N; i++) diam[i].clear();
  xs.clear();
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int t=1; ; t++) {
    if (!solve(t)) break;
    reset();
  }

  ////////////////////////////////
  return 0;
}
