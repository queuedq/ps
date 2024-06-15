#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, subtask;
vector<int> P; // random permutation
vector<pii> G[2]; // (freq, group rep)

int query(int u, int v) {
  int bu = u > N, bv = v > N;
  cout << "? ";
  cout << (char)('A' + bu) << " " << (u - N*bu) << " ";
  cout << (char)('A' + bv) << " " << (v - N*bv) << endl;
  int ans; cin >> ans;
  return ans;
}

int main() {
  ////////////////////////////////

  cin >> N >> subtask;

  for (int u=1; u<=N*2; u++) {
    P.push_back(u);
    swap(P.back(), P[rand() % sz(P)]);
  }

  for (int i=0; i<N*2; i++) {
    int u = P[i], b = u > N;

    // same brand
    bool dup = 0;
    for (auto &[cnt, v]: G[b]) {
      if (query(u, v)) { dup = 1; cnt++; break; }
    }

    if (dup) { sort(G[b].rbegin(), G[b].rend()); continue; }
    else G[b].push_back({1, u});

    // different brand
    for (auto &[cnt, v]: G[!b]) {
      if (query(u, v)) { cout << "! 1" << endl; return 0; }
    }

  }

  cout << "! 0" << endl;

  ////////////////////////////////
  return 0;
}
