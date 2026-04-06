#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, K;
vector<int> ab, bc, ca;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    int a, b, c; cin >> a >> b >> c;
    ab.push_back(a+b);
    bc.push_back(b+c);
    ca.push_back(c+a);
  }
  sort(all(ab)); reverse(all(ab));
  sort(all(bc)); reverse(all(bc));
  sort(all(ca)); reverse(all(ca));

  int sum_ab = 0, sum_bc = 0, sum_ca = 0;
  for (int i=0; i<K; i++) sum_ab += ab[i];
  for (int i=0; i<K; i++) sum_bc += bc[i];
  for (int i=0; i<K; i++) sum_ca += ca[i];

  cout << max({sum_ab, sum_bc, sum_ca}) << endl;

  ////////////////////////////////
  return 0;
}
