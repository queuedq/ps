#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, A[MN];
lld ans;

struct Trie {
  Trie *l, *r;

  Trie* left() {
    if (l == nullptr) l = new Trie;
    return l;
  }

  Trie* right() {
    if (r == nullptr) r = new Trie;
    return r;
  }
};

void solve(Trie *trie, int n) {
  if (trie == nullptr) return;
  if (trie->r == nullptr) return solve(trie->l, n-1);
  if (trie->l == nullptr) return solve(trie->r, n-1);

  int w = 1;
  vector<pair<Trie*, Trie*>> nodes[30];
  nodes[0].push_back({trie->l, trie->r});

  for (int i=1; i<n; i++) {
    w *= 2;
    for (auto [u, v]: nodes[i-1]) {
      if (u->l && v->l) nodes[i].push_back({u->l, v->l});
      if (u->r && v->r) nodes[i].push_back({u->r, v->r});
    }
    if (!nodes[i].empty()) continue;
    
    w++;
    for (auto [u, v]: nodes[i-1]) {
      if (u->l && v->r) nodes[i].push_back({u->l, v->r});
      if (u->r && v->l) nodes[i].push_back({u->r, v->l});
    }
  }

  ans += w;

  solve(trie->l, n-1);
  solve(trie->r, n-1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  Trie *trie = new Trie;

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    Trie *t = trie;
    for (int d=29; d>=0; d--) {
      if (A[i] >> d & 1) t = t->right();
      else t = t->left();
    }
  }

  solve(trie, 30);
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
