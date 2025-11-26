#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int T, N;

struct Task {
  int id, time, priority;
  bool operator<(const Task &X) const {
    return pii(priority, -id) < pii(X.priority, -X.id);
  }
};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> T >> N;

  priority_queue<Task> pq;
  for (int i=0; i<N; i++) {
    int id, time, priority;
    cin >> id >> time >> priority;
    pq.push({id, time, priority});
  }

  for (int i=0; i<T; i++) {
    auto [id, time, priority] = pq.top(); pq.pop();
    cout << id << endl;
    time--;
    priority--; // instead of increasing other tasks' priorities
    if (time > 0) pq.push({id, time, priority});
  }

  ////////////////////////////////
  return 0;
}
