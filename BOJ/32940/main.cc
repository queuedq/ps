#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 255;
int N, A[MN][MN];
int P[MN][MN]; // flip pos in each row

struct Rect { int r1, c1, r2, c2; };
vector<Rect> ans;

void draw_rect(int r1, int c1, int r2, int c2) {
  if (r1 > r2) swap(r1, r2);
  if (c1 > c2) swap(c1, c2);
  ans.push_back({r1, c1, r2, c2});
}

void match(int r1, int r2, vector<int> &F) {
  while (F.size() >= 2) {
    int c1 = F.back(); F.pop_back();
    int c2 = F.back(); F.pop_back();
    draw_rect(r1, c1, r2, c2);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int r=0; r<N; r++) {
    for (int c=0; c<N; c++) {
      char ch; cin >> ch;
      A[r][c] = ch - '0';
    }
  }

  for (int r=0; r<N; r++) {
    int prv = 0;
    for (int c=0; c<N; c++) {
      P[r][c] = prv ^ A[r][c];
      prv = A[r][c];
    }
  }

  // two rows at a time
  for (int r=0; r<N; r+=2) {
    vector<int> F[2][2]; // flip pos for each (up, down) type
    for (int c=0; c<N; c++) {
      bool a = P[r][c], b = P[r+1][c];
      F[a][b].push_back(c);
    }

    // match same types
    match(r, r+1, F[1][0]);
    match(r+1, r+2, F[0][1]);
    match(r, r+2, F[1][1]);

    // match remaining
    int i = sz(F[1][0]) ? F[1][0][0] : N;
    int j = sz(F[0][1]) ? F[0][1][0] : N;
    int k = sz(F[1][1]) ? F[1][1][0] : N;
    if (i < N && j < N && k < N) {
      draw_rect(r, i, r+1, k);
      draw_rect(r+1, j, r+2, k);
    } else {
      if (i < N) draw_rect(r, i, r+1, N);
      if (j < N) draw_rect(r+1, j, r+2, N);
      if (k < N) draw_rect(r, k, r+2, N);
    }
  }

  // print ans
  cout << sz(ans) << endl;
  for (auto [r1, c1, r2, c2]: ans) {
    cout << r1+1 << " " << c1+1 << " " << r2 << " " << c2 << endl;
  }

  ////////////////////////////////
  return 0;
}
