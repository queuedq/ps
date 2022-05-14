#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
void fill_circle(vector<vector<lld>> &arr, lld x, lld y, lld r, lld c) {
  for (lld i=-r; i<=r; i++) {
    for (lld j=-r; j<=r; j++) {
      if (round(sqrt(i*i + j*j)) <= r) arr[x+i][y+j] = c;
    }
  }
}

void draw_circle(vector<vector<lld>> &arr, lld x, lld y, lld R, lld c) {
  for (lld i=-R; i<=R; i++) {
    lld j = round(sqrt(R*R - i*i));
    arr[x+i][y+j] = c;
    arr[x+i][y-j] = c;
    arr[x+j][y+i] = c;
    arr[x-j][y+i] = c;
  }
}

lld solve() {
  lld R; cin >> R;
  vector<vector<lld>> A, B;
  A.resize(R*2+1); B.resize(R*2+1);
  for (lld i=0; i<R*2+1; i++) { A[i].resize(R*2+1); B[i].resize(R*2+1); }
  
  fill_circle(A, R, R, R, 1);
  for (lld r=0; r<=R; r++) {
    draw_circle(B, R, R, r, 1);
  }

  lld ans = 0;
  for (int i=0; i<R*2+1; i++) {
    for (int j=0; j<R*2+1; j++) {
      ans += A[i][j] != B[i][j];
    }
  }
  return ans;

  // for (int i=0; i<R*2+1; i++) {
  //   for (int j=0; j<R*2+1; j++) {
  //     cout << A[i][j];
  //   }
  //   cout << endl;
  // }
  // cout << endl;

  // for (int i=0; i<R*2+1; i++) {
  //   for (int j=0; j<R*2+1; j++) {
  //     cout << B[i][j];
  //   }
  //   cout << endl;
  // }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    cout << "Case #" << t << ": " << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
