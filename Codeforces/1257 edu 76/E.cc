#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<lld, lld> pll;

////////////////////////////////////////////////////////////////
const int MAX_N = 600005;
int N, k1, k2, k3;
int A[MAX_N];
int S1[MAX_N], S2[MAX_N], S3[MAX_N];

void input() {
  cin >> k1 >> k2 >> k3;
  N = k1 + k2 + k3;
  for (int i = 0; i < k1; i++) {
    int j; cin >> j;
    A[j - 1] = 1;
  }
  for (int i = 0; i < k2; i++) {
    int j; cin >> j;
    A[j - 1] = 2;
  }
  for (int i = 0; i < k3; i++) {
    int j; cin >> j;
    A[j - 1] = 3;
  }
}

void prefixSum() {
  for (int i = 1; i <= N; i++) {
    S1[i] = S1[i - 1];
    S2[i] = S2[i - 1];
    S3[i] = S3[i - 1];
    if (A[i - 1] == 1) { S1[i]++; }
    if (A[i - 1] == 2) { S2[i]++; }
    if (A[i - 1] == 3) { S3[i]++; }
  }
}

void calc() {
  int res = INT_MAX, cost = 0, minCost = 0;
  for (int i = 0; i <= N; i++) {
    if (i != 0) {
      if (A[i - 1] == 1) { cost--; }
      if (A[i - 1] == 2) { cost++; }
      minCost = min(minCost, cost);
    }
    int totCost = k1 - S1[i] + k2 - S2[i] + S3[i] + S1[i] + minCost;
    res = min(res, totCost);
  }
  cout << res << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();
  prefixSum();
  calc();

  ////////////////////////////////
  return 0;
}
