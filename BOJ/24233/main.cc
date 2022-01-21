#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N;

struct Frac {
  lld a, b; // a / b
  Frac (lld a, lld b): a(b >= 0 ? a : -a), b(b >= 0 ? b : -b) {}
  Frac (lld a): a(a), b(1) {}
  bool operator <(const Frac &F) const { return a * F.b < F.a * b; }
};
const Frac INF = Frac(1, 0);

struct Band {
  lld s, e, v;

  // time interval where s + vt intersects B
  pair<Frac, Frac> itv(Band B) {
    if (v == B.v) {
      if (B.s <= s && s <= B.e) return {Frac(-1), INF};
      else return {Frac(-1), Frac(-1)};
    }
    auto S = Frac(B.s - s, v - B.v);
    auto E = Frac(B.e - s, v - B.v);
    if (E < S) swap(S, E);
    return {S, E};
  }
};
vector<Band> B;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld S, E, V; cin >> S >> E >> V;
    B.push_back({S, E, V});
  }

  lld ans = 0;

  for (auto b0: B) {    
    vector<pair<Frac, bool>> E;
    for (auto b1: B) {
      auto [s, e] = b0.itv(b1);
      E.push_back({s, 0});
      E.push_back({e, 1});
    }
    sort(E.begin(), E.end());

    lld cnt = 0;
    for (auto [x, end]: E) {
      if (!(x < Frac(0))) ans = max(ans, cnt);
      cnt += end ? -1 : 1;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
