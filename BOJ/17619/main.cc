#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, Q;
vector<pii> A, E;
vector<int> I;

bool cmp(pii a, pii b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=0; i<N; i++) {
    int x, y, _; cin >> x >> y >> _;
    A.push_back({x, y});
    E.push_back({x, 1});
    E.push_back({y, -1});
  }

  sort(E.begin(), E.end(), cmp);

  int cnt = 0;
  for (int i=0; i<E.size(); i++) {
    cnt += E[i].second;
    if (cnt == 0) I.push_back(E[i].first);
  }

  for (int i=0; i<Q; i++) {
    int a, b; cin >> a >> b;
    int i1 = lower_bound(I.begin(), I.end(), A[a-1].first) - I.begin();
    int i2 = lower_bound(I.begin(), I.end(), A[b-1].first) - I.begin();
    cout << (i1 == i2) << endl;
  }

  ////////////////////////////////
  return 0;
}
