#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, A[101010];
vector<lld> xs;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    A[i] = A[i] * N + i; // avoid duplicate
    xs.push_back(A[i]);
  }
  sort(all(xs));
  for (int i=0; i<N; i++) A[i] = lower_bound(all(xs), A[i]) - xs.begin();
  
  int ans = 0;
  for (int i=0; i<N; i++) ans = max(ans, i - (int)A[i]);
  cout << ans + 1 << endl;

  ////////////////////////////////
  return 0;
}
