#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
int N, M;
vector<int> sets[MN];
int vst[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=1; i<=M; i++) {
    vector<int> tmp(N+1);

    int k; cin >> k;
    for (int j=0; j<k; j++) {
      int x; cin >> x;
      tmp[x] = 1;
    }

    // complement set containing 1 (= arbitrary root)
    if (tmp[1]) {
      for (int x=1; x<=N; x++) tmp[x] ^= 1;
    }

    for (int x=1; x<=N; x++) {
      if (tmp[x]) sets[i].push_back(x);
    }
  }

  // large set first
  sort(sets+1, sets+M+1, [](auto &a, auto &b) {
    return a.size() > b.size();
  });

  // 1. set containment check
  vector<int> subtrees = {0}; // 0: entire tree
  for (int i=1; i<=M; i++) {
    // skip same set as parent
    int p = vst[sets[i][0]];
    if (sets[i] == sets[p]) continue;

    // check containment
    for (auto x: sets[i]) {
      if (vst[x] != p) { cout << 0 << endl; return 0; }
      vst[x] = i;
    }

    subtrees.push_back(i);
  }

  // 2. subtree root check:
  // each subtree must have at least one element not contained in its subtrees
  for (auto i: subtrees) {
    bool found = 0;
    for (int x=0; x<=N; x++) {
      if (vst[x] == i) { found = 1; break; }
    }
    if (!found) { cout << 0 << endl; return 0; }
  }

  cout << 1 << endl;

  ////////////////////////////////
  return 0;
}
