#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, B, A[MAXN];
vector<int> L, R;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> B;
  int j;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    if (A[i] == B) j = i;
  }

  int sum = 0;
  L.push_back(0);
  for (int i=j-1; i>=0; i--) {
    if (A[i] > B) sum++;
    else sum--;
    L.push_back(sum);
  }

  sum = 0;
  R.push_back(0);
  for (int i=j+1; i<N; i++) {
    if (A[i] < B) sum++;
    else sum--;
    R.push_back(sum);
  }

  sort(L.begin(), L.end());

  int ans = 0;
  for (auto r: R) {
    auto [s, e] = equal_range(L.begin(), L.end(), r);
    ans += e - s;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
