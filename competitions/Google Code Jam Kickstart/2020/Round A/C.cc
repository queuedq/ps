#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, K, M[MAXN], cnt[MAXN];

void calc(int test) {
  cin >> N >> K;
  for (int i=0; i<N; i++) cin >> M[i];

  priority_queue<pair<double, int>> pq;
  for (int i=0; i<N-1; i++) {
    pq.push({M[i+1] - M[i], i});
    cnt[i] = 1;
  }

  for (int i=0; i<K; i++) {
    int j = pq.top().second; pq.pop();
    cnt[j]++;
    pq.push({(double)(M[j+1] - M[j]) / cnt[j], j});
  }

  int diff = ceil(pq.top().first);
  cout << "Case #" << test << ": " << diff << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    calc(t);
  }

  ////////////////////////////////
  return 0;
}
