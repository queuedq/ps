#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;
using ldb = long double;

////////////////////////////////////////////////////////////////
const int MAXN = 50005;
int N;
vector<int> tree[MAXN];
bool prime[MAXN];

////////////////////////////////
// Centroid Decomposition

vector<int> centroidTree[MAXN];
int sub[MAXN];
bool dead[MAXN];

int getSize(int u, int p) {
  sub[u] = 1;
  for (auto v: tree[u]) {
    if (v == p || dead[v]) continue;
    sub[u] += getSize(v, u);
  }
  return sub[u];
}

int getCentroid(int u, int p, int n) {
  for (auto v : tree[u]) {
    if (v == p || dead[v]) continue;
    if (sub[v] > n/2) return getCentroid(v, u, n);
  }
  return u;
}

int centroidDecomp(int u) {
  int n = getSize(u, -1);
  int c = getCentroid(u, -1, n);
  dead[c] = true;
  for (auto v: tree[c]) {
    if (dead[v]) continue;
    auto a = centroidDecomp(v);
    centroidTree[c].push_back(a);
  }
  return c;
}

////////////////////////////////
// FFT

using cpx = complex<ldb>;
const ldb PI = acos(-1);

// source: https://blog.myungwoo.kr/54
// re-written by me (queued_q)
void fft(vector<cpx> &f, bool inv){
  int n = f.size(), j = 0; // j: bit reverse of i

  for (int i = 1; i < n; i++) { // permute to separate f_even and f_odd
    int bit = (n >> 1);
    for (; j >= bit; bit >>= 1) j -= bit;
    j += bit;
    if (i < j) swap(f[i], f[j]);
  }

  for (int s = 2; s <= n; s <<= 1) { // length of each interval
    ldb t = 2*PI / s * (inv ? -1 : 1);
    cpx ws(cos(t), sin(t)); // w ** s == 1
    for (int i = 0; i < n; i += s) { // start of each interval
      cpx w = 1;
      for (int j = 0; j < s/2; j++) { // merge
        cpx u = f[i+j], v = f[i+j + s/2] * w; // u: f_even, v: f_odd
        f[i+j] = u + v;
        f[i+j + s/2] = u - v;
        w *= ws;
      }
    }
  }

  if (inv) {
    for (int i = 0; i < n; i++) f[i] /= n;
  }
}

vector<cpx> multiply(vector<cpx> a, vector<cpx> b) {
  int n = 1;
  while (n < max(a.size(), b.size())) n <<= 1;
  n <<= 1;
  a.resize(n); b.resize(n);
  fft(a, false); fft(b, false);

  vector<cpx> c(n);
  for (int i = 0; i < n; i++) c[i] = a[i] * b[i];
  fft(c, true);
  return c;
}

lld cpxToInt(cpx z) { return (lld)round(z.real()); }

////////////////////////////////
// cpx array operations
void add(vector<cpx> &a, const vector<cpx> &b) {
  for (int i = 0; i < b.size(); i++) {
    if (i >= a.size()) a.push_back(b[i]);
    else a[i] += b[i];
  }
}

void subtract(vector<cpx> &a, const vector<cpx> &b) {
  for (int i = 0; i < b.size(); i++) {
    if (i >= a.size()) a.push_back(-b[i]);
    else a[i] -= b[i];
  }
}

////////////////////////////////
lld primeSum(const vector<cpx> &a) {
  lld sum = 0;
  for (int i = 0; i < a.size(); i++) {
    if (prime[i]) sum += cpxToInt(a[i]);
  }
  return sum;
}

void dfs(int u, int p, int depth, vector<cpx> &dist) {
  if (dist.size() < depth+1) dist.resize(depth+1);
  dist[depth] += 1;
  for (auto v: tree[u]) {
    if (v == p || dead[v]) continue;
    dfs(v, u, depth+1, dist);
  }
}

lld count(int u) {
  dead[u] = true;

  lld dp = 0, adj = 0;
  vector<cpx> P, Q;
  for (auto v: tree[u]) {
    if (dead[v]) continue;
    adj++;
    vector<cpx> R;
    dfs(v, u, 1, R);
    cout << v << " R: "; for (auto r: R) cout << cpxToInt(r) << " "; cout << endl;
    if (R.size() < 3) R.resize(3);
    dp += cpxToInt(R[2]) + primeSum(R);
    add(P, R);
    add(Q, multiply(R, R));
  }
  P = multiply(P, P);
  subtract(P, Q);
  lld dps = primeSum(P);
  lld d2s = adj * (adj - 1);

  cout << u << " d::::::: " << dps << " " << d2s << " " << dp << endl;
  cout << endl;
  lld ans = dps + d2s + 2*dp;

  for (auto v: centroidTree[u]) {
    ans += count(v);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  fill(prime, prime+MAXN, true);
  for (int i = 2; i < MAXN; i++) {
    if (!prime[i]) continue;
    for (int j = i*2; j < MAXN; j += i) {
      prime[j] = false;
    }
  }
  prime[0] = prime[1] = prime[2] = false;

  cin >> N;
  for (int i = 0; i < N-1; i++) {
    int u, v; cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  int centroid = centroidDecomp(1);

  fill(dead, dead+MAXN, false);
  cout << fixed << setprecision(20) << (ldb)count(centroid) / (N*(N-1)) << endl;

  ////////////////////////////////
  return 0;
}
