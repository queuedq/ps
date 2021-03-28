#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
#define MAX_N 100005
int N, M, A[MAX_N], sqrtN;
int cnt[MAX_N], ofCnt[MAX_N], best = 0;
int ans[MAX_N];

struct Query {
  int l, r, index;
} Q[MAX_N];

bool moCmp(Query a, Query b) {
  if (a.l / sqrtN == b.l / sqrtN) {
    return a.r < b.r;
  } else {
    return a.l < b.l;
  }
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

void insert(int i) {
  ofCnt[cnt[i]]--;
  ofCnt[cnt[i] + 1]++;
  cnt[i]++;
  if (cnt[i] > best) best++;
}

void remove(int i) {
  ofCnt[cnt[i]]--;
  ofCnt[cnt[i] - 1]++;
  cnt[i]--;
  if (ofCnt[best] == 0) best--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  int pl = 0, pr = 0;
  for (int i = 0; i < M; i++) {
    // cout << "Q: " << Q[i].l << " " << Q[i].r << endl;

    while (pr < Q[i].r) {
      insert(A[pr]);
      pr++;
    }
    while (pl > Q[i].l) {
      pl--;
      insert(A[pl]);
    }
    while (pr > Q[i].r) {
      pr--;
      remove(A[pr]);
    }
    while (pl < Q[i].l) {
      remove(A[pl]);
      pl++;
    }

    ans[Q[i].index] = best;
  }

  for (int i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
