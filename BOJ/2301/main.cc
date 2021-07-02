#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

vector<int> solve(int N, int s) {
  if (N == 2) return {s, !s};
  vector<int> ans;
  
  if (s < N/4 || s >= N*3/4) {
    if (s >= N/2) s -= N/2;
    auto A = solve(N/2, s);

    for (int i=0; i<N/2; i++) ans.push_back(A[i] < N/4 ? A[i] : A[i] + N/2);
    for (int i=0; i<N/2; i++) ans.push_back(A[i] + N/4);
  } else {
    auto A = solve(N/2, s - N/4);

    for (int i=0; i<N/2; i++) ans.push_back(A[i] + N/4);
    for (int i=0; i<N/2; i++) ans.push_back(A[i] < N/4 ? A[i] : A[i] + N/2);
  }
  
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N, s; cin >> N >> s;
  vector<int> ans = solve(N, s-1);
  for (auto a: ans) cout << a+1 << " ";

  ////////////////////////////////
  return 0;
}
