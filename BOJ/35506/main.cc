#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N;
string A[200];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=0; i<N*2; i++) A[i] = string(N*4+2, ' ');

  for (int i=0; i<N*2; i++) A[i][N*2-1-i] = '*';
  for (int i=0; i<N; i++) A[i][N*3-i] = '*';
  for (int i=N; i<N*2; i++) A[i][N+1+i] = '*';
  for (int i=0; i<N; i++) A[i][N*3+2+i] = '*';
  for (int i=N; i<N*2; i++) A[i][N*5+1-i] = '*';

  for (int i=0; i<N*2; i++) cout << A[i] << endl;

  ////////////////////////////////
  return 0;
}
