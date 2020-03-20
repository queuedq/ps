#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5 + 5;
int N, M, K, L[MAXN], R[MAXN], A[MAXN];
bool vst[MAXN];

void findCycle(int p, vector<int> &cycle) {
  if (vst[p]) return;
  vst[p] = true;
  for (int i=1; i<=M; i++) {
    if (p < L[i] || p > R[i]) continue;
    p = L[i] + R[i] - p;
  }
  cycle.push_back(p);
  findCycle(p, cycle);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=1; i<=M; i++) {
    cin >> L[i] >> R[i];
  }

  for (int i=1; i<=N; i++) {
    vector<int> cycle;
    findCycle(i, cycle);
    reverse(cycle.begin(), cycle.end());

    int t = cycle.size();
    for (int j=0; j<t; j++) {
      A[cycle[j]] = cycle[(j + K%t) % t];
    }
  }

  for (int i=1; i<=N; i++) {
    cout << A[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
