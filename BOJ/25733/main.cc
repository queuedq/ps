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
int N, A[MN], vst[MN];
vector<int> pos;

bool solve(int k, int st) { // k: idx of unfilled pos, st: check num in (st, N]
  if (k == sz(pos)) return 1;
  int i = pos[k];
  
  int nxt = -1; // next unused num
  for (int x=st; x<=N; x++) {
    if (vst[x]) continue;
    if (nxt == -1) nxt = x;
    if (abs(x - A[i-1]) == 1 || abs(x - A[i+1]) == 1) continue;

    A[i] = x, vst[x] = 1;
    if (solve(k+1, nxt)) return 1;
    A[i] = -1, vst[x] = 0;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i];
  A[0] = A[N+1] = -2;

  for (int i=1; i<=N; i++) {
    if (A[i] == -1) pos.push_back(i);
    else vst[A[i]] = 1;
  }

  if (solve(0, 1)) {
    for (int i=1; i<=N; i++) cout << A[i] << " ";
  } else {
    cout << -1 << endl;
  }

  ////////////////////////////////
  return 0;
}
