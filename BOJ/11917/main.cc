#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 50005;
const int INF = 1e9+5;
int N, M, S[MAXN], cnt, stop;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> S[i];
  cin >> M;

  set<int> num(S+1, S+N+1);
  cnt = num.size();
  auto it = num.lower_bound(cnt);
  if (it == num.end()) stop = INF;
  else stop = *it;

  if (M <= N) cout << S[M] << endl;
  else cout << min(M-N+cnt-1, stop) << endl;

  ////////////////////////////////
  return 0;
}
