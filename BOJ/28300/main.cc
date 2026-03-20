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
int N, Q, A[MN][MN], dx[4], dy[4], t[4];

struct Point { int x, y; };

int mod(int x, int m) { return (x%m+m)%m; }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  t[0] = 0, t[1] = 1, t[2] = 2, t[3] = 3;

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) A[i][j] = i*N+j+1;
  }

  for (int q=0; q<Q; q++) {
    string S; cin >> S;
    if (S == "RO") dy[t[0]]++, dy[t[1]]++, swap(t[0], t[1]);
    if (S == "RE") dy[t[2]]++, dy[t[3]]++, swap(t[2], t[3]);
    if (S == "CO") dx[t[0]]++, dx[t[2]]++, swap(t[0], t[2]);
    if (S == "CE") dx[t[1]]++, dx[t[3]]++, swap(t[1], t[3]);
    if (S == "S") {
      int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
      x1--, y1--, x2--, y2--;
      int o1 = t[x1%2*2 + y1%2], o2 = t[x2%2*2 + y2%2];
      Point p1 = {mod(x1-dx[o1], N), mod(y1-dy[o1], N)};
      Point p2 = {mod(x2-dx[o2], N), mod(y2-dy[o2], N)};
      swap(A[p1.x][p1.y], A[p2.x][p2.y]);
    }
  }

  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      int o = t[i%2*2 + j%2];
      Point p = {mod(i-dx[o], N), mod(j-dy[o], N)};
      cout << A[p.x][p.y] << " ";
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
