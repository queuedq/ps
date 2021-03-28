#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 150'000;
const int ST = 1<<18;

struct Line {
  int l, r, id;
  bool operator <(const Line &L) const { return l < L.l; }
};
bool cmpById(const Line &A, const Line &B) { return A.id < B.id; }

int N, Q, mx[MAXN];
Line line[MAXN];
vector<int> coords;
int nxt[MAXN*2][21];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> line[i].l >> line[i].r;
    line[i].id = i;
    coords.push_back(line[i].l);
    coords.push_back(line[i].r);
  }

  sort(line, line+N);
  sort(coords.begin(), coords.end());

  for (int i=0; i<N; i++) {
    line[i].l = lower_bound(coords.begin(), coords.end(), line[i].l) - coords.begin();
    line[i].r = lower_bound(coords.begin(), coords.end(), line[i].r) - coords.begin();
    mx[i] = i == 0 ? line[i].r : max(mx[i-1], line[i].r);
  }

  for (int x=0; x<coords.size(); x++) {
    int e = lower_bound(line, line+N, Line({x+1, -1, -1})) - line - 1;
    nxt[x][0] = mx[e];
  }

  for (int j=1; j<=20; j++) {
    for (int x=0; x<coords.size(); x++) {
      nxt[x][j] = nxt[nxt[x][j-1]][j-1];
    }
  }

  sort(line, line+N, cmpById);
  cin >> Q;

  for (int i=0; i<Q; i++) {
    int a, b; cin >> a >> b; a--; b--;
    if (line[a].r > line[b].r) swap(a, b);
    int x = line[a].r, y = line[b].l;

    if (nxt[x][20] < y) { cout << -1 << endl; continue; }
    if (x >= y) { cout << 1 << endl; continue; }

    int ans = 0;
    for (int j=20; j>=0; j--) {
      if (nxt[x][j] < y) {
        x = nxt[x][j];
        ans += 1<<j;
      }
    }
    cout << ans+2 << endl;
  }

  ////////////////////////////////
  return 0;
}
