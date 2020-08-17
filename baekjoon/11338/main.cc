#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int Q, K;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) {
    cin >> Q >> K;

    int sum = 0;
    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i=0; i<Q; i++) {
      string query; cin >> query;
      if (query == "insert") {
        int N; cin >> N;
        pq.push(N);
        sum ^= N;
      } else {
        while (pq.size() > K) {
          int N = pq.top(); pq.pop();
          sum ^= N;
        }
        cout << sum << endl;
      }
    }
  }

  ////////////////////////////////
  return 0;
}
