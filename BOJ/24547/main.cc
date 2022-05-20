#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
const int B = 350;
lld N, Q, A[MN], cnt[MN], q1[B+1];

struct Fenwick {
  lld F[MN];

  void upd(int i, lld v) {
    for (; i<MN; i+=i&-i) F[i] += v;
  }

  lld qry(int i) {
    lld ret = 0;
    for (i=min(i, MN-1); i>0; i-=i&-i) ret += F[i];
    return ret;
  }
} F0, F1;

void add(lld a) {
  cnt[a]++;
  F0.upd(a, 1);
  F1.upd(a, a);
  for (lld x=1; x<=B; x++) q1[x] += a%x;
}

void del(lld a) {
  cnt[a]--;
  F0.upd(a, -1);
  F1.upd(a, -a);
  for (lld x=1; x<=B; x++) q1[x] -= a%x;
}

lld Q1(lld X) {
  if (X <= B) return q1[X];
  lld ret = 0;
  for (lld m=0; m<MN; m+=X) {
    ret += (F1.qry(m+X-1) - F1.qry(m-1)) - m * (F0.qry(m+X-1) - F0.qry(m-1));
  }
  return ret;
}

lld Q2(lld X) {
  lld i = 1, ret = X * (F0.qry(MN-1) - F0.qry(X));
  for (; i*i<X; i++) {
    ret += X * (F0.qry(X/i) - F0.qry(X/(i+1))) - (F1.qry(X/i) - F1.qry(X/(i+1))) * i;
  }
  for (i=X/i; i>0; i--) ret += (X%i) * cnt[i];
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) { cin >> A[i]; add(A[i]); }

  cin >> Q;
  for (int q=0; q<Q; q++) {
    int t, i, X; cin >> t;
    if (t == 1) {
      cin >> X;
      cout << Q1(X) << endl;
    } else if (t == 2) { 
      cin >> X;
      cout << Q2(X) << endl;
    } else {
      cin >> i >> X;
      del(A[i]);
      A[i] = X;
      add(A[i]);
    }
  }

  ////////////////////////////////
  return 0;
}
