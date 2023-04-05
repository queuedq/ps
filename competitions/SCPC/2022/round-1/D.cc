#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
lld N, M, pi[MN+MN], cnt[2][MN];
string S, P;

void failure(const string &S) {
  for (int i=1; i<S.size(); i++) {
    int k = pi[i-1];
    while (k && S[i] != S[k]) k = pi[k-1];
    pi[i] = k + (S[i] == S[k]);
  }
}

vector<int> kmp(const string &S, const string &P) {
  int s = S.size(), p = P.size();
  failure(P+'\0'+S);

  vector<int> res;
  for (int i=p+1; i<s+p+1; i++) {
    if (pi[i] == p) res.push_back(i-p*2);
  }
  return res;
}

bool solve() {
  cin >> N >> M >> S >> P;

  cnt[0][0] = cnt[1][0] = 0;
  for (int i=0; i<N; i++) {
    cnt[1][i+1] = cnt[1][i] + (S[i]=='a');
    cnt[0][i+1] = cnt[0][i] + (S[i]=='b');
  }
  
  char st = P[0], ed = P.back();
  int l = 0, r = 0;
  for (int i=0; i<M; i++) {
    if (P[i] == st) l++;
    else break;
  }
  for (int i=M-1; i>=0; i--) {
    if (P[i] == ed) r++;
    else break;
  }
  
  // case 1: aaaa
  if (l == M) return cnt[st=='a'][N] >= M;
  
  // case 2: strip front and back and then match
  string P1 = P.substr(l, M-l-r);
  vector<int> match = kmp(S, P1);
  for (auto i: match) {
    if (cnt[st=='a'][i] >= l &&
        cnt[ed=='a'][N] - cnt[ed=='a'][i+(M-l-r)] >= r) return 1;
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    lld ans = solve();
    cout << "Case #" << t << endl;
    cout << (ans ? "YES" : "NO") << endl;
  }

  ////////////////////////////////
  return 0;
}
