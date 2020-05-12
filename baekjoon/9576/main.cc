#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1000;
int N, M;
pii A[MAXN];

void calc() {
  cin >> N >> M;
  for (int i=0; i<M; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(A, A+M);

  priority_queue<int, vector<int>, greater<int>> pq;
  int j = 0, ans = 0;
  for (int i=1; i<=N; i++) {
    while (j < M && A[j].first <= i) {
      pq.push(A[j].second);
      j++;
    }

    while (!pq.empty() && pq.top() < i) pq.pop();

    if (!pq.empty()) {
      pq.pop();
      ans++;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    calc();
  }

  ////////////////////////////////
  return 0;
}
