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
int N;
int done[MN]; // color sorted?
vector<int> spare; // empty spaces' pole number
vector<int> P[MN]; // pole's disk colors
vector<pii> ans;

// temporary data
struct Disk {
  int pole, j;
  bool operator <(const Disk &D) const { return j > D.j; } // small depth (= size - j) first
};
vector<Disk> disk[MN];

void move(int a, int b) {
  assert(sz(P[a]) > 0 && sz(P[b]) < 3);
  P[b].push_back(P[a].back());
  P[a].pop_back();
  auto it = find(all(spare), b);
  *it = a;

  ans.push_back({a, b});
  // cout << "move " << a << " " << b << endl;
}

void calc_depth_seq() {
  for (int c=1; c<=N; c++) disk[c].clear();

  for (int i=1; i<=N+1; i++) {
    for (int j=0; j<sz(P[i]); j++) {
      int c = P[i][j];
      if (!done[c]) disk[c].push_back({i, j});
    }
  }

  for (int c=1; c<=N; c++) sort(all(disk[c]));
}

int min_depth_color() {
  int ret = 0;
  for (int c=1; c<=N; c++) {
    if (done[c]) continue;
    if (ret == 0 || disk[c] < disk[ret]) ret = c;
  }
  return ret;
}

int find_not(vector<int> &v, int a, int b) {
  for (auto e: v) {
    if (e != a && e != b) return e;
  }
  assert(0);
}

void DEBUG() {
  for (int j=2; j>=0; j--) {
    for (int i=1; i<=N+1; i++) {
      if (j < sz(P[i])) cout << P[i][j] << " ";
      else cout << "  ";
    } cout << endl;
  } cout << endl;
}

int main() {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) P[i].resize(3);
  for (int j=2; j>=0; j--) for (int i=1; i<=N; i++) cin >> P[i][j];
  spare = {N+1, N+1, N+1};

  // do N-1 sorts (last color gets auto-sorted)
  for (int cnt=0; cnt<N-1; cnt++) {
    calc_depth_seq();
    int c = min_depth_color(); // 111, 112, 113, 123
    int dest = spare[0];

    // move to dest
    for (auto [i, j]: disk[c]) {
      while (P[i].back() != c) {
        int to = find_not(spare, i, dest);
        move(i, to);
      }
      move(i, dest);
    }

    // clear pole
    int i = disk[c][2].pole;
    while (sz(P[i])) {
      int to = find_not(spare, i, dest);
      move(i, to);
    }

    // done
    done[c] = 1;
  }

  // empty last pole
  int dest = spare[0];
  if (sz(P[N+1])) move(N+1, dest), move(N+1, dest), move(N+1, dest);

  // print ans
  cout << sz(ans) << endl;
  for (auto [a, b]: ans) cout << a << " " << b << endl;

  ////////////////////////////////
  return 0;
}
