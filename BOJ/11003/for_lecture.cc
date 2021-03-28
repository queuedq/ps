#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 5e6+5;
int N, L, A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> L;
  for (int i=0; i<N; i++) cin >> A[i];

  deque<pii> dq;
  for (int i=0; i<N; i++) {
    // A[i]보다 큰 최솟값 후보를 덱의 뒤에서 제거 후, A[i] 삽입
    while (!dq.empty() && dq.back().first >= A[i]) dq.pop_back();
    dq.push_back({A[i], i});

    // 덱의 왼쪽에서 구간에 벗어난 후보 제거
    while (dq.front().second <= i-L) dq.pop_front();

    // 최솟값 출력
    cout << dq.front().first << " ";
  }
  cout << endl;

  ////////////////////////////////
  return 0;
}
