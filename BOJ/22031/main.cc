#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2505;

struct Interval {
  lld s, e, w;
  bool operator <(const Interval &I) const { return s < I.s; }
};

bool cmp(const Interval &I, const Interval &J) { return I.w > J.w; }

lld N, K, tot, D[MN*2];
Interval A[MN];
vector<lld> xs;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  xs.push_back(0);
  for (int i=0; i<N; i++) {
    cin >> A[i].s >> A[i].e >> A[i].w;
    xs.push_back(A[i].s);
    xs.push_back(A[i].e);
    tot += A[i].w;
  }
  sort(A, A+N);
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());

  // DP
  D[0] = 0;
  
  for (int i=1; i<xs.size(); i++) {
    priority_queue<Interval, vector<Interval>, decltype(&cmp)> pq(cmp);
    lld cost = 0;

    for (int j=i-1, k=N-1; j>=0; j--) {
      // make group with cuts at indices j and i (cut at index i = cut at xs[i]+eps)
      while (k >= 0 && A[k].s > xs[j]) {
        if (A[k].e <= xs[i]) {
          pq.push(A[k]);
          cost += A[k].w;
        }
        k--;
      }

      // make group size at most K
      while (pq.size() > K) {
        cost -= pq.top().w;
        pq.pop();
      }

      D[i] = max(D[i], D[j] + cost);
    }
  }

  cout << tot - D[xs.size() - 1] << endl;

  ////////////////////////////////
  return 0;
}
