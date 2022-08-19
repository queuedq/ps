#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<18;
const int MQ = 1e6+5;
int N, Q, A[ST], idx[ST], nxt[ST], seg[ST*2], ans[MQ];
vector<int> st;

struct Query {
  int t, pos, idx;
  bool operator <(const Query &Q) const { return t < Q.t; }
} qry[MQ];

void update(int i, int x) {
  seg[i+=ST] = x;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

pii search(int n, int s) {
  if (n >= ST) return {n-ST, s};
  if (seg[n*2] <= s) return search(n*2+1, s-seg[n*2]);
  return search(n*2, s);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> Q;
  for (int i=1; i<=N; i++) {
    cin >> A[i];
    idx[A[i]] = i;
    while (sz(st) && A[st.back()] < A[i]) { nxt[st.back()] = i; st.pop_back(); }
    st.push_back(i);
  }
  while (sz(st)) { nxt[st.back()] = N+1; st.pop_back(); }

  // sort queries
  for (int i=0; i<Q; i++) {
    int t, pos; cin >> t >> pos;
    qry[i] = {t, pos, i};
  }
  sort(qry, qry+Q);

  // init chunks
  for (int i=1; i<=N; i=nxt[i]) update(A[i], nxt[i]-i);

  int q = 0;
  for (int t=0; t<=N; t++) {
    // answer queries
    while (q<Q && qry[q].t == t) {
      auto [a, s] = search(1, qry[q].pos-1);
      ans[qry[q].idx] = A[idx[a]+s];
      q++;
    }

    // shuffle
    auto [a, s] = search(1, N/2); // split middle chunk
    int ed = idx[a]+seg[a+ST];
    if (s == 0) break;
    update(a, s);
    for (int j=idx[a]+s; j<ed && seg[A[j]+ST]==0; j=nxt[j]) {
      update(A[j], min(nxt[j], ed) - j); // new chunks
    }
  }

  while (q<Q) {
    auto [a, s] = search(1, qry[q].pos-1);
    ans[qry[q].idx] = A[idx[a]+s];
    q++;
  }

  for (int i=0; i<Q; i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
