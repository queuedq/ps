#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
bool p[4];
vector<int> tower[4];
vector<pii> ans;

void print() {
  for (int i=1; i<=3; i++) {
    cout << "[" << i << "] ";
    for (auto x: tower[i]) cout << x;
    cout << endl;
  }
}

void move(int s, int t) {
  int x = tower[s].size();
  int y = tower[t].size();
  int v = tower[s][x/2];
  tower[s].erase(tower[s].begin() + x/2);
  tower[t].insert(tower[t].begin() + (y+1)/2, v);
  // for (int i=1; i<=3; i++) assert(is_sorted(tower[i].begin(), tower[i].end()));
  ans.push_back({s, t});
  // cout << s << " " << t << endl;
  // print();
}

void hanoi(int l, int r, int s, int t) {
  if (l > r) return;
  if (l == r) { move(s, t); return; }

  // cout << l << " " << r << " " << p[1] << " " << p[2] << " " << p[3] << " " << s << " " << t << endl;

  int last = 0;
  if (!p[s]) { // last move: l
    if (!p[t]) { // last move one disk
      p[s] = !p[s];
      hanoi(l+1, r, s, s^t);
      p[s] = !p[s];
      p[t] = !p[t];
      move(s, t);
      hanoi(l+1, r, s^t, t);
      p[t] = !p[t];
    } else { // last move two disks
      hanoi(l+1, r-1, s, s^t);
      move(s, t);
      move(s, t);
      hanoi(l+1, r-1, s^t, t);
    }
  } else { // last move: r
    if (p[t]) { // last move one disk
      p[s] = !p[s];
      hanoi(l, r-1, s, s^t);
      p[s] = !p[s];
      p[t] = !p[t];
      move(s, t);
      hanoi(l, r-1, s^t, t);
      p[t] = !p[t];
    } else { // last move two disks
      hanoi(l+1, r-1, s, s^t);
      move(s, t);
      move(s, t);
      hanoi(l+1, r-1, s^t, t);
    }
  }
  // cout << "end of " << l << " " << r << " " << p[1] << " " << p[2] << " " << p[3] << " " << s << " " << t << endl;
}

void solve(int test) {
  N = 21;
  // cin >> N;
  for (int i=1; i<=N; i++) tower[1].push_back(i);

  hanoi(1, N, 1, 3);

  cout << "Case #1" << endl;
  cout << N << endl;
  for (auto [s, t]: ans) {
    if (s == 1 && t == 2) cout << 'A';
    if (s == 1 && t == 3) cout << 'B';
    if (s == 2 && t == 1) cout << 'C';
    if (s == 2 && t == 3) cout << 'D';
    if (s == 3 && t == 1) cout << 'E';
    if (s == 3 && t == 2) cout << 'F';
  }
  cout << endl;
  // cout << ans.size() << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T, M; cin >> T >> M;
  solve(1);

  ////////////////////////////////
  return 0;
}
