#include "liar.h"
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;

////////////////////////////////////////////////////////////////

vector<int> subtract(const vector<int> &A, const vector<int> &B) {
  vector<int> res;
  int j = 0;
  for (int a: A) {
    while (j < sz(B) && B[j] < a) j++;
    if (j == sz(B) || B[j] != a) res.push_back(a);
  }
  return res;
}

// finds excludes (= lie streak k+1)
vector<int> solve(int k, vector<int> cand) {
  int n = sz(cand);
  if (n <= 1<<k) return {};

  // binary split
  int pattern = 0;
  for (int b=0; b<k; b++) {
    vector<int> Q;
    int mask = (1<<b) - 1;
    for (int i=0; i<n; i++) {
      if ((i&mask) == pattern && (i>>b & 1)) Q.push_back(cand[i]);
    }
    bool ans = ask(Q);
    if (!ans) pattern |= (1<<b); // lie streak +1 for Q
  }

  // collect lie streak k
  vector<int> X;
  int mask = (1<<k) - 1;
  for (int i=0; i<n; i++) {
    if ((i & mask) == pattern) X.push_back(cand[i]);
  }

  // make lie streak k+1
  if (sz(X) >= 2) {
    vector<int> Q, Qc;
    for (int i=0; i<sz(X); i++) {
      if (i & 1) Q.push_back(X[i]);
      else Qc.push_back(X[i]);
    }

    bool ans = ask(Q);
    return ans ? Qc : Q;
  }

  // make lie streak 1 for all but one
  assert(sz(X) == 1);
  bool ans = ask(X);
  if (!ans) return X;

  // reduce them again to make lie streak k+1
  return solve(k-1, subtract(cand, X));
}

vector<int> game(int k, int n) {
  vector<int> cand;
  for (int i=1; i<=n; i++) cand.push_back(i);

  while (true) {
    auto excludes = solve(k, cand);
    if (sz(excludes) == 0) break;
    cand = subtract(cand, excludes);
  }
  return cand;
}
