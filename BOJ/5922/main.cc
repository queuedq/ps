#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, X, H[MN], S[MN];
lld ans;

void merge(int l, int r) {
  if (l == r) return;
  int m = (l+r)/2;
  merge(l, m);
  merge(m+1, r);

  vector<int> tmp;
  int i = l, j = m+1;
  while (i <= m) {
    while (j <= r && S[i] > S[j]) {
      tmp.push_back(S[j++]);
      ans += i-l;
    }
    tmp.push_back(S[i++]);
  }
  while (j <= r) {
    tmp.push_back(S[j++]);
    ans += i-l;
  }

  for (int i=l; i<=r; i++) S[i] = tmp[i-l];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> X;
  for (int i=1; i<=N; i++) {
    cin >> H[i];
    S[i] = S[i-1] + (H[i] >= X ? 1 : -1);
  }

  merge(0, N);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
