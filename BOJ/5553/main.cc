#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
const int ST = 1<<19;
int N;

struct Bacteria { lld a, b, i; };
vector<Bacteria> A;

struct Node {
  lld sum, cnt;
  Node operator +(Node &X) { return {sum + X.sum, cnt + X.cnt}; }
};
Node seg[ST*2];

void add(lld i, lld x) {
  seg[i+=ST] = (Node){x, 1};
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int query(int n, int nl, int nr, lld diff, lld b) {
  if (n >= ST) {
    auto [sum, cnt] = seg[n];
    return (cnt == 1 && diff + b - sum >= 0);
  }
  int m = (nl+nr)/2;
  auto [sum, cnt] = seg[n*2];
  if (diff + b*cnt - sum >= 0)
    return cnt + query(n*2+1, m+1, nr, diff + b*cnt - sum, b);
  else
    return query(n*2, nl, m, diff, b);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    lld a, b; cin >> a >> b;
    A.push_back({a, b, 0});
  }
  sort(all(A), [](auto X, auto Y) { return X.a < Y.a; }); // sort by a to index
  for (int i=0; i<N; i++) A[i].i = i;
  sort(all(A), [](auto X, auto Y) { return X.b > Y.b; }); // sort by b in decreasing ord

  int ans = 0;
  for (int i=0; i<N; i++) {
    auto [a, b, idx] = A[i];
    add(idx, a);
    ans = max(ans, query(0, 0, ST-1, 0, b));
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
