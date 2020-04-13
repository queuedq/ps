#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
vector<pii> P;
multiset<int> S;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int L, H, R; cin >> L >> H >> R;
    P.push_back({L, H});
    P.push_back({R, -H});
  }

  sort(P.begin(), P.end());

  int height = 0;
  for (int i=0; i<P.size(); i++) {
    if (P[i].second > 0) S.insert(P[i].second);
    else S.erase(S.lower_bound(-P[i].second));

    if (i+1 < P.size() && P[i+1].first == P[i].first) continue;

    int h = 0;
    if (!S.empty()) h = *S.rbegin();

    if (h != height) {
      height = h;
      cout << P[i].first << " " << height << " ";
    }
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
