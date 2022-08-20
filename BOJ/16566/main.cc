#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 4'000'005;
int N, M, K, par[MN];

int find(int x) {
  if (par[x] == x) return x;
  return par[x] = find(par[x]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<M; i++) {
    int a; cin >> a;
    par[a] = a;
  }
  int p = N+1;
  for (int i=N; i>=1; i--) {
    if (par[i] == i) p = i;
    else par[i] = p;
  }

  for (int i=0; i<K; i++) {
    int b; cin >> b;
    int a = find(b+1);
    cout << a << endl;
    par[a] = find(a+1);
  }

  ////////////////////////////////
  return 0;
}
