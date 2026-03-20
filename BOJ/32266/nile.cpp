#include "nile.h"

#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld INF = 1e18;
const int MN = 101010;

struct Event {
  int t, d, i, j, q; // t=0 : update event, t=1 : query event
  bool operator<(const Event &E) const {
    return pii(d, t) < pii(E.d, E.t);
  }
};

struct Comp {
  int i, len;
  lld even, odd, jump; // min additional cost for each case
  lld cost; // real additional cost

  void update_cost() {
    if (len%2 == 0) cost = 0;
    else if (i%2 == 0) cost = min(even, jump);
    else cost = min(odd, jump);
  }

  void merge(Comp &C) {
    len += C.len;
    even = min(even, C.even);
    odd = min(odd, C.odd);
    jump = min(jump, C.jump);
    update_cost();
  }
};

int par[MN];
Comp comp[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

vector<int> reorder(vector<int> &arr, vector<int> &idx) {
  vector<int> res;
  for (auto i: idx) res.push_back(arr[i]);
  return res;
}

vector<lld> calculate_costs(vector<int> W, vector<int> A, vector<int> B,
                            vector<int> E) {
  int N = (int)W.size();
  int Q = (int)E.size();

  // sort
  vector<int> idx(N);
  for (int i=0; i<N; i++) idx[i] = i;
  sort(all(idx), [&](int a, int b) { return W[a] < W[b]; });
  W = reorder(W, idx);
  A = reorder(A, idx);
  B = reorder(B, idx);

  // get events
  vector<Event> evt;
  for (int i=0; i<N; i++) {
    if (i >= 1) evt.push_back({0, W[i] - W[i-1], i-1, i, -1});
    if (i >= 2) evt.push_back({0, W[i] - W[i-2], i-2, i, -1});
  }

  for (int q=0; q<Q; q++) {
    evt.push_back({1, E[q], -1, -1, q});
  }

  sort(all(evt));

  // initialize dsu and cost
  lld tot = 0;
  for (int i=0; i<N; i++) {
    tot += A[i];
    par[i] = i;
    comp[i] = {i, 1, INF, INF, INF, A[i] - B[i]};
    if (i%2 == 0) comp[i].even = A[i] - B[i];
    else comp[i].odd = A[i] - B[i];
  }

  // process events
  vector<lld> ans(Q);

  for (auto [t, d, i, j, q]: evt) {
    if (t == 0 && j-i == 1) { // union two chains
      i = find(i), j = find(j);

      tot -= comp[i].cost + comp[j].cost;
      par[j] = i;
      comp[i].merge(comp[j]);
      tot += comp[i].cost;

    } else if (t == 0 && j-i == 2) { // add jump to chain
      int k = i+1;
      i = find(i);

      tot -= comp[i].cost;
      comp[i].jump = min(comp[i].jump, (lld)A[k] - B[k]);
      comp[i].update_cost();
      tot += comp[i].cost;

    } else { // query
      ans[q] = tot;
    }
  }

  return ans;
}
