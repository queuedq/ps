#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 8005;
const int MK = 805;
lld N, K, C[MN], psum[MN], D[MN];

lld cost(int l, int r) { return (psum[r] - psum[l-1]) * (r-l+1); }

struct Line {
  lld i, d, c; // Line starts at c (cross)
  lld get(int x) { return d + cost(i+1, x); }
  bool operator <(const Line &L) const { return c < L.c; }

  int cross(Line &L) { // i < L.i
    int l = L.i - 1, r = N+1;
    while (l+1 < r) {
      int m = (l+r)/2;
      if (L.get(m) <= get(m)) r = m; // L is better
      else l = m;
    }
    return r;
  }
};
vector<Line> mq;

void add(Line L) {
  while (!mq.empty() && mq.back().cross(L) <= mq.back().c) mq.pop_back();
  if (!mq.empty()) L.c = mq.back().cross(L);
  mq.push_back(L);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    cin >> C[i];
    psum[i] = psum[i-1] + C[i];
  }

  for (int i=1; i<=N; i++) D[i] = psum[i] * i;
  for (int k=2; k<=K; k++) {
    mq.clear();
    int l = 0;
    for (int i=0; i<=N; i++) {
      add({i, D[i], i});
      while (l+1 < mq.size() && mq[l+1].c <= i) l++;
      D[i] = min(D[i], mq[l].get(i));
    }
  }

  cout << D[N] << endl;

  ////////////////////////////////
  return 0;
}
