#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const lld INF = 1e9;

int N;
vector<pll> V;
vector<lld> X;
int S[MN][2], p;

int findx(int x) {
  return upper_bound(X.begin(), X.end(), x) - X.begin();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    V.emplace_back(a, b);
    X.push_back(a);
  }


  memset(S, -1, sizeof(S));
  sort(V.begin(), V.end());
  sort(X.begin(), X.end());
  X.erase(unique(X.begin(), X.end()), X.end());

  for (int i = 0; i < N; i++) {
    auto [a, b] = V[i];
    int x = findx(a);
    
  }

  ////////////////////////////////
  return 0;
}
