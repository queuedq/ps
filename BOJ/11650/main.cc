#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
const int MAXN = 100'005;
int N;
pair<int, int> A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> A[i].first >> A[i].second;
  }

  sort(A, A+N);

  for (int i=0; i<N; i++) {
    cout << A[i].first << ' ' << A[i].second << '\n';
  }

  ////////////////////////////////
  return 0;
}
