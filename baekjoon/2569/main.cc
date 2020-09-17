#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
const int MAXW = 10005;
int N, A[MAXN], B[MAXN], vst[MAXN];
int id[MAXW];

void getCycle(int i, vector<int> &cycle) {
  if (vst[i]) return;
  vst[i] = true;
  cycle.push_back(A[i]);
  getCycle(id[A[i]], cycle);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(B, B+N);

  for (int i=0; i<N; i++) id[B[i]] = i;

  lld ans = 0;
  for (int i=0; i<N; i++) {
    vector<int> cycle;
    getCycle(i, cycle);
    int len = cycle.size();
    if (len <= 1) continue;

    sort(cycle.begin(), cycle.end());

    ans += min({
      cycle[0] * (len-1),
      cycle[0] * 2 + B[0] * (len+1)
    });
    for (int j=1; j<cycle.size(); j++) ans += cycle[j];
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
