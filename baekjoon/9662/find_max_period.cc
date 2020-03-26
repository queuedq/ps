#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

template<class T>
ostream& operator << (ostream& os, vector<T> vec) {
  os << "{";
  if (vec.size() > 0) {
    copy(vec.begin(), vec.end() - 1, ostream_iterator<T>(os, ", "));
    os << *(vec.end() - 1);
  }
  os << "}";
  return os;
}

////////////////////////////////////////////////////////////////
int K, A[22], win[5'000'000], vst[5'000'000];
int P[10'000'000];

int calc(int rule) {
  int j = 0;
  for (int i=1; i<=22; i++) {
    if (rule & (1<<i)) A[j++] = i;
  }
  K = j;

  int B = A[K-1], hash = 0;
  assert(B <= 22);

  for (int i=0; i<B; i++) {
    win[i] = false;
    for (int j=0; j<K; j++) {
      if (i >= A[j] && !win[i-A[j]]) win[i] = true;
    }
    hash = (hash*2+win[i]) % (1<<B);
  }

  int period = 0, start = 0;

  for (int i=B; ; i++) {
    win[i] = false;
    for (int j=0; j<K; j++) {
      if (i >= A[j] && !win[i-A[j]]) win[i] = true;
    }
    hash = (hash*2+win[i]) % (1<<B);
    if (vst[hash]) {
      period = i-vst[hash];
      start = vst[hash];
      break;
    }
    vst[hash] = i;
  }

  P[rule] = period;

  // clean up
  hash = 0;
  for (int i = 0; i < start+period+1; i++) {
    hash = (hash*2+win[i]) % (1<<B);
    vst[hash] = 0;
    win[i] = 0;
  }

  return period;
}

vector<int> rule_vec(int rule) {
  vector<int> ret;
  for (int i=1; i<=22; i++) {
    if (rule & (1<<i)) ret.push_back(i);
  }
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int p = 0, rule = 0;
  for (int i=2; i<(2<<22); i+=2) {
    calc(i);
    if (p < P[i]) { p = P[i]; rule = i; }
    if (i % (2<<19) == 0) cout << "..." << rule_vec(i) << " / max: " << p << endl;
  }
  cout << "rule with max period: " << rule_vec(rule) << " / period: " << p << endl;

  ////////////////////////////////
  return 0;
}

// OUTPUT

// ...{20} / max: 314
// ...{21} / max: 314
// ...{20, 21} / max: 444
// ...{22} / max: 444
// ...{20, 22} / max: 494
// ...{21, 22} / max: 516
// ...{20, 21, 22} / max: 516
// rule with max period: {2, 7, 10, 12, 15, 20, 22} / period: 516
