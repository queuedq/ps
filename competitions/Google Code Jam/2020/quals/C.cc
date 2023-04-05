#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1005;
int N;
struct Interval {
  int s, e, i;

  bool operator <(Interval t) const { return pii(s, e) < pii(t.s, t.e); }
} I[MAXN];

string calc() {
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> I[i].s >> I[i].e;
    I[i].i = i;
  }

  sort(I, I+N);

  int J = 0, C = 0;
  vector<char> ans(N);
  for (int i=0; i<N; i++) {
    if (I[i].s >= J) {
      ans[I[i].i] = 'J';
      J = I[i].e;
    } else if (I[i].s >= C) {
      ans[I[i].i] = 'C';
      C = I[i].e;
    } else {
      return "IMPOSSIBLE";
    }
  }

  return string(ans.begin(), ans.end());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int i=1; i<=T; i++) {
    cout << "Case #" << i << ": " << calc() << endl;
  }

  ////////////////////////////////
  return 0;
}
