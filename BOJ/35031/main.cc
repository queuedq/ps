#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;

////////////////////////////////////////////////////////////////
const lld ML = 1e6+5;
lld N, L, K;
lld P[ML], psum[ML];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> L >> K;
  for (int i=0; i<K; i++) {
    int p; cin >> p;
    P[p-1] = 1;
  }
  for (int i=1; i<=L; i++) psum[i] = psum[i-1] + P[i-1];

  lld t = 0, cur = 0, speed = 1, repeats = 0;
  while (repeats < N) {
    // get jumps in range [cur, cur+speed)
    lld wraps = (cur+speed) / L;
    lld nxt = (cur+speed) % L;
    lld jumps = (psum[nxt] - psum[cur]) + psum[L] * wraps;

    // update
    t++;
    cur = nxt;
    speed += jumps;
    repeats += wraps;

    // cout << "cur = " << cur << " (rep " << repeats << ") at " << t << endl;
  }

  cout << t << endl;

  ////////////////////////////////
  return 0;
}
