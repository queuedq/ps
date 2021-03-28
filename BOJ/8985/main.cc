#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
struct Rect { lld l, r, h; };
vector<Rect> aqua;
vector<lld> heights, holes;
lld totalArea;

class RMQ {
public:
  vector<pll> arr;
  int start;

  RMQ(int size) {
    int arrSize = 1;
    while (arrSize < size * 2) { arrSize <<= 1; }
    arr.resize(arrSize);
    start = arrSize / 2;
  }

  void build(const vector<lld> &a) {
    for (int i = 0; i < start; i++) { arr[start+i] = {LLONG_MAX, -1}; }
    for (int i = 0; i < a.size(); i++) { arr[start+i] = {a[i], i}; }
    for (int node = start-1; node > 0; node--) {
      arr[node] = min(arr[node*2], arr[node*2+1]);
    }
  }

  pll query(int l, int r) { return query(1, 0, start, l, r); }
  pll query(int node, int nl, int nr, int l, int r) {
    if (nr <= l || r <= nl) return {LLONG_MAX, -1};
    if (l <= nl && nr <= r) return arr[node];
    int mid = (nl + nr) / 2;
    return min(query(node*2, nl, mid, l, r), query(node*2+1, mid, nr, l, r));
  }
} rmq(300'000);

void input() {
  // Aquarium
  lld N; cin >> N; N = N/2-1;
  map<lld, lld> idx;
  lld zero; cin >> zero >> zero;
  for (int i = 0; i < N; i++) {
    lld l, r, h;
    cin >> l >> h;
    cin >> r >> h;
    aqua.push_back({l, r, h});
    heights.push_back(h);
    idx[l] = i;
    totalArea += (r - l) * h;
  }
  cin >> zero >> zero;

  // Holes
  lld M; cin >> M;
  vector<lld> ho; ho.resize(N); holes.resize(N+1);
  for (int i = 0; i < M; i++) {
    lld l, r, h; cin >> l >> h >> r >> h;
    ho[idx[l]]++;
  }

  for (int i = 1; i <= N; i++) {
    holes[i] = holes[i-1] + ho[i-1];
  }
}

pair<lld, double> calc(int l, int r, lld h) {
  lld numHoles = holes[r] - holes[l];
  if (numHoles == 0) { return {0, 0}; }

  pll q = rmq.query(l, r);
  lld hh = q.first, i = q.second;

  lld area = (hh - h) * (aqua[r-1].r - aqua[l].l);
  double time = (double)area / numHoles;

  pair<lld, double> a = calc(l, i, hh);
  pair<lld, double> b = calc(i+1, r, hh);
  return {area + a.first + b.first, time + max(a.second, b.second)};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  rmq.build(heights);

  auto res = calc(0, aqua.size(), 0);
  cout << fixed << setprecision(2) << res.second << endl;
  cout << totalArea - res.first << endl;

  ////////////////////////////////
  return 0;
}
