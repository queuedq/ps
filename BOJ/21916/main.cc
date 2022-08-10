#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = LLONG_MAX;
int N;

struct Politician {
  lld m, p;
  bool operator <(const Politician &X) const { return m + p < X.m + X.p; }
} A[MN];

bool check(int k) {
  vector<lld> P(N, INF), M(N, -INF); // minimize p, maximize m
  priority_queue<lld> pq1;
  priority_queue<lld, vector<lld>, greater<lld>> pq2;
  
  for (lld i=0, sum=0; i<N; i++) {
    sum += A[i].p, pq1.push(A[i].p);
    if (sz(pq1) > k) sum -= pq1.top(), pq1.pop();
    if (sz(pq1) == k) P[i] = sum;
  }
  
  for (lld i=N-1, sum=0; i>=0; i--) {
    sum += A[i].m, pq2.push(A[i].m);
    if (sz(pq2) > k) sum -= pq2.top(), pq2.pop();
    if (sz(pq2) == k) M[i] = sum;
  }

  for (int i=0; i<N-1; i++) {
    if (P[i] <= M[i+1]) return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].m;
  for (int i=0; i<N; i++) cin >> A[i].p;
  sort(A, A+N);

  int l=0, r=N/2+1;
  while (l+1 < r) {
    int m = (l+r)/2;
    if (check(m)) l = m;
    else r = m;
  }

  cout << l << endl;

  ////////////////////////////////
  return 0;
}
