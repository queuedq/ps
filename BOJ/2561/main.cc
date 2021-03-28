#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N, A[MAXN];
vector<pii> ans;

bool single() {
  int a, b;
  for (a=1; a<=N; a++) { if (A[a] != a) break; }
  for (b=N; b>=1; b--) { if (A[b] != b) break; }
  if (a == N+1) a = b = 1;

  for (int i=a; i<=b; i++) {
    if (A[i] != a+b-i) return false;
  }
  ans.push_back({a, b+1}); return true;
}

bool solve(int n) {
  if (n == 1) return single();

  set<int> cand;
  for (int i=1; i<=N+1; i++) {
    if (abs(A[i] - A[i-1]) > 1) {
      if (i-1 >= 1) cand.insert(i-1);
      cand.insert(i);
      if (i+1 <= N+1) cand.insert(i+1);
    }
  }

  for (auto a: cand) {
    for (auto b: cand) {
      if (a >= b) continue;
      reverse(A+a, A+b);
      if (solve(n-1)) { ans.push_back({a, b}); return true; }
      reverse(A+a, A+b);
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  A[N+1] = N+1;

  if (!solve(3)) {
    cout << "1 1\n1 1\n1 1" << endl;
  } else {
    assert(ans.size() == 3);
    reverse(ans.begin(), ans.end());
    for (auto [a, b]: ans) cout << a << " " << b-1 << endl;
  }

  ////////////////////////////////
  return 0;
}
