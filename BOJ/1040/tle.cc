#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int K, used, cnt[10], ans[19];
string N;

bool solve(int i, bool big) { // # of digits is same as N
  if (i == N.size()) return used == K;

  int d = big ? 0 : N[i]-'0';
  while (used == K && d <= 9 && cnt[d] == 0) d++;
  if (d == 10) return false;

  for (; d<=9; d++) {
    if (used == K && cnt[d] == 0) continue;
    ans[i] = d;
    if (cnt[d]++ == 0) used++;
    bool found = solve(i+1, big || d>N[i]-'0');
    if (found) return true;
    if (--cnt[d] == 0) used--;
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  bool found = solve(0, 0);
  
  if (found) {
    for (int i=0; i<N.size(); i++) cout << ans[i];
  } else if (K > N.size()) {
    cout << 10;
    for (int i=2; i<K; i++) cout << i;
  } else {
    cout << 1;
    for (int i=0; i<N.size()-K+2; i++) cout << 0;
    for (int i=2; i<K; i++) cout << i;
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
