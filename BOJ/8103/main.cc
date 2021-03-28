#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 3005;
int N;
pair<pii, int> xint[MAXN], yint[MAXN];
int xidx[MAXN], yidx[MAXN];
pii coords[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) {
    int a, b, c, d; cin >> a >> b >> c >> d;
    xint[i] = {{a, c}, i};
    yint[i] = {{b, d}, i};
  }

  sort(xint+1, xint+N+1);
  sort(yint+1, yint+N+1);

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  int i = 1;
  for (int j=1; j<=N; j++) {
    while (i <= N && xint[i].first.first <= j) {
      pq.push({xint[i].first.second, xint[i].second});
      i++;
    }

    if (pq.empty() || pq.top().first < j) {
      cout << "NIE" << endl;
      return 0;
    }

    xidx[j] = pq.top().second; pq.pop();
  }

  assert(pq.empty());
  i = 1;
  for (int j=1; j<=N; j++) {
    while (i <= N && yint[i].first.first <= j) {
      pq.push({yint[i].first.second, yint[i].second});
      i++;
    }

    if (pq.empty() || pq.top().first < j) {
      cout << "NIE" << endl;
      return 0;
    }

    yidx[j] = pq.top().second; pq.pop();
  }

  for (int i=1; i<=N; i++) {
    coords[xidx[i]].first = i;
    coords[yidx[i]].second = i;
  }

  for (int i=1; i<=N; i++) {
    cout << coords[i].first << " " << coords[i].second << endl;
  }

  ////////////////////////////////
  return 0;
}
