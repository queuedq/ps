#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
////////////////////////////////////////////////////////////////
const int MX = 202020;
int N, L, cnt[MX];
string S;

struct Node { int i, lo, hi; };

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L >> S;

  // leftmost
  int x = 1;
  cnt[x]++;
  for (int i=0; i<L; i++) {
    x += (S[i] == 'L') ? -1 : 1;
    x = min(max(x, 1), N);
    cnt[x]++;
  }

  if (cnt[x] == 1 && 1 <= x && x <= N) {
    cout << "WIN" << endl;
    cout << 1 << " " << x << endl;
    return 0;
  }

  // rightmost
  fill_n(cnt, MX, 0);
  x = N;
  cnt[x]++;
  for (int i=0; i<L; i++) {
    x += (S[i] == 'L') ? -1 : 1;
    x = min(max(x, 1), N);
    cnt[x]++;
  }

  if (cnt[x] == 1 && 1 <= x && x <= N) {
    cout << "WIN" << endl;
    cout << N << " " << x << endl;
    return 0;
  }

  cout << "DEFEAT" << endl;

  ////////////////////////////////
  return 0;
}
