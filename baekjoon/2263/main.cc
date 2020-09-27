#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
int N, post[MAXN], in[MAXN], rin[MAXN];

void solve(int pl, int pr, int il, int ir) {
  if (pr-pl < 0) return;
  int i = rin[post[pr]];
  cout << post[pr] << " ";
  solve(pl, pl+(i-il)-1, il, i-1);
  solve(pl+(i-il), pr-1, i+1, ir);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> in[i];
    rin[in[i]] = i;
  }
  for (int i=0; i<N; i++) cin >> post[i];
  solve(0, N-1, 0, N-1);
  cout << endl;

  ////////////////////////////////
  return 0;
}
