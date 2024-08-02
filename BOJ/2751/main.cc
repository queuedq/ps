#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int N, A[MN];

void merge_sort(int s, int e) {
  if (e-s <= 1) return;
  int m = (s+e)/2;
  merge_sort(s, m);
  merge_sort(m, e);
  
  // merge
  vector<int> B;
  int j = m;
  for (int i=s; i<m; i++) {
    while (j < e && A[j] < A[i]) B.push_back(A[j++]);
    B.push_back(A[i]);
  }
  while (j < e) B.push_back(A[j++]);

  for (int i=s; i<e; i++) A[i] = B[i-s];
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) cin >> A[i];
  merge_sort(0, N);

  for (int i=0; i<N; i++) cout << A[i] << endl;

  ////////////////////////////////
  return 0;
}
