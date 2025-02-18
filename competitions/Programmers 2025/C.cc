#include <bits/stdc++.h>
#define sz(x) int(x.size())
using namespace std;
using lld = long long;
using pii = pair<int, int>;

////////////////////////////////////////////////////////////////
const int _N = 505;
int N, M;
char A[_N][_N];
int vst_A[_N], vst_B[_N];

bool oob(int x, int y) {
  return x < 1 || x > N || y < 1 || y > N;
}

lld solution(vector<string> grid) {
  N = sz(grid), M = sz(grid[0]);
  for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) A[i][j] = grid[i-1][j-1];
  
  return 0;
}
