#include <bits/stdc++.h>
using namespace std;

////////////////////////////////////////////////////////////////
int N, M;
unordered_map<string, bool> A;
vector<string> ans;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> N >> M;
  for (int i=0; i<N; i++) {
    string s; cin >> s;
    A[s] = true;
  }

  for (int i=0; i<M; i++) {
    string s; cin >> s;
    if (A[s]) ans.push_back(s);
  }

  sort(ans.begin(), ans.end());

  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
