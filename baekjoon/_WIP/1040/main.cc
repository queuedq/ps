#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, used, cnt[10], ans[19], found;
string N;

void solve(int i, bool big) {
  if (i == N.size() || found) { found = true; return; }

  int d = big ? 0 : N[i]-'0';
  while (used == K && d <= 9 && cnt[d] == 0) d++;
  if (d == 10) return;

  for (; d<=9; d++) {
    if (found) return;
    ans[i] = d;
    if (cnt[d]++ == 0) used++;
    solve(i+1, big || d>N[i]-'0');
    if (--cnt[d] == 0) used--;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  solve(0, 0);

  for (int i=0; i<N.size(); i++) cout << ans[i];

  ////////////////////////////////
  return 0;
}
