#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 252525;
int N, h[2][MN];
int concave, match;
vector<int> xs;
vector<pii> S; // {h, i}
vector<pii> I; // {s, e}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> h[0][i] >> h[1][i];

  // get concave & vertical lines (xs)
  for (int i=2; i<=N; i++) {
    bool b0 = h[0][i-1] != h[0][i];
    bool b1 = h[1][i-1] != h[1][i];
    concave += b0;
    concave += b1;
    if (b0 && b1) xs.push_back(i-1);
  }

  // get horizontal lines (intervals)
  for (int d=0; d<2; d++) {
    auto H = h[d];
    S.clear();

    for (int i=1; i<=N; i++) {
      while (!S.empty() && S.back().first > H[i]) S.pop_back();
      if (!S.empty() && S.back().first == H[i]) {
        if (H[i-1] > H[i]) I.push_back({S.back().second, i-1});
        S.pop_back();
      }
      S.push_back({H[i], i});
    }
  }

  // matching
  sort(all(I));
  priority_queue<int, vector<int>, greater<int>> pq;
  int j = 0;

  for (auto x: xs) {
    while (j < sz(I) && I[j].first <= x) pq.push(I[j++].second);
    while (!pq.empty() && pq.top() < x) pq.pop();

    if (!pq.empty()) match++, pq.pop();
  }

  int ind = sz(xs) + sz(I) - match; // independent set
  cout << concave - ind << endl;

  ////////////////////////////////
  return 0;
}
