#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 3000;
int N, comb[MN];

int bit_cnt(int x) {
  int cnt = 0;
  for (; x; x >>= 1) cnt += x&1;
  return cnt;
}

char get_color(int i, int j) {
  int colors = comb[i] & ~comb[j];
  for (int i=0; i<14; i++) {
    if (colors & 1<<i) return 'a' + i;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;

  for (int i=0, x=0; i<N; x++) {
    if (bit_cnt(x) == 7) comb[i++] = x;
  }

  for (int i=1; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<i; j++) {
      if (S[j] == '1') cout << get_color(i, j);
      else cout << get_color(j, i);
    }
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
