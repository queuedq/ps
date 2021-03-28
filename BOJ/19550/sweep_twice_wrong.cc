#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// 틀린 풀이입니다. (https://www.acmicpc.net/board/view/54910)
// 반례 데이터:
// 6 7
// 0 2
// 0 4
// 1 6
// 3 1
// 3 5
// 4 6

////////////////////////////////////////////////////////////////
const int MAXN = 1e5;
int N, L;
pii A[MAXN*2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) {
    int s, e; cin >> s >> e;
    if (s > e) swap(s, e);
    if (e-s > L/2) { swap(s, e); s -= L; }
    A[i] = {e, s};
  }

  sort(A, A+N);
  for (int i=0; i<N; i++) {
    auto [e, s] = A[i];
    A[i+N] = {e+L, s+L};
  }

  int i = 0, j = 0;
  while (i < N) {
    while (A[j].second <= A[i].first) j++;
    i = j;
  }
  i -= N; j -= N;

  int s = i, ans = 0;
  while (i < N) {
    ans++;
    while (A[j].second <= A[i].first) j++;
    i = j;
  }
  if (i - s < N) ans++;

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
