#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MH = 105;
const int MV = MH * MH;
// left/up color of each tile
const int L[4] = {1, 1, 0, 0}, U[4] = {1, 0, 1, 0};

int H, W;
char A[MH][MH];
int hor[MH][MH]; // (left point of) horizontal line segment each cell belongs
int xcnt; // number of 'x's
int seg; // number of unmatching segments

int id(int i, int j) { return i*W + j; }
pii to_point(int I) { I -= W+1; return {I/W + 1, I%W + 1}; }
int h_parity(int i, int j0, int j) { return L[A[i][j0] - '1'] ^ L[A[i][j] - '1'] ^ ((j-j0) & 1); }
int v_parity(int j, int i0, int i) { return U[A[i0][j] - '1'] ^ U[A[i][j] - '1'] ^ ((i-i0) & 1); }

// bipartite matching
vector<int> adj[MV];
int cnt, S[MV], T[MV], vst[MV];

bool match_node(int u) {
  if (vst[u]) return 0;
  vst[u] = 1;

  for (int v: adj[u]) {
    if (!T[v] || match_node(T[v])) {
      S[u] = v; T[v] = u;
      return 1;
    }
  }
  return 0;
}

int match() {
  for (int i=1; i<=H; i++) {
    for (int j=1; j<=W; j++) {
      fill(vst+1, vst+(H+1)*(W+1), 0);
      cnt += match_node(id(i, j));
    }
  }
  return cnt;
}

////////////////////////////////

int solve() {
  // horizontal lines
  for (int i=1; i<=H; i++) {
    int j0 = 0;

    for (int j=1; j<=W+1; j++) {
      if (A[i][j] == 'x') { j0 = -1; continue; } // (?, x)
      
      if ('1' <= A[i][j] && A[i][j] <= '4') {
        if (j0 == -1) { j0 = j; continue; } // (x, 1)

        // (1, 1)
        if (h_parity(i, j0, j)) { // unmatching segment
          seg++;

          // not entirely 'o'
          bool ok = false;
          for (int k=j0+1; k<j; k++) if (A[i][k] == '.') ok = true;
          if (!ok) return -1;

          // save hor
          for (int k=j0+1; k<j; k++) hor[i][k] = id(i, j0+1);
        }

        j0 = j;
      }
    }
  }

  // vertical lines
  for (int j=1; j<=W; j++) {
    int i0 = 0;
    
    for (int i=1; i<=H+1; i++) {
      if (A[i][j] == 'x') { i0 = -1; continue; } // (?, x)

      if ('1' <= A[i][j] && A[i][j] <= '4') {
        if (i0 == -1) { i0 = i; continue; } // (x, 1)

        // (1, 1)
        if (v_parity(j, i0, i)) { // unmatching segment
          seg++;

          // not entirely 'o'
          bool ok = false;
          for (int k=i0+1; k<i; k++) if (A[k][j] == '.') ok = true;
          if (!ok) return -1;

          // build graph
          for (int k=i0+1; k<i; k++) {
            if (hor[k][j] == 0) continue;
            if (A[k][j] == 'o') continue; // not crossing
            adj[hor[k][j]].push_back(id(i0+1, j));
          }
        }

        i0 = i;
      }
    }
  }

  return H * W - xcnt - (seg - match());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> H >> W;
  for (int i=1; i<=H; i++) for (int j=1; j<=W; j++) {
    cin >> A[i][j];
    if (A[i][j] == 'x') xcnt++;
  }
  for (int i=1; i<=H; i++) A[i][0] = '1', A[i][W+1] = '4';
  for (int j=1; j<=W; j++) A[0][j] = '1', A[H+1][j] = '4';
  
  cout << solve() << endl;

  ////////////////////////////////
  return 0;
}
