#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, D[MN], diff[MN]; // diff[i]: results of comparison between i and i+1 differs

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> D[i];
  
  bool ans = true;
  for (int i=1; i<=N; i++) {
    if (D[i] > 2) { ans = false; break; } 
    if (D[i] == 2 && !diff[i-1]) { ans = false; break; }
    if (D[i] == 1) diff[i] = !diff[i-1];
    else diff[i] = diff[i-1];
  }
  if (diff[N]) ans = false;

  cout << (ans ? "YES" : "NO") << endl;

  ////////////////////////////////
  return 0;
}
