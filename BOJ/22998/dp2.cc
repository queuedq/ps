#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 1<<18;
int D[MK];
vector<int> group[128];

int calc(int n, vector<int> P) { // number of inc seq
  vector<int> D(n);
  int sum = 0;
  for (int i=0; i<n; i++) {
    D[i] = 1;
    for (int j=0; j<i; j++)
      if (P[j] < P[i]) D[i] += D[j];
    sum += D[i];
  }
  return sum;
}

void perm(int n, vector<int> P) {
  if (sz(P) == n) {
    int cnt = calc(n, P);
    group[cnt] = P;
    return;
  }
  for (int i=0; i<n; i++) {
    if (count(all(P), i)) continue;
    P.push_back(i);
    perm(n, P);
    P.pop_back();
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  for (int n=7; n>=1; n--) {
    vector<int> P;
    perm(n, P);
  }

  D[0] = 0;
  for (int i=1; i<MK; i++) {
    D[i] = D[i-1]+1;
    // add second to the bottom, makes loop condition below into j<11
    // if (i-2>=1) D[i] = min(D[i], D[i-2]+1);

    for (int j=1; j<31; j++) { // add sz(group[j]) elems at the top
      if (i%(j+1) == j) D[i] = min(D[i], D[i/(j+1)] + sz(group[j]));
    }
  }

  int mx = 0;
  for (int i=0; i<MK; i++) mx = max(mx, D[i]);
  for (int i=0; i<100; i++) {
    cout << D[i] << " ";
    if (i%10 == 9) cout << endl;
  }
  cout << mx << endl;

  ////////////////////////////////
  return 0;
}
