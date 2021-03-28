#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int ST = 1<<17;
int N, K, seg[ST*2];

void upd(int i, int v) {
  i += ST;
  seg[i] = v;
  for (i/=2; i>0; i/=2) seg[i] = seg[i*2] + seg[i*2+1];
}

int qry(int l, int r) {
  int ret = 0;
  for (l+=ST, r+=ST; l<=r; l/=2, r/=2) {
    if (l&1) ret += seg[l++];
    if (~r&1) ret += seg[r--];
  }
  return ret;
}

int kth(int k) {
  int n = 1;
  while (n < ST) {
    if (seg[n*2] >= k) n = n*2;
    else { n = n*2+1; k -= seg[n-1]; }
  }
  return n - ST;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=1; i<=N; i++) upd(i, 1);

  int j = 0;
  vector<int> ans;
  for (int i=0; i<N; i++) {
    int s = qry(0, j);
    j = kth((s+K-1) % (N-i) + 1); 
    upd(j, 0);
    ans.push_back(j);
  }

  cout << "<";
  for (int i=0; i<N-1; i++) cout << ans[i] << ", ";
  cout << ans[N-1] << ">\n";

  ////////////////////////////////
  return 0;
}
