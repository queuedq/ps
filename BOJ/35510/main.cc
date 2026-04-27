#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 303030;
int N, bit[MN];

void add(int i, int x) {
  for (; i<MN; i+=i&-i) bit[i] += x;
}

int sum(int i) {
  int s = 0;
  for (; i>0; i-=i&-i) s += bit[i];
  return s;
}

void clear(int n) {
  for (int i=1; i<=n; i++) bit[i] = 0;
}

lld solve() {
  cin >> N;
  vector<pii> A;
  for (int i=1; i<=N; i++) {
    int a; cin >> a;
    A.push_back({a, i});
  }
  sort(all(A));
  reverse(all(A));

  clear(N);
  for (int i=1; i<=N; i++) add(i, 1);

  set<int> S;
  lld ans = 0;
  for (int i=N, j=0; i>=1; i--) {
    // people who can be at position i
    while (j < N && A[j].first >= i) S.insert(A[j].second), j++;
    if (S.empty()) return -1;

    // move last person
    int k = *S.rbegin();
    ans += i-sum(k);
    S.erase(k);
    add(k, -1);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  int T; cin >> T;
  while (T--) cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
