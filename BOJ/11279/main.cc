#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
priority_queue<int> pq;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x; cin >> x;

    if (x != 0) {
      pq.push(x);
    } else if (!pq.empty()) {
      cout << pq.top() << endl;
      pq.pop();
    } else {
      cout << 0 << endl;
    }
  }

  ////////////////////////////////
  return 0;
}
