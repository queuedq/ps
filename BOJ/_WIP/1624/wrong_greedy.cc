#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1005;
const int INF = 1e9;
int N;
vector<int> A, B;
unordered_map<int, int> L, R, cnt;

struct Deque {
  int l, r, lcnt, rcnt;

  bool push_left(int x) {
    if (x == l) {
      lcnt++;
      if (l == r) rcnt++;
      return true;
    }

    if (x == L[l] && (l == r || lcnt == cnt[l])) {
      l = x;
      lcnt = 1;
      return true;
    }

    return false;
  }

  bool push_right(int x) {
    if (x == r) {
      rcnt++;
      if (l == r) lcnt++;
      return true;
    }

    if (x == R[r] && (l == r || rcnt == cnt[r])) {
      r = x;
      rcnt = 1;
      return true;
    }

    return false;
  }
};

vector<Deque> dqs;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int x; cin >> x;
    A.push_back(x);
    B.push_back(x);
    cnt[x]++;
  }

  sort(B.begin(), B.end());
  B.erase(unique(B.begin(), B.end()), B.end());

  for (int i=0; i<B.size(); i++) {
    L[B[i]] = i > 0 ? B[i-1] : -INF;
    R[B[i]] = i < B.size()-1 ? B[i+1] : INF;
  }

  for (int i=0; i<N; i++) {
    bool pushed = false;
    for (auto dq: dqs) {
      if (pushed = dq.push_left(A[i])) break;
      if (pushed = dq.push_right(A[i])) break;
    }
    if (!pushed) dqs.push_back({A[i], A[i], 1, 1});
  }

  cout << dqs.size() << endl;

  ////////////////////////////////
  return 0;
}
