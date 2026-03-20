#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 25;
const int MX = (1<<20) + 5;
int N, w[MX], l[MX];
vector<int> adj[MX];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<(1<<N)-2; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    w[a]++; l[b]++;
  }
  for (int i=1; i<=(1<<N); i++) {
    sort(all(adj[i]), [](int a, int b) { return w[a] < w[b]; });
  }

  // collect players who didn't lose
  vector<int> lose;
  for (int i=1; i<=(1<<N); i++) {
    if (!l[i]) lose.push_back(i);
  }
  if (w[lose[0]] > w[lose[1]]) swap(lose[0], lose[1]);
  assert(lose.size() == 2); // missing match loser, final winner

  // final winner's match missing
  if (w[lose[1]] < N) {
    if (w[lose[0]] == w[lose[1]]) {
      // final match missing
      cout << lose[0] << " " << lose[1] << endl;
      cout << lose[1] << " " << lose[0] << endl;
    } else {
      cout << lose[1] << " " << lose[0] << endl;
    }
    return 0;
  }

  // someone (x) is missing win against lose[0]
  // x's opponent in its last match (y) has duplicate opponent win count
  for (int i=1; i<=(1<<N); i++) {
    for (int j=0; j<w[i]-1; j++) {
      if (w[adj[i][j]] != w[adj[i][j+1]]) continue;
      assert(w[adj[i][j]] >= w[lose[0]]);

      vector<int> X = {adj[i][j], adj[i][j+1]};
      sort(all(X));

      for (auto x: X) {
        // check correct x
        bool ok = true;
        for (auto k: adj[x]) {
          if (w[k] == w[lose[0]]) ok = false;
        }
        if (ok) cout << x << " " << lose[0] << endl;
      }
      return 0;
    }
  }

  // all done
  assert(0);

  ////////////////////////////////
  return 0;
}
