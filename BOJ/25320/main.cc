#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 202020;
int N, M, vst[MN], need[MN];
char robot[MN];
vector<int> chain[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<M; i++) {
    string _; int num; cin >> robot[i] >> _ >> num;
    chain[i].push_back(num);
    vst[num] = 1;
  }

  vector<pii> A; // starting blocks
  for (int i=0; i<M; i++) {
    if (i == M-1) need[i] = robot[i] == 'A';
    else need[i] = robot[i] == robot[i+1];
    if (need[i]) A.push_back({chain[i][0], i});
  }
  sort(A.rbegin(), A.rend());
  
  vector<int> B; // unused blocks
  for (int i=1; i<=N*2; i++)
    if (!vst[i]) B.push_back(i); 
  
  // place blocks at needed chain
  bool ok = 1;
  for (auto [b, i]: A) {
    if (!need[i]) continue;
    if (B.empty() || B.back() < b) { ok = 0; break; }
    chain[i].push_back(B.back());
    B.pop_back();
  }
  if (!ok) { cout << "NO" << endl; return 0; }
  
  // place remaining blocks at 1 chain
  for (int i=0; i<M; i++) {
    if (chain[i][0] == 1) {
      while (!B.empty()) {
        chain[i].push_back(B.back());
        B.pop_back();
      }
      sort(all(chain[i]));
    }
  }
  if (!B.empty()) { cout << "NO" << endl; return 0; }

  // print
  cout << "YES" << endl;
  int t = 0;
  for (int i=0; i<M; i++) {
    for (int j=0; j<chain[i].size(); j++) {
      cout << (t%2 == 0 ? 'A' : 'B') << ' ';
      cout << (j == 0 ? "BLOCK" : "CHAIN") << ' ';
      cout << chain[i][j] << endl;
      t++;
    }
  }

  ////////////////////////////////
  return 0;
}
