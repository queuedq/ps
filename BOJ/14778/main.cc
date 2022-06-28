#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 25005;
int N, B;
struct Cow { int a, b; };
vector<Cow> P, Q;

bool cmp1(Cow x, Cow y) { return x.a < y.a; }
bool cmp2(Cow x, Cow y) { return x.b > y.b; }

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int a, b; cin >> a >> b;
    if (a-b < 0) P.push_back({a, b});
    else Q.push_back({a, b});
    B += b;
  }
  sort(all(P), cmp1);
  sort(all(Q), cmp2);

  int ans = 0, psum = 0;
  for (auto [a, b]: P) {
    ans = max(ans, psum + a + B);
    psum += a-b;
  }
  for (auto [a, b]: Q) {
    ans = max(ans, psum + a + B);
    psum += a-b;
  }
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
