#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a; cin >> a;
    A[a]++;
  }

  for (int i=0; i<MN; i++) {
    A[i+1] += A[i] / 2;
    A[i] %= 2;
  }

  int cnt = 0;
  for (int i=0; i<MN; i++) {
    if (A[i]) cnt++;
  }

  if (cnt > 2) cout << "N" << endl;
  else if (cnt == 2) cout << "Y" << endl;
  else if (cnt == 1 && N > 1) cout << "Y" << endl;
  else cout << "N" << endl;

  ////////////////////////////////
  return 0;
}
