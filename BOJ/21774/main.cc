#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
int N, Q;
vector<string> cnt[7];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N >> Q;
  cin.ignore();

  for (int i=0; i<N; i++) {
    string S; getline(cin, S);

    int j = S.find('#');
    string date = S.substr(0, j);
    int level = stoi(S.substr(j+1));

    cnt[level].push_back(date);
  }

  for (int i=0; i<Q; i++) {
    string S; getline(cin, S);

    int j = S.find('#');
    int k = S.find('#', j+1);
    string s_date = S.substr(0, j);
    string e_date = S.substr(j+1, k-j-1);
    int level = stoi(S.substr(k+1));
    
    int ans = 0;
    for (int l=level; l<=6; l++) {
      int s = lower_bound(cnt[l].begin(), cnt[l].end(), s_date) - cnt[l].begin();
      int e = upper_bound(cnt[l].begin(), cnt[l].end(), e_date) - cnt[l].begin();
      ans += e - s;
    }
    cout << ans << endl;
  }

  ////////////////////////////////
  return 0;
}
