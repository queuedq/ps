#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 1e5+5;
int N, K, D;

struct Student {
  int d, A[30];

  bool operator <(const Student x) const {
    return d < x.d;
  }
} S[MAXN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K >> D;
  for (int i=0; i<N; i++) {
    int M, d; cin >> M >> d;
    S[i].d = d;
    for (int j=0; j<M; j++) {
      int a; cin >> a; a--;
      S[i].A[a]++;
    }
  }

  sort(S, S+N);

  int j = 0, A[30], ans = 0;
  fill(A, A+30, 0);
  for (int i=0; i<N; i++) {
    for (int a=0; a<30; a++) A[a] += S[i].A[a];
    while (S[j].d < S[i].d - D) {
      for (int a=0; a<30; a++) A[a] -= S[j].A[a];
      j++;
    }

    int score = 0;
    for (int a=0; a<30; a++) score += (A[a] > 0 && A[a] < i-j+1);
    score *= (i-j+1);
    ans = max(ans, score);
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
