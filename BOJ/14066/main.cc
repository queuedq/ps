#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int CTR = 300;
int M, N, u, d, l, r;
char pic[CTR*2][CTR*2];
string cube[6] = {
  "..+---+",
  "./   /|",
  "+---+ |",
  "|   | +",
  "|   |/.",
  "+---+..",
};

void place(int i, int j, int k) {
  int x = i*2 - k*3, y = -i*2 + j*4;
  for (int a=0; a<6; a++) {
    for (int b=0; b<7; b++) {
      if (cube[a][b] != '.') pic[CTR+x+a][CTR+y+b] = cube[a][b];
    }
  }
  u = min(u, x);
  d = max(d, x+5);
  l = min(l, y);
  r = max(r, y+6);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  u = d = l = r = 0;

  cin >> M >> N;
  for (int i=0; i<M; i++) {
    for (int j=0; j<N; j++) {
      int A; cin >> A;

      for (int k=0; k<A; k++) place(i, j, k);
    }
  }

  for (int x=u; x<=d; x++) {
    for (int y=l; y<=r; y++) {
      if (pic[CTR+x][CTR+y] == 0) cout << '.';
      else cout << pic[CTR+x][CTR+y];
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
