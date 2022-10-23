#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MK = 55;
int N, K, prime[MK], P;
vector<int> ans[MK*MK];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  fill(prime+1, prime+MK, 1);
  for (int p=2; p<MK; p++) {
    if (prime[p]) {
      for (int m=p*2; m<MK; m+=p) prime[m] = 0;
    }
  }

  // for (int K=2; K<=50; K++) {
  //   int P = K-1;
  //   while (!prime[P]) P++;
  //   if (K*K*3/2 < P*P+P+1) cout << K << endl;
  // }
  // exception: K = 9

  cin >> N >> K;
  P = K-1;
  while (!prime[P]) P++; // smallest prime >= K-1
  if (K == 9) P = 7; // exception
  
  // projective plane
  for (int i=0; i<N; i++) {
    int a = i/P, b = i%P; // line: a*x+b
    for (int x=0; x<P; x++) ans[i].push_back(x*P + (a*x+b)%P);
    ans[i].push_back(P*P + a); 
    // exception
    if (K == 9) ans[i].push_back(P*P+P+1 + i); // one short, add extra point for each line
  }

  for (int i=0; i<N; i++) {
    cout << ans[i].size() << " ";
    for (auto a: ans[i]) cout << a+1 << " ";
    cout << endl;
  }

  ////////////////////////////////
  return 0;
}
