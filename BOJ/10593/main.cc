#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 105;
int n, vst[MN][MN*MN];

struct FSM { int state, nxt[3]; };
FSM A[MN], B[MN*MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n;
  for (int i=0; i<n; i++) {
    char c; int r, p, s; cin >> c >> r >> p >> s;
    if (c == 'R') A[i].state = 0;
    if (c == 'P') A[i].state = 1;
    if (c == 'S') A[i].state = 2;
    A[i].nxt[0] = r-1;
    A[i].nxt[1] = p-1;
    A[i].nxt[2] = s-1;
  }
  for (int i=0; i<n*n; i++) {
    B[i].state = (A[i%n].state + 1) % 3;
    B[i].nxt[0] = B[i].nxt[1] = B[i].nxt[2] = -1;
  }

  for (int k=0; k<n; k++) {
    for (int i=0; i<n; i++) fill(vst[i], vst[i] + n*n, 0);

    int u = k, v = 0;
    while (true) {
      if (vst[u][v]) break;
      vst[u][v] = true;

      int &u1 = A[u].nxt[B[v].state];
      int &v1 = B[v].nxt[A[u].state];
      if (v1 == -1) v1 = n * k + u1;

      u = u1;
      v = v1;
    }
  }

  cout << n*n << endl;
  for (int i=0; i<n*n; i++) {
    if (B[i].state == 0) cout << "R ";
    if (B[i].state == 1) cout << "P ";
    if (B[i].state == 2) cout << "S ";
    for (int j=0; j<3; j++) {
      if (B[i].nxt[j] == -1) cout << 1 << " ";
      else cout << B[i].nxt[j] + 1 << " ";
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
