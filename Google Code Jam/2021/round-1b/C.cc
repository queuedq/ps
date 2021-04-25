#include <bits/stdc++.h>
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, B, P;
int cnt[25], p, q, r;

void place_high() {
  cout << p << endl;
  cnt[p]++;
  while (cnt[p] >= B) p++;
  while (cnt[q] >= B-1) q++;
  while (cnt[r] >= B-2) r++;
}

void place_low() {
  if (q > N) return place_high();
  cout << q << endl;
  cnt[q]++;
  while (cnt[q] >= B-1) q++;
  while (cnt[r] >= B-2) r++;
}

void place_lower() {
  if (r > N) return place_low();
  cout << r << endl;
  cnt[r]++;
  while (cnt[r] >= B-2) r++;
}

void solve() {
  fill(cnt, cnt+25, 0);
  p = 1; // leftmost < B tower
  q = 1; // leftmost < B-1 tower
  r = 1; // leftmost < B-2 tower

  for (int i=0; i<N*B; i++) {
    int D; cin >> D;

    if (D == 9) place_high();
    else if (D == 8) place_low();
    else place_lower();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T >> N >> B >> P;
  for (int t=1; t<=T; t++) {
    solve();
  }

  ////////////////////////////////
  return 0;
}
