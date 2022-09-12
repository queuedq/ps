#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, vst[MN];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> S;
  N = sz(S);

  queue<int> Q;

  for (int i=0; i<N; i++) { // BC
    if (S[i] == 'B') Q.push(i);
    if (S[i] == 'C' && !Q.empty()) { vst[Q.front()] = 1; Q.pop(); }
  }

  while (!Q.empty()) Q.pop();

  for (int i=N-1; i>=0; i--) { // AB
    if (S[i] == 'B') Q.push(i);
    if (S[i] == 'A' && !Q.empty()) { vst[Q.front()] = 1; Q.pop(); }
  }

  int ans = 0;
  for (int i=0; i<N; i++) ans += vst[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
