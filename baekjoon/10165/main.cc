#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXM = 5e5+5;
int N, M;

struct Bus {
  lld l, r, i;

  bool operator <(Bus B) const {
    return l == B.l ? (r > B.r) : (l < B.l);
  }
};

vector<Bus> B;
bool excluded[MAXM];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    lld l, r; cin >> l >> r;
    if (r < l) r += N;
    B.push_back({l, r, i});
    B.push_back({l+N, r+N, i});
  }

  sort(B.begin(), B.end());

  lld maxr = 0;
  for (int i=0; i<B.size(); i++) {
    if (B[i].r <= maxr) excluded[B[i].i] = true;
    else maxr = B[i].r;
  }

  for (int i=0; i<M; i++) {
    if (!excluded[i]) cout << i+1 << endl;
  }

  ////////////////////////////////
  return 0;
}
