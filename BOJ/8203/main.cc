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
int N, M, A[MN], two[MN], L[MN*2], R[MN*2];
string S;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> M >> S;
  for (int i=0; i<N; i++) A[i] = S[i] == 'W' ? 1 : 2;
  
  for (int i=N-1, last=N; i>=0; i--) {
    if (A[i] == 1) last = i;
    two[i] = last-i;
  }

  int sum = 0;
  for (int k=0, i=0; k<=N*2; k++) {
    if (i < N && sum+A[i] <= k) sum += A[i++];
    
    if (sum == k) {
      L[k] = 0, R[k] = i;
    } else if (sum == k-1) {
      // jump consecutive twos
      if (two[i] <= two[0]) L[k] = two[i], R[k] = i+two[i]+1;
      else L[k] = two[0]+1, R[k] = i+two[0]+1;
    }
  }

  for (int i=0; i<M; i++) {
    int K; cin >> K;
    if (K > sum || R[K] > N) cout << "NIE" << endl;
    else cout << L[K]+1 << " " << R[K] << endl;
  }

  ////////////////////////////////
  return 0;
}
