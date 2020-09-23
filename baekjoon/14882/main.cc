#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const lld MOD = 786433;

vector<lld> fft(vector<lld> &f, vector<lld> &x) {
  int n = f.size(), m = x.size();
  if (n == 1) {
    vector<lld> ff(m, f[0]);
    return ff;
  }

  vector<lld> e, o, x2;
  for (int i=0; i<n; i+=2) {
    e.push_back(f[i]);
    o.push_back(f[i+1]);
  }

  for (int i=0; i<m; i++) x2.push_back(x[i]*x[i] % MOD);
  sort(x2.begin(), x2.end());
  x2.resize(unique(x2.begin(), x2.end()) - x2.begin());

  const vector<lld> &fe = fft(e, x2);
  const vector<lld> &fo = fft(o, x2);

  vector<lld> ff(m);
  for (int i=0; i<m; i++) {
    int j = lower_bound(x2.begin(), x2.end(), x[i]*x[i] % MOD) - x2.begin();
    ff[i] = (fe[j] + x[i]*fo[j]) % MOD;
  }

  return ff;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  lld N; cin >> N;
  vector<lld> f(1<<18);
  for (int i=0; i<=N; i++) cin >> f[i];

  lld K; cin >> K;
  vector<lld> x(K);
  for (int i=0; i<K; i++) cin >> x[i];

  const vector<lld> &ff = fft(f, x);

  for (int i=0; i<K; i++) cout << ff[i] << endl;

  ////////////////////////////////
  return 0;
}
