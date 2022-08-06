#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, F[MN];
char S[MN];

int query() {
  cout << S << endl;
  int cnt; cin >> cnt;
  if (cnt == N) exit(0);
  return cnt;
}

void flip(int i) { S[i] = '0'+'1'-S[i]; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  while (1) {
    for (int i=0; i<N; i++) S[i] = '0' + rand()%2;
    if (query()) break;
  }

  flip(0);
  for (int i=1; i<N; i++) {
    flip(i);
    F[i] = query();
    flip(i);
  }
  flip(0);

  for (int i=1; i<N; i++) if (F[i]) flip(i);
  query();
  for (int i=0; i<N; i++) flip(i);
  query();

  ////////////////////////////////
  return 0;
}
