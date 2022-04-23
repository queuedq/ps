#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 50;
int N, sa[MN], ord[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> sa[i];
    ord[sa[i]] = i;
  }
  ord[N] = -1; // empty is earliest

  int cnt = 1;
  for (int i=0; i<N-1; i++) {
    if (ord[sa[i] + 1] > ord[sa[i+1] + 1]) cnt++;
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
