#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
pair<pii, int> P[1000];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<3*N; i++) {
    int x, y; cin >> x >> y;
    P[i] = {{x, y}, i+1};
  }

  sort(P, P+3*N);

  for (int i=0; i<3*N; i+=3) {
    cout << P[i].second << " " << P[i+1].second << " " << P[i+2].second << endl;
  }

  ////////////////////////////////
  return 0;
}
