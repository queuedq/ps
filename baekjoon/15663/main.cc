#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
int A[8], ans[8];
bool used[8];

void solve(int s) {
  if (s == M) {
    for (int i=0; i<M; i++) cout << ans[i] << " ";
    cout << endl;
    return;
  }

  int prv = -1;
  for (int i=0; i<N; i++) {
    if (used[i] || A[i] == prv) continue;
    used[i] = true;
    ans[s] = A[i];
    solve(s+1);
    used[i] = false;
    prv = A[i];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];
  sort(A, A+N);
  solve(0);

  ////////////////////////////////
  return 0;
}
