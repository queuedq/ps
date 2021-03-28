#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, A[100];

bool calc() {
  cin >> N;
  for (int i = 0; i < N; i++) { cin >> A[i]; }

  if (N % 2 == 1) { return true; }
  int e = 0, o = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] == 0) continue;
    if (i % 2 == 0) e++;
    else o++;
  }

  if (abs(e - o) <= 1) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    if (calc()) cout << "YES" << endl;
    else cout << "NO" << endl;
  }

  ////////////////////////////////
  return 0;
}
