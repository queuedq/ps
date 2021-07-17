#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
lld N, W;

struct Worker {
  lld S, Q, idx;
  bool operator <(const Worker &w) const { return Q < w.Q; }
};
Worker A[505050];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> W;
  for (int i=0; i<N; i++) {
    lld S, Q; cin >> S >> Q;
    A[i] = {S, Q, i+1};
  }
  sort(A, A+N, [](const Worker &x, const Worker &y) {
    if (x.S * y.Q == y.S * x.Q) return x.S < y.S;
    return x.S * y.Q < y.S * x.Q;
  });

  lld sum = 0, max_size = 0, ans_idx = 0;
  double min_cost = INFINITY;
  priority_queue<Worker> pq;

  for (int i=0; i<N; i++) {
    pq.push(A[i]);
    sum += A[i].Q;
    while (!pq.empty() && sum * A[i].S > W * A[i].Q) { // sum * k > W
      sum -= pq.top().Q;
      pq.pop();
    }

    double cost = (double)sum * A[i].S / A[i].Q;
    if (pq.size() > max_size || (pq.size() == max_size && cost < min_cost)) {
      ans_idx = i;
      max_size = pq.size();
      min_cost = cost;
    }
  }

  vector<Worker> workers;
  sum = 0;
  while (!pq.empty()) pq.pop();

  for (int i=0; i<=ans_idx; i++) {
    pq.push(A[i]);
    sum += A[i].Q;
    while (!pq.empty() && sum * A[i].S > W * A[i].Q) { // sum * k > W
      sum -= pq.top().Q;
      pq.pop();
    }
  }

  cout << max_size << endl;
  while (!pq.empty()) {
    cout << pq.top().idx << endl;
    pq.pop();
  }

  ////////////////////////////////
  return 0;
}
