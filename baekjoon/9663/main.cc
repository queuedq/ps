#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 15;
int N, ans, v[MAXN], d1[MAXN*2], d2[MAXN*2];

void solve(int i) {
  if (i == N) { ans++; return; }
  for (int j=0; j<N; j++) {
    if (v[j] || d1[i+j] || d2[i-j+N]) continue;

    v[j]++;
    d1[i+j]++;
    d2[i-j+N]++;

    solve(i+1);

    v[j]--;
    d1[i+j]--;
    d2[i-j+N]--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  solve(0);

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
