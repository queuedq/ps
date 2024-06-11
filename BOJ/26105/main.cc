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
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  for (int i=1; i<=N; i++) A[i] += A[i-1];

  priority_queue<pii, vector<pii>, greater<pii>> E;
  int prv = 0; // max prev folded hinge
  int ans = INT_MAX;

  for (int i=1; i<=N; i++) {
    while (!E.empty() && E.top().first <= A[i]) {
      auto [_, x] = E.top(); E.pop();
      prv = max(prv, x);
    }
    int len = A[i] - prv;
    E.push({A[i] + len, A[i]});
    if (A[i] + len >= A[N]) ans = min(ans, len);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
