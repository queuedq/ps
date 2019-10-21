#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

template<typename T>
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
#define SQRT_K 50000
lld K;
bool composite[SQRT_K];
vector<lld> primes;

struct Candidate {
  lld num, mobius, pFactorIdx;
};
bool cmpCand(Candidate a, Candidate b) {
  if (a.num == b.num) return (a.pFactorIdx > b.pFactorIdx);
  return a.num > b.num;
}

vector<lld> SF;
vector<lld> mobius;

priority_queue<Candidate, vector<Candidate>, decltype(&cmpCand)> candidates(cmpCand);
lld idx[SQRT_K];

void getPrimes() {
  for (lld i = 2; i * i < SQRT_K; i++) {
    if (composite[i]) { continue; }
    for (lld j = i * 2; j < SQRT_K; j += i) {
      composite[j] = true;
    }
  }

  for (lld i = 2; i < SQRT_K; i++) {
    if (!composite[i]) { primes.push_back(i); }
  }
}

void getSquareFreeNumbers() {
  SF.push_back(1);
  mobius.push_back(1);
  for (lld i = 0; i < primes.size(); i++) {
    idx[i] = 0;
    candidates.push({primes[i], -1, i});
  }

  while (SF.back() < SQRT_K) {
    Candidate maybe = candidates.top();
    candidates.pop();

    lld prevSF = SF.back();
    lld nextSF = maybe.num;
    lld i = maybe.pFactorIdx;
    lld p = primes[i];

    bool isSF = (nextSF / p) % p != 0;
    bool isNotDuplicate = nextSF != prevSF;

    if (isSF && isNotDuplicate) {
      SF.push_back(nextSF);
      mobius.push_back(maybe.mobius);
    }

    idx[i]++;
    candidates.push({p * SF[idx[i]], -mobius[idx[i]], i});
  }

  // for (int i = 0; i < 30; i++) {
  //   cout << SF[i] << " " << mobius[i] << endl;
  // }
}

lld squareFreesUnder(lld n) {
  lld result = 0;
  for (int i = 0; i < SF.size(); i++) {
    if (SF[i] * SF[i] > n) break;
    result += mobius[i] * (n / SF[i] / SF[i]);
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  getPrimes();
  getSquareFreeNumbers();

  // cout << squareFreesUnder(46) << endl;

  cin >> K;
  lld r = K;
  while (squareFreesUnder(r) < K) {
    r *= 2;
  }

  lld l = 0, mid = (l + r) / 2;
  while (l + 1 < r) {
    if (squareFreesUnder(mid) >= K) {
      r = mid;
      mid = (l + r) / 2;
    } else {
      l = mid;
      mid = (l + r) / 2;
    }
  }

  cout << r << endl;

  ////////////////////////////////
  return 0;
}
