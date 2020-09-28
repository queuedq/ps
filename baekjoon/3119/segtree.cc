#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 100005;
const int ST_SIZE = 1 << 19;
int N;
vector<int> coords, heights;

struct Plank {
  int l, r, h, i;
};

bool cmp(Plank a, Plank b) {
  return pair<int, pii>{a.h, {a.l, -a.r}} < pair<int, pii>{b.h, {b.l, -b.r}};
}

Plank P[MAX_N];
vector<Plank> PH[MAX_N], selection;

struct SegTree {
  const int start = ST_SIZE / 2;
  bool seg[ST_SIZE]; // lazy not needed, since we'll only update to true

  SegTree() {
    fill(seg, seg + ST_SIZE, false);
  }

  void propagate(int node) {
    if (seg[node] == true) {
      if (node < start) {
        seg[node*2] = true;
        seg[node*2+1] = true;
      }
    }
  }

  void update(int l, int r) { update(1, 0, start, l, r); }
  void update(int node, int nl, int nr, int l, int r) {
    propagate(node);
    if (r <= nl || nr <= l) { return; }
    if (l <= nl && nr <= r) {
      seg[node] = true;
      return;
    }
    int mid = (nl + nr) / 2;
    update(node*2, nl, mid, l, r);
    update(node*2+1, mid, nr, l, r);
    seg[node] = seg[node*2] && seg[node*2+1];
  }

  bool query(int l, int r) { return query(1, 0, start, l, r); }
  bool query(int node, int nl, int nr, int l, int r) {
    propagate(node);
    if (r <= nl || nr <= l) { return true; }
    if (l <= nl && nr <= r) { return seg[node]; }
    int mid = (nl + nr) / 2;
    return query(node*2, nl, mid, l, r) && query(node*2+1, mid, nr, l, r);
  }
} seg;

void input() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    int X, W, H; cin >> X >> W >> H;
    P[i] = {X, X+W, H, i+1};
    coords.push_back(X);
    coords.push_back(X+W);
    heights.push_back(H);
  }
}

void compress() {
  sort(coords.begin(), coords.end());
  coords.resize(unique(coords.begin(), coords.end()) - coords.begin());
  sort(heights.begin(), heights.end());
  heights.resize(unique(heights.begin(), heights.end()) - heights.begin());
  for (int i = 0; i < N; i++) {
    P[i].l = lower_bound(coords.begin(), coords.end(), P[i].l) - coords.begin();
    P[i].r = lower_bound(coords.begin(), coords.end(), P[i].r) - coords.begin();
    P[i].h = lower_bound(heights.begin(), heights.end(), P[i].h) - heights.begin();
  }
}

void sortPlanks() {
  sort(P, P + N, cmp);

  int prevH = -1, prevR = -1;
  for (int i = 0; i < N; i++) {
    if (P[i].h == prevH && P[i].r <= prevR) {
      continue;
    }
    PH[P[i].h].push_back(P[i]);
    prevH = P[i].h; prevR = P[i].r;
  }
}

void select(vector<Plank> &planks) {
  planks.push_back({INT_MAX, INT_MAX, 0, -1}); // Only q->l is important
  for (auto p = planks.begin(), q = p+1; q != planks.end(); p++, q++) {
    // cout << p->l << " " << p->r << " " << p->h << " " << p->i << endl;
    assert(p->l < q->l);
    assert(p->r < q->r);
    if(!seg.query(p->l, min(p->r, q->l))) {
      selection.push_back(*p);
      seg.update(p->l, p->r);
    };
  }
}

void sweep() {
  for (int h = N; h >= 0; h--) {
    select(PH[h]);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  compress();
  sortPlanks();
  sweep();

  sort(selection.begin(), selection.end(), [](Plank a, Plank b) { return a.i < b.i; });
  cout << selection.size() << endl;
  for (int i = 0; i < selection.size() - 1; i++) {
    cout << selection[i].i << " ";
  }
  cout << selection[selection.size() - 1].i << endl;

  ////////////////////////////////
  return 0;
}
