#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int n, c;

struct App { int i, s, e; } A[505];
bool cmp_extra(App x, App y) { return x.e > y.e; }
bool cmp_storage(App x, App y) { return x.s < y.s; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> n >> c;
  for (int i=0; i<n; i++) {
    int d, s; cin >> d >> s;
    A[i] = {i+1, s, max(d, s) - s};
  }

  sort(A, A+n, cmp_extra);

  priority_queue<App, vector<App>, decltype(&cmp_storage)> pq(cmp_storage);
  int tot = 0;
  for (int i=0; i<n; i++) {
    pq.push(A[i]);
    tot += A[i].s;
    if (tot + A[i].e > c) {
      auto [i, s, e] = pq.top(); pq.pop();
      tot -= s;
    }
  }

  vector<App> used;
  for (; !pq.empty(); pq.pop()) used.push_back(pq.top());
  sort(used.begin(), used.end(), cmp_extra);

  cout << used.size() << endl;
  if (used.size() > 0) {
    for (auto a: used) cout << a.i << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
