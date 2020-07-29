#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int M, N;

void solve2() {
  vector<pii> A(N);
  for (int i=0; i<N; i++) cin >> A[i].first;
  for (int i=0; i<N; i++) cin >> A[i].second;
  sort(A.begin(), A.end());

  vector<int> S;
  for (int i=0; i<N; i++) {
    auto it = lower_bound(S.begin(), S.end(), A[i].second);
    if (it == S.end()) S.push_back(A[i].second);
    else *it = A[i].second;
  }

  cout << S.size() << endl;
}

////////////////////////////////

void solve3() {
  vector<pair<int, pii>> A;
  A.resize(N);
  for (int i=0; i<N; i++) cin >> A[i].first;
  for (int i=0; i<N; i++) cin >> A[i].second.first;
  for (int i=0; i<N; i++) cin >> A[i].second.second;
  sort(A.begin(), A.end());

  vector<set<pii>> S;
  for (int i=0; i<N; i++) {
    auto [x, y] = A[i].second;

    int l = -1, r = S.size();
    while (l+1 < r) {
      int mid = (l+r)/2;
      auto it = S[mid].lower_bound({x, y});
      if (it == S[mid].begin() || prev(it)->second > y) r = mid;
      else l = mid;
    }

    if (r < S.size()) {
      auto it = S[r].lower_bound({x, y});
      if (it != S[r].begin() && prev(it)->second < y) continue;

      while (it != S[r].end() && it->second > y) {
        it++; // Avoid iterator invalidation
        S[r].erase(prev(it));
      }
    } else {
      S.push_back(set<pii>());
    }

    S[r].insert({x, y});
  }

  cout << S.size() << endl;
  // for (int i=0; i<S.size(); i++) {
  //   for (auto [x, y]: S[i]) cout << x << " " << y << " | ";
  //   cout << endl;
  // }
}

////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> M >> N;

  if (M == 2) solve2();
  else solve3();

  return 0;
}
