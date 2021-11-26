#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, X[MN], A, B, nim, cnt, mx;

bool win() {
  if (A == B) return nim;
  if (A > B) return !(nim == 0 && cnt == 0);
  // A < B
  if (cnt == 0) return nim;
  if (cnt > 1) return false;
  // and cnt == 1
  int g = (mx % (A+1)) ^ nim;
  int target = mx / (A+1) * (A+1) + g;
  if (target > mx) target -= A+1;

  if (target <= A) return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> A >> B;
  for (int i=0; i<N; i++) {
    cin >> X[i];
    nim ^= X[i] % (min(A, B)+1);
    if (X[i] > min(A, B)) cnt++;
    mx = max(mx, X[i]);
  }

  cout << (win() ? "Petyr" : "Varys") << endl;

  ////////////////////////////////
  return 0;
}
