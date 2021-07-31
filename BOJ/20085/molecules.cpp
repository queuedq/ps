#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

#include "molecules.h"

vector<int> find_subset(int l, int u, vector<int> w) {
  int N = w.size();

  vector<int> ord(N);
  iota(ord.begin(), ord.end(), 0);
  sort(ord.begin(), ord.end(), [&](int x, int y) { return w[x] < w[y]; });
  
  vector<lld> p(N+1);
  for (int i=1; i<=N; i++) p[i] = p[i-1] + w[ord[i-1]];

  int k = 1;
  for (; k<=N; k++) {
    lld mn = p[k];
    lld mx = p[N] - p[N-k];
    if (max(mn, (lld)l) <= min(mx, (lld)u)) break;
  }
  if (k == N+1) return vector<int>();

  for (int i=0; i<=k; i++) {
    lld sum = p[i] + p[N] - p[N-(k-i)];
    if (l <= sum && sum <= u) {
      vector<int> ans;
      for (int j=0; j<i; j++) ans.push_back(ord[j]);
      for (int j=N-(k-i); j<N; j++) ans.push_back(ord[j]);
      return ans;
    }
  }

  assert(false);
}
