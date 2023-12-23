#include <bits/stdc++.h>
#include <functional>
#include <queue>
#include <vector>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
vector<pii> I;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    int s, l; cin >> s >> l;
    I.push_back({s, s+l});
  }
  sort(all(I));

  priority_queue<int, vector<int>, greater<int>> pq;
  int cnt = 0;

  for (int i=0; i<N; i++) {
    while (!pq.empty() && pq.top() < I[i].first-M) pq.pop();
    if (!pq.empty() && pq.top() <= I[i].first) pq.pop(), cnt++;
    pq.push(I[i].second);
  }

  cout << cnt << endl;

  ////////////////////////////////
  return 0;
}
