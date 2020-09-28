#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
lld N, A[MAXN];

void solve() {
  cin >> N;
  lld avg = 0;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    avg += A[i];
  }
  if (avg % N != 0) { cout << -1 << endl; return; }
  avg /= N;

  vector<pair<pll, lld>> ans;
  for (int i=2; i<=N; i++) {
    lld x = A[i] / i;
    if (A[i] != x*i && A[1] >= (x+1)*i - A[i]) {
      x++;
      ans.push_back({{1, i}, x*i - A[i]});
      A[1] -= x*i - A[i];
      A[i] += x*i - A[i];
    }
    ans.push_back({{i, 1}, x});
    A[i] -= x*i;
    A[1] += x*i;
  }

  for (int i=2; i<=N; i++) {
    if (A[i] > avg) {
      lld x = (A[i] - avg) / i + 1;
      lld a = A[i] - x*i;
      assert(a < avg);
      ans.push_back({{1, i}, avg - a});
      A[1] -= avg - a;
      A[i] += avg - a;
      ans.push_back({{i, 1}, x});
      A[i] -= x*i;
      A[1] += x*i;
      assert(A[i] == avg);
    }
  }

  for (int i=2; i<=N; i++) {
    if (A[i] < avg) {
      ans.push_back({{1, i}, avg - A[i]});
      A[1] -= avg - A[i];
      A[i] += avg - A[i];
    }
  }

  cout << ans.size() << endl;
  for (auto [ij, x]: ans) {
    auto [i, j] = ij;
    cout << i << ' ' << j << ' ' << x << endl;
  }

  // for (int i=1; i<=N; i++) cout << A[i] << ", ";
  // cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
