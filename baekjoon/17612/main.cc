#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, k, w[MAXN];
lld id[MAXN];

struct Customer {
  int time, counter; lld id;

  bool operator <(const Customer &x) const {
    return tie(time, counter, id) < tie(x.time, x.counter, x.id);
  }
  bool operator >(const Customer &x) const {
    return x < *this;
  }
};

priority_queue<Customer, vector<Customer>, greater<Customer>> pq;
set<Customer> out;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> k;
  for (int i=0; i<N; i++) cin >> id[i] >> w[i];

  for (int i=0; i<N; i++) {
    if (pq.size() < k) {
      int c = pq.size();
      pq.push({w[i], c, id[i]});
    } else {
      auto [t, c, r] = pq.top();
      pq.pop();
      out.insert({t, -c, r});
      pq.push({t+w[i], c, id[i]});
    }
  }

  while (!pq.empty()) {
    auto [t, c, r] = pq.top();
    pq.pop();
    out.insert({t, -c, r});
  }

  lld mul=1, ans=0;
  for (auto [t, c, r]: out) {
    ans += r * mul++;
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
