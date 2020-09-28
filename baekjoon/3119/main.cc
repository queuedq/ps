#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N;

struct Plank {
  int l, r, h, i;
  bool operator <(const Plank &p) const { return l < p.l; }
} A[MAXN];

bool cmp(const Plank &a, const Plank &b) { return pii(a.h, a.r) < pii(b.h, b.r); }

vector<int> xs;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    int X, W, H; cin >> X >> W >> H;
    A[i] = {X, X+W, H, i+1};
    xs.push_back(X);
    xs.push_back(X+W);
  }

  sort(A, A+N);
  sort(xs.begin(), xs.end());

  priority_queue<Plank, vector<Plank>, decltype(&cmp)> pq(cmp);
  unordered_map<int, int> covered;
  vector<int> ans;

  int j = 0;
  for (int i=0; i<xs.size(); i++) {
    int x = xs[i];

    // Insert planks
    while (j<N && A[j].l == x) pq.push(A[j++]);

    // Remove planks
    while (!pq.empty()) {
      if (pq.top().r > x) break;
      pq.pop();
    }

    int h = pq.empty() ? 0 : pq.top().h;

    if (covered[h] <= x) {
      if (pq.empty()) continue;
      Plank P = pq.top();
      ans.push_back(P.i);
      covered[h] = P.r;
    }
  }

  sort(ans.begin(), ans.end());
  cout << ans.size() << endl;
  for (auto a: ans) cout << a << " ";
  cout << endl;

  ////////////////////////////////
  return 0;
}
