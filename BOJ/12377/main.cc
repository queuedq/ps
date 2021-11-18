#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

random_device rd;
mt19937 rng(rd());
uniform_real_distribution<double> rnd(0, 1);

////////////////////////////////////////////////////////////////
const int MN = 1010;
double eps = 1e-3;
lld N, W, L, r[MN], idx[MN];
double cx[MN], cy[MN];

double dist(double x, double y) { return sqrt(x*x + y*y); }

bool collision(int i) {
  int a = idx[i];
  for (int j=0; j<i; j++) {
    int b = idx[j];
    if (dist(cx[a]-cx[b], cy[a]-cy[b]) < r[a]+r[b]+eps) return true;
  }
  return false;
}

void solve(int test) {
  cin >> N >> W >> L;
  for (int i=0; i<N; i++) cin >> r[i];
  iota(idx, idx+N, 0);
  sort(idx, idx+N, [&](int i, int j) { return r[i] > r[j]; });

  for (int i=0; i<N; i++) {
    while (true) {
      cx[idx[i]] = rnd(rng) * W;
      cy[idx[i]] = rnd(rng) * L;
      if (!collision(i)) break;
    }
  }

  cout << "Case #" << test << ": ";
  for (int i=0; i<N; i++) cout << cx[i] << " " << cy[i] << " ";
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  cout << fixed << setprecision(6);
  for (int t=1; t<=T; t++) solve(t);

  ////////////////////////////////
  return 0;
}
