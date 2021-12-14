#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, M, A[MN], tmp[MN], L[MN], cnt[MN], nice[MN], tot;
lld K;

void add(int c) {
  if (cnt[c] == L[c]) { nice[c]--; tot--; }
  cnt[c]++;
  if (cnt[c] == L[c]) { nice[c]++; tot++; }
}

void del(int c) {
  if (cnt[c] == L[c]) { nice[c]--; tot--; }
  cnt[c]--;
  if (cnt[c] == L[c]) { nice[c]++; tot++; }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) { cin >> tmp[i]; K += tmp[i]; }
  for (int i=0; i<M; i++) { int c; cin >> c; L[c] = tmp[i]; }
  for (int i=0; i<N; i++) cin >> A[i];

  if (K > N) { cout << 0 << endl; return 0; }
  tot = N-M;

  int i = 0, ans = 0;
  for (; i<K; i++) add(A[i]);
  for (; i<=N; i++) {
    if (tot == N) ans++;
    add(A[i]);
    del(A[i-K]);
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
