#include <bits/stdc++.h>
#include <cmath>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
int N, H[MN];
double ans[MN];

struct Curve {
  // f(x) = sqrt(x-a) + b
  lld a, b;
  lld inter; // intersection with previous curve

  double eval(lld x) { return sqrt((double)(x - a)) + b; }
};

lld intersection(Curve F, Curve G) {
  // find the first point where F(x) <= G(x)
  lld l = G.a - 1, r = N + 2;
  while (l+1 < r) {
    lld m = (l+r)/2;
    if (F.eval(m) <= G.eval(m)) r = m;
    else l = m;
  }
  return r;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> H[i];

  // CHT forward
  deque<Curve> Q;
  for (int i=0; i<N; i++) {
    Curve C = {i, H[i], i};

    while (!Q.empty()) {
      C.inter = intersection(Q.back(), C);
      if (Q.back().inter < C.inter) break;
      Q.pop_back();
    }
    Q.push_back(C);

    while (sz(Q) >= 2 && Q[1].inter <= i) Q.pop_front();
    ans[i] = Q.front().eval(i);
  }

  // CHT backward
  Q.clear();
  for (int i=N-1; i>=0; i--) {
    Curve C = {-i, H[i], -i};

    while (!Q.empty()) {
      C.inter = intersection(Q.back(), C);
      if (Q.back().inter < C.inter) break;
      Q.pop_back();
    }
    Q.push_back(C);

    while (sz(Q) >= 2 && Q[1].inter <= -i) Q.pop_front();
    ans[i] = max(ans[i], Q.front().eval(-i));
  }

  // print ans
  for (int i=0; i<N; i++) {
    cout << (lld)ceil(ans[i]) - H[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
