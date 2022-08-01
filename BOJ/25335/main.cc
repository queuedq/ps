#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M, R, G, B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0, x, y; i<N; i++) cin >> x >> y;
  for (int i=0, u, v; i<M; i++) {
    char c; cin >> u >> v >> c;
    R += c == 'R';
    G += c == 'G';
    B += c == 'B';
  }
  if (R + G-G/2 > B + G/2) cout << "jhnah917" << endl;
  else cout << "jhnan917" << endl;

  ////////////////////////////////
  return 0;
}
