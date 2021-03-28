#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MN = 1e5+5;
lld N, D, A[MN], E[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> D;
  for (int i=0; i<N; i++) cin >> A[i];

  deque<pll> dq;
  for (int i=0; i<N; i++) {
    // 구간 벗어난 최댓값 후보 삭제
    while (!dq.empty() && dq.front().second < i-D) dq.pop_front();

    // DP값 갱신
    E[i] = A[i];
    if (!dq.empty()) E[i] = max(E[i], dq.front().first + A[i]);

    // 새 최댓값 후보 삽입
    while (!dq.empty() && dq.back().first <= E[i]) dq.pop_back();
    dq.push_back({E[i], i});
  }

  cout << *max_element(E, E+N) << endl;

  ////////////////////////////////
  return 0;
}
