#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
const int INF = 1e9;
int N, st[MAXN], ed[MAXN], D[MAXN][10], E[MAXN][10];

int add(int a, int b) { return (a+b) % 10; }
int sub(int a, int b) { return (a-b+10) % 10; }

void traceback(int i, int j) {
  if (E[i][j] != 0) cout << N-i << " " << E[i][j] << endl;
  if (i == 0) return;
  if (E[i][j] > 0) {
    int s = (j-E[i][j]-(ed[i]-ed[i-1]) + 20) % 10;
    traceback(i-1, s);
  } else {
    int s = (j-(ed[i]-ed[i-1]) + 10) % 10;
    traceback(i-1, s);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  string a, b;
  cin >> N >> a >> b;
  for (int i = 0; i < N; i++) {
    st[i] = a[N-i-1] - '0';
    ed[i] = b[N-i-1] - '0';
  }

  for (int i = 0; i < N; i++) fill(D[i], D[i]+10, INF);

  for (int j = 0; j < 10; j++) {
    int dist = sub(j, st[0]);
    if (dist <= 5) {
      D[0][j] = dist;
      E[0][j] = dist;
    } else {
      D[0][j] = 10 - dist;
      E[0][j] = dist - 10;
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < 10; j++) {
      int diff = sub(ed[i], ed[i-1]);
      int s0 = sub(st[i], diff);
      if ( D[i-1][s0] + sub(j, st[i]) < D[i][j] ) {
        D[i][j] = D[i-1][s0] + sub(j, st[i]);
        E[i][j] = sub(j, st[i]);
      }
      int s1 = sub(j, diff);
      if ( D[i-1][s1] + sub(st[i], j) < D[i][j] ) {
        D[i][j] = D[i-1][s1] + sub(st[i], j);
        E[i][j] = -sub(st[i], j);
      }
    }
  }

  // for (int j = 0; j < 10; j++) cout << j << " ";
  // cout << endl;
  // cout << "====================" << endl;
  // for (int i = 0; i < N; i++) {
  //   for (int j = 0; j < 10; j++) cout << D[i][j] << " ";
  //   cout << endl;
  // }

  cout << D[N-1][ed[N-1]] << endl;
  traceback(N-1, ed[N-1]);

  ////////////////////////////////
  return 0;
}
