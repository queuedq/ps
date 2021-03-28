#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAX_N = 100'005;
int N, M, A[MAX_N];
vector<int> coords;

int compress(int x) {
  return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
}

struct Query {
  int q, i, j, k;
} Q[MAX_N];

class Fenwick {
public:
  map<pii, int> arr;

  int query(int i, int j) {
    i++; j++;
    int s = 0;
    while (i > 0) {
      int j1 = j;
      while (j1 > 0) {
        s += arr[{i, j1}];
        j1 -= j1 & -j1;
      }
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int j, int val) {
    i++; j++;
    while (i < MAX_N) {
      int j1 = j;
      while (j1 < MAX_N * 2) {
        arr[{i, j1}] += val;
        j1 += j1 & -j1;
      }
      i += i & -i;
    }
  }
} fenwick;

void input() {
  cin >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
    coords.push_back(A[i]);
  }

  cin >> M;
  for (int t = 0; t < M; t++) {
    int q, i, j = 0, k; cin >> q;
    if (q == 1) {
      cin >> i >> j >> k;
    } else {
      cin >> i >> k;
    }
    Q[t] = {q, i, j, k};
    coords.push_back(k);
  }

  sort(coords.begin(), coords.end());
  for (int i = 1; i <= N; i++) {
    A[i] = compress(A[i]);
  }
  for (int i = 0; i < M; i++) {
    Q[i].k = compress(Q[i].k);
  }
}

void calc() {
  for (int i = 1; i <= N; i++) {
    fenwick.add(i, A[i], 1);
  }

  for (int t = 0; t < M; t++) {
    if (Q[t].q == 1) {
      int ans = fenwick.query(Q[t].j, MAX_N * 2 - 1);
      ans -= fenwick.query(Q[t].i - 1, MAX_N * 2 - 1);
      ans -= fenwick.query(Q[t].j, Q[t].k);
      ans += fenwick.query(Q[t].i - 1, Q[t].k);
      cout << ans << endl;
    } else {
      fenwick.add(Q[t].i, A[Q[t].i], -1);
      fenwick.add(Q[t].i, Q[t].k, 1);
      A[Q[t].i] = Q[t].k;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  calc();

  ////////////////////////////////
  return 0;
}
