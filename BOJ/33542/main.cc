#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
using namespace std;
using pii = pair<int, int>;

const int INF = 1e9;
int N, A, B;
vector<pii> L, R;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> A >> B >> N;
  for (int i=1; i<=N; i++) {
    int l, r; cin >> l >> r;
    L.push_back({l, i});
    R.push_back({r, i});
  }
  L.push_back({0, -1});
  R.push_back({0, -1});
  sort(all(L));
  sort(all(R));

  array<int, 3> ans = {INF, -1, -1};

  for (int i=0; i<sz(L); i++) {
    auto [l, li] = L[i];
    auto j = lower_bound(all(R), pii(A-B-l+1, -1)) - R.begin();
    if (j == sz(R)) continue;
    auto [r, ri] = R[j];

    if (li == -1 || li != ri) ans = min(ans, {l+r, li, ri});
    else if (j < sz(R)-1) {
      tie(r, ri) = R[j+1];
      ans = min(ans, {l+r, li, ri});
    }
  }

  if (ans[0] == INF) {
    cout << "No" << endl;
  } else {
    cout << ans[1] << " " << ans[2] << endl;
  }

  return 0;
}
