#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
////////////////////////////////
const int BKT = 320;

struct Query {
  int l, r, i;
  bool operator <(Query q) {
    if (l/BKT == q.l/BKT) return r < q.r;
    return l/BKT < q.l/BKT;
  }
} qry[MN];

const int MN = 101010;
int N, Q, A[MN], cnt[MN], cnt2[MN], mx[MN], res, ans[MN];

void add(int id) {
  cnt2[cnt[id]]--;
  cnt[id]++;
  cnt2[cnt[id]]++;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  vector<int> xs;
  for (int i=1; i<=N; i++) { cin >> A[i]; xs.push_back(A[i]); }
  for (int i=1; i<=Q; i++) { cin >> qry[i].l >> qry[i].r; qry[i] = i; }

  sort(xs.begin(), xs.end());
  xs.erase(unique(xs.begin(), xs.end()), xs.end());
  for (int i=1; i<=N; i++) A[i] = lower_bound(xs.begin(), xs.end(), A[i]) - xs.begin();
  sort(qry, qry+Q);

  int l = 1, r = 0;
  for (int i=0; i<Q; i++) {
    while (qry[i].l < l) {
      add(A[i]);
      l--;
    }
  }

  ////////////////////////////////
  return 0;
}
