#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
int N, A[MAXN];
vector<int> D;

vector<int> find() {
  for (auto a: D) {
    for (auto b: D) {
      if (a == b) continue;

      reverse(A+a, A+b);

      vector<int> E;
      int c = 1, d = 2;
      for (int i=1; i<=N+1; i++) {
        if (abs(A[i] - A[i-1]) > 1) E.push_back(i);
      }
      if (E.size() == 2) {
        c = E[0];
        d = E[1];
      }

      reverse(A+c, A+d);

      bool ok = true;
      for (int i=1; i<=N; i++) {
        if (A[i] != i) ok = false;
      }
      if (ok) return {a, b, c, d};

      reverse(A+c, A+d);
      reverse(A+a, A+b);
    }
  }

  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  A[N+1] = N+1;

  D.push_back(1);
  D.push_back(2);
  for (int i=1; i<=N+1; i++) {
    if (abs(A[i] - A[i-1]) > 1) {
      D.push_back(i-1);
      D.push_back(i);
      D.push_back(i+1);
    }
  }

  sort(D.begin(), D.end());

  auto ans = find();
  cout << ans[0] << " " << ans[1]-1 << endl;
  cout << ans[2] << " " << ans[3]-1 << endl;

  ////////////////////////////////
  return 0;
}
