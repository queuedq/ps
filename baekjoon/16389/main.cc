#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 2e5+5;
int N;
pii A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i].second >> A[i].first;
  sort(A, A+N);

  lld tot = 0;
  priority_queue<int> pq;
  for (int i=0; i<N; i++) {
    pq.push(A[i].second);
    tot += A[i].second;
    if (tot > A[i].first) {
      tot -= pq.top();
      pq.pop();
    }
  }

  cout << pq.size() << endl;

  ////////////////////////////////
  return 0;
}
