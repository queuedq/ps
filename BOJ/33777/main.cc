#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, vst[MN*2];
string S;
pii ans[MN];

void solve() {
  cin >> N >> S;
  fill_n(vst+1, N*2, 0);

  int a = 1, b = 2; // smallest available indicies
  for (int i=0; i<N; i++) {
    bool sum_parity = (a+b) % 2;
    bool given_parity = S[i] == 'O';

    if (sum_parity != given_parity) b++;
    if (b > N*2) { cout << "NO" << endl; return; }

    vst[a] = vst[b] = 1;
    ans[i] = {a, b};

    while (vst[a]) a++;
    b = a+1;
    while (vst[b]) b++;
  }

  cout << "YES" << endl;
  for (int i=0; i<N; i++) {
    auto [a, b] = ans[i];
    cout << a << " " << b << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
