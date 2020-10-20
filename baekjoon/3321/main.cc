#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 15005;
const int MAXM = 1505;
int N, M, D[MAXM], ord[MAXM];
string A[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) cin >> A[i];
  for (int i=0; i<M; i++) ord[i] = i;

  int area = 0;
  for (int i=0; i<N; i++) {
    int k = 0;
    for (int j=0; j<M; j++) {
      if (A[i][ord[j]] == '0') D[ord[j]] = 0;
      else {
        D[ord[j]]++;
        swap(ord[k++], ord[j]);
      }
    }

    for (int j=0; j<M; j++) {
      area = max(area, (j+1) * D[ord[j]]);
    }
  }

  cout << area << endl;

  ////////////////////////////////
  return 0;
}
