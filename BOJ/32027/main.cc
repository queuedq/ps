#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5050;
int N;
char D[MN];
vector<int> L, R;
int lcnt[MN], rcnt[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;

  char td; // tallest's direction
  for (int i=1; i<=N; i++) {
    int h; cin >> h >> D[i]; 
    if (D[i] == 'L') L.push_back(h);
    else R.push_back(h);
    if (h == N) td = D[i];
  }

  sort(all(L));
  sort(all(R));

  int mx = 0, l = 0, r = 0;
  for (int i=1; i<=N; i++) {
    lcnt[i] = lcnt[i-1];
    if (D[i] == 'L') {
      while (l < sz(L) && L[l] < mx) l++;
      if (l < sz(L)) l++, lcnt[i]++;
    } else {
      mx = R[r++];
    }
  }

  mx = 0, l = 0, r = 0;
  for (int i=N; i>=1; i--) {
    rcnt[i] = rcnt[i+1];
    if (D[i] == 'R') {
      while (r < sz(R) && R[r] < mx) r++;
      if (r < sz(R)) r++, rcnt[i]++;
    } else {
      mx = L[l++];
    }
  }

  int ans = 0;
  for (int k=0; k<=N; k++) {
    if (D[k] == td) {
      if (td == 'L') ans = max(ans, lcnt[k] + rcnt[k+1]);
      else ans = max(ans, lcnt[k-1] + rcnt[k]);
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
