#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////

struct DoublePriorityQueue {
  priority_queue<int> pq_max;
  priority_queue<int, vector<int>, greater<int>> pq_min;
  unordered_map<int, int> cnt;
  int total = 0;

  void insert(int x) {
    pq_max.push(x);
    pq_min.push(x);
    cnt[x]++;
    total++;
  }

  void clean_removed() {
    while (!pq_max.empty() && cnt[pq_max.top()] == 0) pq_max.pop();
    while (!pq_min.empty() && cnt[pq_min.top()] == 0) pq_min.pop();
  }

  int get_max() {
    clean_removed();
    assert(total > 0);
    return pq_max.top();
  }

  int get_min() {
    clean_removed();
    assert(total > 0);
    return pq_min.top();
  }

  void pop_max() {
    clean_removed();
    if (total == 0) return;
    int x = pq_max.top();
    pq_max.pop();
    cnt[x]--;
    total--;
  }

  void pop_min() {
    clean_removed();
    if (total == 0) return;
    int x = pq_min.top();
    pq_min.pop();
    cnt[x]--;
    total--;
  }
};

void solve() {
  int K; cin >> K;
  DoublePriorityQueue pq;

  for (int q=0; q<K; q++) {
    char cmd; int x;
    cin >> cmd >> x;

    if (cmd == 'I') {
      pq.insert(x);
    } else {
      if (x == 1) pq.pop_max();
      else pq.pop_min();
    }
  }

  if (pq.total == 0) cout << "EMPTY" << endl;
  else cout << pq.get_max() << " " << pq.get_min() << endl;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) solve();

  ////////////////////////////////
  return 0;
}
