#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 55;
int N, M, K, cnt[26];
char A[MN][MN];
vector<pii> pos[26];
string S;

string ans;
int y, x;

void move(int ny, int nx) {
  while (y < ny) { y++; ans.push_back('D'); }
  while (y > ny) { y--; ans.push_back('U'); }
  while (x < nx) { x++; ans.push_back('R'); }
  while (x > nx) { x--; ans.push_back('L'); }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M >> K;
  for (int i=0; i<N; i++) {
    cin >> A[i];
    for (int j=0; j<M; j++) pos[A[i][j]-'a'].push_back({i, j});
  }
  cin >> S;
  for (int i=0; i<K; i++) cnt[S[i]-'a']++;

  int C = 1e9;
  for (int i=0; i<26; i++) {
    if (cnt[i]) C = min(C, sz(pos[i]) / cnt[i]);
  }

  for (int i=0; i<C; i++) {
    for (int j=0; j<K; j++) {
      auto [ny, nx] = pos[S[j]-'a'].back(); pos[S[j]-'a'].pop_back();
      move(ny, nx);
      ans.push_back('P');
    }
  }
  move(N-1, M-1);

  cout << C << " " << sz(ans) << endl;
  cout << ans << endl;

  ////////////////////////////////
  return 0;
}
