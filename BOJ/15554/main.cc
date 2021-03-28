#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e5+5;
int N;
pll A[MAXN];
lld S[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(A+1, A+N+1);
  for (int i=1; i<=N; i++) S[i] = S[i-1] + A[i].second;

  lld j = 0, ans = 0;
  for (int i=1; i<=N; i++) {
    ans = max(ans, (S[i] - A[i].first) - (S[j] - A[j+1].first));
    if (S[i] - A[i+1].first < S[j] - A[j+1].first) j = i;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
