#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, M;
vector<string> A, B, ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  A.resize(N);
  B.resize(M);

  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) cin >> B[i];

  sort(A.begin(), A.end());
  sort(B.begin(), B.end());

  int j = 0;
  for (int i=0; i<N; i++) {
    while (j < M && A[i].compare(B[j]) > 0) j++;
    if (j == M) break;
    if (A[i] == B[j]) ans.push_back(A[i]);
  }

  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); i++) cout << ans[i] << endl;

  ////////////////////////////////
  return 0;
}
