#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

#define st second
#define ed first

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, K;
pii A[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> K;
  for (int i=0; i<N; i++) {
    cin >> A[i].st >> A[i].ed;
  }
  sort(A, A+N);

  multiset<int> S; // end times of K-1 participants
  for (int i=0; i<K-1; i++) S.insert(0);

  int end = 0, ans = 0; // end: Kth's end time
  for (int i=0; i<N; i++) {
    if (end >= A[i].st) continue; // Kth cannot participate, ignore
    
    auto it = S.lower_bound(A[i].st);
    if (it != S.begin()) {
      it--; // ends before A[i].st
      S.erase(it);
      S.insert(A[i].ed);
    } else {
      end = A[i].ed;
      ans++;
    }
  }

  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
