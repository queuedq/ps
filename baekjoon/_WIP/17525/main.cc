#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
char alpha[21];
vector<int> ans;

void enumerate(int n, int k, int p, int s, int e) {
  if (k == 0) return;
  if (k == 1) {
    ans.push_back(p + s);
    for (int i=0; i<n; i++) {
      if (!(s>>i & 1) && !(e>>i & 1)) ans.push_back(p + (1<<i));
    }
    ans.push_back(p + e);
  }
  int l = s>>k-1 & 1, r = e>>k-1 & 1;
  if (l && r) { }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int n, k, s=0, e=0;
  string a, b;
  cin >> n >> k >> alpha >> a >> b;

  for (int i=0; i<k; i++) {
    s += 1 << find(alpha, alpha+n, a[i]) - alpha;
    e += 1 << find(alpha, alpha+n, b[i]) - alpha;
  }

  enumerate(n, k, 0, s, e);

  ////////////////////////////////
  return 0;
}
