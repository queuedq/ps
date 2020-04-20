#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int T, R, S;
int A[50];
int B[50];
int temp[50];

void solve(int test) {
  cin >> R >> S;
  for (int i=0; i<R; i++) {
    for (int j=0; j<S; j++) {
      A[i+j*R] = i;
      B[i+j*R] = (i+j*R) / S;
    }
  }

  vector<pii> ans;

  while (true) {
    int r = S*R-1;
    while (r >= 0) {
      if (A[r] != B[r]) break;
      r--;
    }
    if (r == -1) break;
    int l = 0;
    while (true) {
      if (A[l] == B[r]) break;
      l++;
    }

    ans.push_back({l+1, r-l});
    for (int i=0; i<=l; i++) { temp[i] = A[i]; }
    for (int i=0; i<=r-l; i++) { A[i] = A[i+l+1]; }
    for (int i=r-l; i<=r; i++) { A[i] = temp[i-r+l]; }
  }

  cout << "Case #" << test << ": ";
  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); i++) {
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> T;
  for (int i=1; i<=T; i++) {
    solve(i);
  }

  ////////////////////////////////
  return 0;
}
