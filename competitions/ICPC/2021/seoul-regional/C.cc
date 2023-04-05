#include<bits/stdc++.h>

using namespace std;

#define int long long

int N;
int Q[10005][2], V[10005];
int x;

void move() {
  for (int i = 1; i <= N; i++) {
    if (Q[i][0] == x && !V[i]) {
      x += Q[i][1];
      V[i] = 1;
      return;
    }
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> N;
  for (int i = 1; i <= N; i++) {
    int u, v; char p;
    cin >> u >> p >> v;
    if (p == 'R')
      Q[i][0] = u, Q[i][1] = v;
    if (p == 'L')
      Q[i][0] = u, Q[i][1] = -v;
  }
  cin >> x;
  for (int i = 0; i < N; i++)
    move();
  
  cout << x << endl;
  return 0;
}
