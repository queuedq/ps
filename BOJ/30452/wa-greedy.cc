#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1010;
lld N, K, A[MN][MN];

lld L[MN], R[MN], vst[MN], S[MN];
vector<lld> triple;

void solve(int i) {
  // init linked list
  for (int x=1; x<=N; x++) L[x] = x-1, R[x] = x+1, vst[x] = 0;
  L[0] = R[0] = R[N] = 0;
  vst[0] = 1;

  // init sums
  priority_queue<pll> pq;
  for (int x=1; x<=N-2; x++) {
    S[x] = A[i][x] + A[i][x+1] + A[i][x+2];
    pq.push({S[x], x});
  }

  // greedy
  while (!pq.empty()) {
    auto [sum, x] = pq.top(); pq.pop();

    // a, b, [x, y, z], c, d
    int a = L[L[x]], b = L[x];
    int y = R[x], z = R[R[x]];
    int c = R[z], d = R[R[z]];

    if (vst[x] || !y || !z) continue;
    if (sum != S[x]) continue;
    triple.push_back(sum);

    // remove x, y, z
    vst[y] = vst[z] = 1;
    if (b) R[b] = c;
    if (c) L[c] = b;

    // update a, b sums
    if (a && b && c) {
      S[a] = A[i][a] + A[i][b] + A[i][c];
      pq.push({S[a], a});
    }
    if (b && c && d) {
      S[b] = A[i][b] + A[i][c] + A[i][d];
      pq.push({S[b], b});
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    for (int j=1; j<=N; j++) cin >> A[i][j];
  }

  for (int i=1; i<=N; i++) solve(i);

  lld ans = 0;
  sort(triple.rbegin(), triple.rend());
  for (int i=0; i<min(K, (lld)sz(triple)); i++) ans += triple[i];
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
