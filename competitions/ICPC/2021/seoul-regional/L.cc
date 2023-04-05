#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 2020;
int N;
string A[MN];

int color(string a, string b) {
  int c = 0;
  for (int i=0; i<4; i++) {
    if (a[i] == b[i]) c += 1<<i;
  }
  return c;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i];
  }

  for (int i=0; i<N; i++) {
    int cnt = 0;
    for (int j=0; j<N-1; j++) {
      if (i == j) continue;
      color(A[i], A[j])
    }
  }



  ////////////////////////////////
  return 0;
}
