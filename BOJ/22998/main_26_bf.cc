#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 1<<18;
int D[MK], E[MK];
vector<int> group[128];

int calc(int n, vector<int> P) { // number of inc seq
  vector<int> D(n);
  int sum = 0;
  for (int i=0; i<n; i++) {
    D[i] = 1;
    for (int j=0; j<i; j++)
      if (P[j] < P[i]) D[i] += D[j];
    sum += D[i];
  }
  return sum;
}

void perm(int n, vector<int> P) {
  if (sz(P) == n) {
    int cnt = calc(n, P);
    group[cnt] = P;
    return;
  }
  for (int i=0; i<n; i++) {
    if (count(all(P), i)) continue;
    P.push_back(i);
    perm(n, P);
    P.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int n=7; n>=1; n--) {
    vector<int> P;
    perm(n, P);
  }

  D[0] = 0;
  for (int i=1; i<MK; i++) {
    D[i] = D[i-1]+1, E[i] = 0; // at bottom

    for (int j=1; j<31; j++) { // group at top
      int val = D[i/(j+1)] + sz(group[j]);
      if (i%(j+1) == j && val < D[i])
        D[i] = min(D[i], val), E[i] = j;
    }
  }

  int T; cin >> T;
  while (T--) {
    int K; cin >> K;

    vector<int> G;
    int lo = 0;
    while (K) {
      G.push_back(E[K]);
      if (E[K] == 0) K--, lo++;
      else K /= E[K]+1;
    }
    reverse(all(G));

    vector<int> ans;
    int hi = lo+1;
    for (auto g: G) {
      if (g == 0) ans.push_back(lo--);
      else {
        for (auto i: group[g])
          ans.push_back(hi + i);
        hi += sz(group[g]);
      }
    }

    cout << ans.size() << endl;
    for (auto x: ans) cout << x << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
