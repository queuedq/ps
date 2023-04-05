#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
////////////////////////////////
const int MN = 101010;
const int BKT = 350;

struct Query {
  int l, r, i;
  bool operator <(Query q) const {
    if (l/BKT == q.l/BKT) return r < q.r;
    return l/BKT < q.l/BKT;
  }
} qry[MN];

int N, Q, A[MN], cnt[MN], cnt2[MN], mx, inv[MN][BKT], ans[MN];

void add(int id) {
  cnt2[cnt[id]]--;
  inv[cnt[id]][id/BKT]--;
  cnt[id]++;
  cnt2[cnt[id]]++;
  inv[cnt[id]][id/BKT]++;
  mx = max(mx, cnt[id]);
}

void remove(int id) {
  if (cnt[id] == mx && cnt2[cnt[id]] == 1) mx--;
  cnt2[cnt[id]]--;
  inv[cnt[id]][id/BKT]--;
  cnt[id]--;
  cnt2[cnt[id]]++;
  inv[cnt[id]][id/BKT]++;
}

int get() {
  for (int i=BKT-1; i>=0; i--) {
    if (inv[mx][i] == 0) continue;
    for (int j=BKT-1; j>=0; j--) {
      int id = i*BKT + j;
      if (id < N && cnt[id] == mx) return id;
    }
  }
  return -1; // unreachable
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  vector<int> xs;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  for (int i=1; i<=Q; i++) { cin >> qry[i].l >> qry[i].r; qry[i].i = i; }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i=1; i<=N; i++) A[i] = lower_bound(xs.begin(), xs.end(), A[i]) - xs.begin();
  sort(qry+1, qry+Q+1);

  int l = 1, r = 0;
  for (int q=1; q<=Q; q++) {
    while (qry[q].l < l) add(A[--l]);
    while (qry[q].r > r) add(A[++r]);
    while (qry[q].l > l) remove(A[l++]);
    while (qry[q].r < r) remove(A[r--]);
    ans[qry[q].i] = get();
  }

  for (int i=1; i<=Q; i++) {
    cout << xs[ans[i]] << endl;
  }

  ////////////////////////////////
  return 0;
}
