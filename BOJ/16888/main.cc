#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 1e6 + 1;
bool D[MAX_N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  for (int i = 1; i <= MAX_N; i++) {
    for (int j = 1; j*j <= i; j++) {
      D[i] = D[i] || !D[i - j*j];
    }
  }

  int T; cin >> T;
  for (int i = 0; i < T; i++) {
    int N; cin >> N;
    cout << (D[N] ? "koosaga" : "cubelover") << endl;
  }

  ////////////////////////////////
  return 0;
}
