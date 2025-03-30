#include <bits/stdc++.h>
#define endl "\n"
#define sz(x) (int(x.size()))
#define all(x) x.begin(), x.end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

struct Score {
  lld a, b;
  bool operator<(Score S) const { return a-b < S.a-S.b; } 
};

const int MN = 250250;
lld N, Q, A, B;
vector<Score> X;
lld psum[MN]; // A smaller -> psum of B in [0, i)
lld ssum[MN]; // B smaller -> ssum of A in [i, N)

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> N;
  for (int i=0; i<N; i++) {
    lld a, b; cin >> a >> b;
    X.push_back({a, b});
  }
  sort(all(X));

  for (int i=1; i<=N; i++) psum[i] = psum[i-1] + X[i-1].b;
  for (int i=N-1; i>=0; i--) ssum[i] = ssum[i+1] + X[i].a;

  cin >> Q;
  for (int q=0; q<Q; q++) {
    char c; int x; cin >> c >> x;
    if (c == 'A') A += x;
    else B += x;

    int i = lower_bound(all(X), Score{B, A}) - X.begin();

    lld tot = psum[i] + B*i + ssum[i] + A*(N-i);
    cout << tot << endl;
  }

  return 0;
}
