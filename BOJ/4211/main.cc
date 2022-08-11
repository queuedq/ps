#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

queue<int> input;
void get_stdin() { int x; while (cin >> x) input.push(x); }
void get(int &x) { x = input.front(); input.pop(); }

////////////////////////////////////////////////////////////////
// [Directions]
//   3
// 2   0
//   1
// [Mirror] / = 3, \ = 1 (xor)

////////////////////////////////
// init

const int ST = 1<<20;
int R, C;
unordered_map<int, vector<pii>> rows, cols;

void init() {
  int M, N;
  get(R), get(C), get(M), get(N);
  for (int i=0; i<M; i++) {
    int r, c; get(r), get(c);
    rows[r].push_back({c, 3});
    cols[c].push_back({r, 3});
  }
  for (int i=0; i<N; i++) {
    int r, c; get(r), get(c);
    rows[r].push_back({c, 1});
    cols[c].push_back({r, 1});
  }

  // laser start/end rows (create empty vector)
  rows[1]; rows[R];
  // oob protection
  for (auto &[k, v]: rows) v.push_back({0, 0}), v.push_back({C+1, 0});
  for (auto &[k, v]: cols) v.push_back({0, 0}), v.push_back({R+1, 0});
  // sort
  for (auto &[k, v]: rows) sort(all(v));
  for (auto &[k, v]: cols) sort(all(v));

  // for (auto &[k, v]: rows) {
  //   cout << k << ": ";
  //   for (auto [c, d]: v) cout << "(" << c << "," << d << ") "; cout << endl;
  // }
}

////////////////////////////////
// laser

struct Event { // ver line event
  int r, c, add, color;
  bool operator <(Event E) const { return r < E.r; }
};
vector<Event> E;

struct Line { // hor line
  int r, c1, c2, color;
  bool operator <(Line H) const { return pii(r, c1) < pii(H.r, H.c1); }
};
vector<Line> L;

tuple<int, int, int> next_hit(int r, int c, int d) {
  if (d == 0 || d == 2) {
    auto it = lower_bound(all(rows[r]), pii(c, 0));
    if (d == 0) it++; else it--;
    return {r, it->first, d ^ it->second};
  } else {
    auto it = lower_bound(all(cols[c]), pii(r, 0));
    if (d == 1) it++; else it--;
    return {it->first, c, d ^ it->second};
  }
}

bool oob(int r, int c) { return r <= 0 || r > R || c <= 0 || c > C; }

void add_line(int r1, int c1, int r2, int c2, int color) {
  if (r1 == r2) { // hor
    L.push_back({r1, min(c1, c2), max(c1, c2), color});
  } else { // ver
    assert(c1 == c2);
    E.push_back({min(r1, r2), c1, 1, color});
    E.push_back({max(r1, r2), c1, -1, color});
  }
}

// 0 if opens without mirror
bool laser() {
  // from start, color = 0
  int r = 1, c = 0, d = 0, color = 0, nr, nc;
  do {
    tie(nr, nc, d) = next_hit(r, c, d);
    add_line(r, c, nr, nc, color);
    r = nr, c = nc;
  } while (!oob(r, c));

  // opens without mirror
  if (r == R && c == C+1) return 0;

  // from end, color = 1
  r = R, c = C+1, d = 2, color = 1;
  do {
    tie(nr, nc, d) = next_hit(r, c, d);
    add_line(r, c, nr, nc, color);
    r = nr, c = nc;
  } while (!oob(r, c));

  // sort events and lines
  sort(all(E)); sort(all(L));

  // cout << "E" << endl;
  // for (auto [r, c, add, color]: E) cout << r << " " << c << " " << add << " " << color << endl;
  // cout << "L" << endl;
  // for (auto [r, c1, c2, color]: L) cout << r << " " << c1 << " " << c2 << " " << color << endl;
  return 1;
}

////////////////////////////////
// sweep

vector<int> sum_seg[2], min_seg[2];

void seg_add(int i, int x, int color) {
  i += ST;
  sum_seg[color][i] += x;
  min_seg[color][i] = sum_seg[color][i] ? i-ST : ST;
  for (i/=2; i>0; i/=2) {
    sum_seg[color][i] = sum_seg[color][i*2] + sum_seg[color][i*2+1];
    min_seg[color][i] = min(min_seg[color][i*2], min_seg[color][i*2+1]);
  }
}

pll seg_qry(int l, int r, int color) {
  lld ret = 0, lwb = ST;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) {
      ret += sum_seg[color][l];
      lwb = min(lwb, (lld)min_seg[color][l]);
      l++;
    }
    if (r&1) {
      --r;
      ret += sum_seg[color][r];
      lwb = min(lwb, (lld)min_seg[color][r]);
    }
  }
  return {ret, lwb};
}

void sweep() {
  sum_seg[0].resize(ST*2); sum_seg[1].resize(ST*2);
  min_seg[0].assign(ST*2, ST); min_seg[1].assign(ST*2, ST);

  lld i = 0, tot = 0, found = 0, mr, mc;
  for (auto [r, c1, c2, color]: L) {
    // calc active cols
    while (i < sz(E) && E[i].r <= r) {
      seg_add(E[i].c, E[i].add, E[i].color);
      i++;
    }
    // get intersections
    auto [cnt, lwb] = seg_qry(c1+1, c2-1, !color);
    tot += cnt;
    // first intersection
    if (!found && cnt > 0) found = 1, mr = r, mc = lwb;
  }
  
  if (found) cout << tot << " " << mr << " " << mc << endl;
  else cout << "impossible" << endl;
}

void reset() {
  rows.clear(); cols.clear();
  E.clear(); L.clear();
  sum_seg[0].clear(); sum_seg[1].clear();
  min_seg[0].clear(); min_seg[1].clear();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  get_stdin();
  for (int t=1; sz(input); t++) {
    cout << "Case " << t << ": ";
    init();
    if (laser()) sweep();
    else cout << 0 << endl;
    reset();
  }

  ////////////////////////////////
  return 0;
}
