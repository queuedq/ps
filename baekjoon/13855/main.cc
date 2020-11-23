#include <bits/stdc++.h>
#define endl "\n"
#define X first
#define Y second
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pii> A;

bool check(const vector<pii> &P, int s, int cnt) {
  if (P.size() == 0) return true;

  int mnx = 1e9, mxx = 0, mny = 1e9, mxy = 0;
  for (int i=0; i<P.size(); i++) {
    mnx = min(mnx, P[i].X);
    mxx = max(mxx, P[i].X);
    mny = min(mny, P[i].Y);
    mxy = max(mxy, P[i].Y);
  }

  if (cnt == 1) return mxx - mnx <= s && mxy - mny <= s;

  vector<pii> Q[4];
  for (int i=0; i<P.size(); i++) {
    if (P[i].X > mnx + s || P[i].Y > mny + s) Q[0].push_back(P[i]);
    if (P[i].X > mnx + s || P[i].Y < mxy - s) Q[1].push_back(P[i]);
    if (P[i].X < mxx - s || P[i].Y > mny + s) Q[2].push_back(P[i]);
    if (P[i].X < mxx - s || P[i].Y < mxy - s) Q[3].push_back(P[i]);
  }

  if (
    check(Q[0], s, cnt-1) ||
    check(Q[1], s, cnt-1) ||
    check(Q[2], s, cnt-1) ||
    check(Q[3], s, cnt-1)
  ) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  A.resize(N);
  for (int i=0; i<N; i++) cin >> A[i].X >> A[i].Y;
  
  int l = -1, r = 1e9;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(A, m, 3)) r = m;
    else l = m;
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
