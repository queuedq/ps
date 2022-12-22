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
int N, H[MN];

void unremove(int a) {
  // bubble up 1
  int i = a-1;
  while (i > 1) {
    swap(H[i], H[i/2]);
    i /= 2;
  }
  // insert a
  H[1] = a;
  H[a] = 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) unremove(i);
  for (int i=1; i<=N; i++) cout << H[i] << " ";

  ////////////////////////////////
  return 0;
}
