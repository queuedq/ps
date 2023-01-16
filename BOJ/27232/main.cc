#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 505050;
lld N, K, A[MN], dist, ans;
set<pii> S;

void add(int a, int p) {
  auto [it, _] = S.insert({a, p});
  auto pt = prev(it), nt = next(it);
  dist -= abs(pt->second - nt->second);
  dist += abs(p - pt->second);
  dist += abs(p - nt->second);
}

void del(int a, int p) {
  auto it = S.find({a, p});
  auto pt = prev(it), nt = next(it);
  dist -= abs(p - pt->second);
  dist -= abs(p - nt->second);
  dist += abs(pt->second - nt->second);
  S.erase(it);
}

lld get_dist() {
  lld res = dist;
  res -= next(S.begin())->second;
  res -= prev(prev(S.end()))->second;
  return res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> A[i];

  S.insert({0, 0});
  S.insert({INT_MAX, 0});

  ans = LLONG_MAX;

  for (int i=0; i<K; i++) add(A[i], i);
  ans = min(ans, get_dist());

  for (int i=K; i<N; i++) {
    add(A[i], i);
    del(A[i-K], i-K);
    ans = min(ans, get_dist());
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
