#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 300;
const int MAXA = 100'005;
int N, tot;
pii A[MAXN];
int D[MAXA], E[MAXA];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A[i] = {a, i+1};
    tot += a;
  }

  sort(A, A+N);
  reverse(A, A+N);

  fill(D, D+tot+1, -1);
  D[0] = 0;

  for (int i=0; i<N; i++) {
    for (int j=tot; j>=0; j--) {
      auto [a, num] = A[i];
      if (0 <= j-a && j-a <= tot/2 && D[j] == -1 && D[j-a] >= 0) {
        D[j] = j-a;
        E[j] = num;
      }
    }
  }

  int cnt;
  for (int i=tot; i>=0; i--) {
    if (D[i] >= 0) { cnt = i; break; }
  }

  vector<int> ans;
  for (; cnt > 0; cnt = D[cnt]) {
    ans.push_back(E[cnt]);
  }

  cout << ans.size() << endl;
  for (auto num: ans) cout << num << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
