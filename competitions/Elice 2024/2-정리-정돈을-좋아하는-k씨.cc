#include <bits/stdc++.h>
using namespace std;

const int MN = 101010;
int A[MN];

int main() {
  int N, M; cin >> N >> M;
  for (int i=1; i<=N; i++) cin >> A[i];
  
  for (int q=0; q<M; q++) {
    int l, r, k; cin >> l >> r >> k;
    vector<int> B;
    for (int i=l; i<=r; i++) B.push_back(A[i]);
    sort(B.begin(), B.end());
    cout << B[k-1] << endl;
  }
  return 0;
}
