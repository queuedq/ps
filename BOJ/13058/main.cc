#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
const int MK = 1e5+5;
const int MW = 305;
lld N, K, D[MW][MK];
vector<lld> A[MW];

void dnco(int s, int e, int l, int r, int w, int offset) {
  if (s > e) return;
  int m = (s+e)/2;
  int opt = l;
  for (int i=l; i<=min(m, r); i++) {
    int cnt = m-i;
    if (cnt > A[w].size()) continue;
    if (D[w][m*w + offset] < D[w-1][i*w + offset] + A[w][cnt]) {
      D[w][m*w + offset] = D[w-1][i*w + offset] + A[w][cnt];
      opt = i;
    }
  }
  dnco(s, m-1, l, opt, w, offset);
  dnco(m+1, e, opt, r, w, offset);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int w=1; w<=300; w++) A[w].push_back(0);
  for (int i=0, w, c; i<N; i++) { cin >> w >> c; A[w].push_back(c); }
  for (int w=1; w<=300; w++) {
    sort(A[w].rbegin(), A[w].rend()-1);
    for (int i=1; i<A[w].size(); i++) A[w][i] += A[w][i-1];
  }

  for (int w=1; w<=300; w++) {
    for (int i=0; i<w; i++) dnco(0, (K-i)/w, 0, (K-i)/w, w, i);
    for (int i=1; i<=K; i++) D[w][i] = max(D[w][i], D[w-1][i]);
  }

  for (int i=1; i<=K; i++) cout << D[300][i] << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
