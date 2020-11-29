#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, h[MN], D[MN];
vector<lld> i1, i2;

lld dnco(int s, int e, int l, int r) {
  if (s > e) return 0;
  int mid = (s+e) / 2;
  lld opt = l, cost = 0;
  for (int i=l; i<=r; i++) {
    lld val = (h[i1[i]] + h[i2[mid]]) * (i2[mid] - i1[i]);
    if (val > cost) {
      opt = i;
      cost = val;
    }
  }
  return max({cost, dnco(s, mid-1, l, opt), dnco(mid+1, e, opt, r)});
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> h[i];
    if (i1.empty() || h[i1.back()] < h[i]) i1.push_back(i);
    while (!i2.empty() && h[i2.back()] <= h[i]) i2.pop_back();
    i2.push_back(i);
  }
  cout << dnco(0, i2.size()-1, 0, i1.size()-1) << endl;

  ////////////////////////////////
  return 0;
}
