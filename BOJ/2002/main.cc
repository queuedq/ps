#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, vst[MN], ans;
map<string, int> ord;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) { string A; cin >> A; ord[A] = i; }
  for (int i=0; i<N; i++) {
    string B; cin >> B; int k = ord[B];
    vst[k] = 1;
    for (int j=0; j<k; j++) {
      if (!vst[j]) { ans++; break; }
    }
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
