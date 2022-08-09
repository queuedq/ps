#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
map<int, int> lo, hi; // min/max of A[i] appearance time

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    if (lo.count(a)) lo[a] = min(lo[a], i);
    else lo[a] = i;
    if (hi.count(a)) hi[a] = max(hi[a], i);
    else hi[a] = i;
  }

  // each deque should contain down->up sequence
  int last = N, up = 0, cnt = 1;
  for (int x=-1000; x<=1000; x++) {
    if (lo.count(x) == 0) continue;
    if (up) {
      if (lo[x] > last) last = hi[x];
      else last = lo[x], up = !up, cnt++;
    } else {
      if (hi[x] < last) last = lo[x];
      else last = hi[x], up = !up;
    }
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
