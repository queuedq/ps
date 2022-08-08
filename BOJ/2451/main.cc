#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3030;
int N, A[MN][MN], S[MN][MN];
pii D[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    while (1) {
      int j; cin >> j;
      if (j == 0) break;
      if (i < j) A[i][j] = 1;
    }
  }

  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) {
      S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1] + A[i][j];
    }
  }

  D[0] = {0, 0};
  for (int i=1; i<=N; i++) {
    D[i] = {INT_MAX, 0};
    for (int l=0; l<i; l++) {
      int inner = (i-l)*(i-l-1)/2 - (S[i][i] - S[l][i]);
      int outer = S[l][i] - S[l][l];
      D[i] = min(D[i], {D[l].first + inner + outer, l});
    }
  }

  vector<int> ans;
  int x = N;
  while (x) {
    ans.push_back(x - D[x].second);
    x = D[x].second;
  }
  reverse(all(ans));

  cout << D[N].first << endl;
  cout << sz(ans) << ' ';
  for (auto a: ans) cout << a << ' ';

  ////////////////////////////////
  return 0;
}
