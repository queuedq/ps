#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
////////////////////////////////
const int MK = 101010;
const int ST = 1<<17;
int M, N, K, D[MK], seg[ST*2];
pii A[MK];

void upd(int i, int v) {
  i += ST;
  seg[i] = max(seg[i], v);
  for (i/=2; i>0; i/=2) {
    seg[i] = max(seg[i*2], seg[i*2+1]);
  }
}

int qry(int l, int r) {
  int res = 0;
  for (l+=ST, r+=ST+1; l<r; l/=2, r/=2) {
    if (l&1) res = max(res, seg[l++]);
    if (r&1) res = max(res, seg[--r]);
  }
  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N >> K;
  for (int i=0; i<K; i++) {
    int x, y; cin >> x >> y;
    A[i] = {x, y};
  }
  sort(A, A+K);

  for (int i=0; i<K; i++) {
    D[i] = qry(A[i].second+1, ST-1) + 1;
    upd(A[i].second, D[i]);
  }
  
  cout << *max_element(D, D+K) << endl;

  ////////////////////////////////
  return 0;
}
