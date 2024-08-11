#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
lld N, stone[MN], x[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> stone[i];
  for (int i=0; i<N; i++) cin >> x[i];

  int shift = -1;
  for (int i=0; i<N; i++) {
    if (stone[i]) { shift = i; break; }
  }
  if (shift == -1) { return cout << "0 0" << endl, 0; }

  rotate(stone, stone+shift, stone+N);
  rotate(x, x+shift, x+N);
  stone[N] = stone[0];

  lld score[3] = {};
  vector<lld> odd;
  for (int i=0; i<N; i++) {
    if (stone[i]) { score[stone[i]] += x[i]; continue; }

    int len = 0;
    while (!stone[i+len]) len++;
    int L = stone[i-1], R = stone[i+len];
    if (L == R) {
      for (int j=0; j<len; j++) score[L] += x[i+j];
    } else {
      for (int j=0; j<len/2; j++) score[L] += x[i+j], score[R] += x[i+len-j-1];
      if (len%2 == 1) odd.push_back(x[i+len/2]);
    }
    i += len-1;
  }

  sort(all(odd));
  reverse(all(odd));
  for (int i=0; i<sz(odd); i++) {
    if (i%2 == 0) score[1] += odd[i];
    else score[2] += odd[i];
  }
  cout << score[1] << " " << score[2] << endl;

  ////////////////////////////////
  return 0;
}
