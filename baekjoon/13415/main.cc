#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K, X[101010];
pii st[101010];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> X[i];

  cin >> K;
  int m = 0;
  for (int i=0; i<K; i++) {
    int A, B; cin >> A >> B;

    while (m>0 && st[m-1].first <= A) m--;
    if (m==0 || st[m-1].second != 0) st[m++] = {A, 0};

    while (m>0 && st[m-1].first <= B) m--;
    if (m==0 || st[m-1].second != 1) st[m++] = {B, 1};
  }
  st[m] = {0, 0};

  sort(X, X+st[0].first);
  deque<int> dq;
  for (int i=0; i<st[0].first; i++) dq.push_back(X[i]);

  int j = st[0].first-1;
  for (int i=0; i<m; i++) {
    while (j >= st[i+1].first) {
      if (st[i].second == 0) { X[j--] = dq.back(); dq.pop_back(); }
      else { X[j--] = dq.front(); dq.pop_front(); }
    }
  }

  for (int i=0; i<N; i++) cout << X[i] << " ";

  ////////////////////////////////
  return 0;
}
