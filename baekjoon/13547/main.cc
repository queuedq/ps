#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 100005;
const int MAX_A = 1000005;
int N, M, A[MAX_N], sqrtN;
int cnt[MAX_A], num = 0;
int ans[MAX_N];

struct Query {
  int l, r, idx;
} Q[MAX_N];

bool moCmp(Query a, Query b) {
  if (a.l / sqrtN == b.l / sqrtN) return a.r < b.r;
  else return a.l < b.l;
}

void input() {
  cin >> N;
  sqrtN = floor(sqrt(N));
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    Q[i] = {x - 1, y, i};
  }

  sort(Q, Q + M, moCmp);
}

void insert(int x) {
  if (cnt[x] == 0) num++;
  cnt[x]++;
}

void remove(int x) {
  cnt[x]--;
  if (cnt[x] == 0) num--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  int pl = 0, pr = 0;
  for (int i = 0; i < M; i++) {
    int l = Q[i].l, r = Q[i].r, idx = Q[i].idx;
    while (pr < r) { insert(A[pr]); pr++; }
    while (pl > l) { pl--; insert(A[pl]); }
    while (pr > r) { pr--; remove(A[pr]); }
    while (pl < l) { remove(A[pl]); pl++; }
    ans[idx] = num;
  }

  for (int i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
