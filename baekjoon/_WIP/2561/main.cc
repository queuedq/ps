#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 10005;
int N, A[MAXN];

bool find(vector<pii> itv, int revs) {
  if (revs == 0) return true;

  vector<int> jumps;
  for (int i=1; i<=N+1; i++) {
    if (abs(A[i] - A[i-1]) > 1) {
      jumps.push_back(i-1);
      jumps.push_back(i);
      jumps.push_back(i+1);
    }
  }

  if (jumps.size() > revs*2) return false;

  sort(jumps.begin(), jumps.end());
  jumps.resize(unique(jumps.begin(), jumps.end()) - jumps.begin());

  if (jumps.size() == 0) return;

  for (int i=0; i<D.size(); i++) {
    for (int i=0; i<D.size(); i++) {
      if (a == b) continue;

      reverse(A+a, A+b);

      bool ok = true;
      for (int i=1; i<=N; i++) {
        if (A[i] != i) ok = false;
      }

      find();

      reverse(A+a, A+b);
    }
  }

  assert(false);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  A[N+1] = N+1;

  auto ans = find();
  cout << ans[0] << " " << ans[1]-1 << endl;
  cout << ans[2] << " " << ans[3]-1 << endl;

  ////////////////////////////////
  return 0;
}
