#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const pii dir[4] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
const int MN = 303030;
int N, Q, A[MN];
pii pos[MN];
map<pii, vector<int>> idx; // inv of pos
pii D[MN]; // D[i]: when pushable rock is on pos[i], final coord of rock

pii operator +(const pii &a, const pii &b) { return {a.X + b.X, a.Y + b.Y}; }
pii operator -(const pii &a, const pii &b) { return {a.X - b.X, a.Y - b.Y}; }
ostream& operator <<(ostream &os, const pii &a) { return os << a.X << " " << a.Y; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    char c; cin >> c;
    if (c == 'L') A[i] = 0;
    if (c == 'R') A[i] = 1;
    if (c == 'U') A[i] = 2;
    if (c == 'D') A[i] = 3;
  }

  pos[0] = {0, 0};
  idx[{0, 0}].push_back(0);
  for (int i=1; i<=N; i++) {
    pos[i] = pos[i-1] + dir[A[i]];
    idx[pos[i]].push_back(i);
  }

  D[N] = pos[N] + dir[A[N]];
  for (int i=N-1; i>=1; i--) {
    pii P = pos[i] + dir[A[i]];
    int j = lower_bound(idx[P].begin(), idx[P].end(), i) - idx[P].begin();
    if (j == idx[P].size()) D[i] = P;
    else D[i] = D[idx[P][j]];
  }

  // for (int i=1; i<=N; i++) cout << D[i].X << "," << D[i].Y << endl;

  cin >> Q;
  for (int i=0; i<Q; i++) {
    int x, y; cin >> x >> y;
    if (idx[{-x, -y}].size() == 0) {
      cout << (pii(x, y) + pos[N]) << endl;
      continue;
    }
    cout << pos[N] - D[idx[{-x, -y}][0]] << endl;
  }

  ////////////////////////////////
  return 0;
}
