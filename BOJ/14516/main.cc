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
const int MC = 1010;
int N, K, A[MN], C[MN], base, cnt[MC];

int floor_d2(int x) { return x>0 ? x/2 : -((-x+1)/2); }

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  string S;
  cin >> N >> K >> S;
  for (int i=0; i<N; i++) A[i] = S[i] == '(' ? 1 : -1;
  for (int i=0; i<N; i++) {
    cin >> C[i];
    if (C[i] < 0) {
      base += C[i];
      C[i] *= -1, A[i] *= -1;
    }
  }

  if (N%2 == 1) { cout << base << endl; return 0; } // always impossible

  int sum = 0;
  for (int i=0; i<N; i++) {
    sum += A[i];
    if (A[i] == -1) cnt[C[i]]++;
  }

  int h = 0, ans = INT_MAX;
  for (int i=0;; i++) {
    int l = floor_d2(-h+1), r = floor_d2(sum-h+1);
    int target = max(K+1-l-r, 0);

    // get cost
    int cost = base;
    for (int c=0; c<MC && target>0; c++) {
      int n = min(cnt[c], target);
      cost += c * n;
      target -= n;
    }
    if (target == 0) ans = min(ans, cost);

    // update
    if (i == N) break;
    h += A[i];
    if (A[i] == 1) cnt[C[i]]++;
    if (A[i] == -1) cnt[C[i]]--;
  }

  if (ans == INT_MAX) cout << "?" << endl;
  else cout << ans << endl;

  ////////////////////////////////
  return 0;
}
