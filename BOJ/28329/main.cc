#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
int N, Q;

struct Node {
  // cnt: bigger count - smaller (or equal) count
  // pmin: prefix min of cnt / i: pmin idx
  // cost: abs sum / partial cost until i
  int cnt, pmin, i;
  lld cost, pcost;
};
Node seg[26][ST*2];

Node merge(Node X, Node Y) {
  int cnt = X.cnt + Y.cnt;
  lld cost = X.cost + Y.cost;
  if (X.pmin < X.cnt + Y.pmin) return {cnt, X.pmin, X.i, cost, X.pcost};
  else return {cnt, X.cnt + Y.pmin, Y.i, cost, X.cost + Y.pcost};
}

void update(int c, int i, int v) {
  int n = i+ST;
  if (v > c) seg[c][n] = {1, 0, i, v-c, 0};
  else seg[c][n] = {-1, -1, i+1, c-v, c-v};
  for (n/=2; n>0; n/=2) seg[c][n] = merge(seg[c][n*2], seg[c][n*2+1]);
}

Node query(int c, int l, int r) {
  Node L = {0, 0, l, 0, 0}, R = {0, 0, r, 0, 0};
  for (l+=ST, r+=ST; l<r; l/=2, r/=2) {
    if (l&1) L = merge(L, seg[c][l++]);
    if (r&1) R = merge(seg[c][--r], R);
  }
  return merge(L, R);
}

lld calc() { // greedy
  lld i = 0, ans = 0;
  for (int c=0; c<26; c++) {
    auto X = query(c, i, N);
    // jump to psum min (using c is optimal until there)
    ans += X.pcost;
    i = X.i;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S; cin >> S;
  N = sz(S);

  for (int i=0; i<N; i++) {
    for (int x=0; x<26; x++) update(x, i, S[i]-'a');
  }
  cout << calc() << endl;

  cin >> Q;
  for (int q=0; q<Q; q++) {
    int i; char c; cin >> i >> c; i--;
    for (int x=0; x<26; x++) update(x, i, c-'a');
    cout << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
