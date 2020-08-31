#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e4+5;
int N, M;
vector<int> castle[2], tree[2], nexttree[2];
int D[MAXN][MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    char d; int x; cin >> d >> x;
    if (d == 'U') castle[0].push_back(x);
    else castle[1].push_back(x);
  }
  for (int i=0; i<M; i++) {
    char d; int x; cin >> d >> x;
    if (d == 'U') tree[0].push_back(x);
    else tree[1].push_back(x);
  }

  ////////////////////////////////
  return 0;
}
