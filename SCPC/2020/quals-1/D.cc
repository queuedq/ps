#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MAXN = 50'005;
int N, K, M;
string S;

struct Num {
  int val, st, ch;
  bool operator <(Num n) const { return val < n.val; }
};
vector<Num> A;
int df[MAXN], dfcnt[MAXN*2], dfmx;

void reset() {
  A.clear();
  fill(df, df+N, 0);
  fill(dfcnt, dfcnt + MAXN*2, 0);
  dfmx = 0;
}

void solve(int test) {
  cin >> N >> K >> M >> S;

  for (int i=0; i<N-K+1; i++) {
    A.push_back({atoi(S.substr(i, K).c_str()), i, -1});
    for (int ch=0; ch<K; ch++) {
      char tmp = S[i+ch];
      S[i+ch] = '1';
      A.push_back({atoi(S.substr(i, K).c_str()), i, ch});
      S[i+ch] = tmp;
    }
  }

  sort(A.begin(), A.end());

  dfcnt[0] = N, dfmx = 0;
  int j = 0, cnt = 0, ans = 0;
  for (int i=0; i<A.size(); i++) {
    if (A[i].ch == -1) {
      cnt++;
      for (int k=A[i].st; k<A[i].st+K; k++) {
        dfcnt[MAXN+df[k]]--;
        df[k]--;
        dfcnt[MAXN+df[k]]++;
        if (dfcnt[MAXN+dfmx] == 0) dfmx--;
      }
    } else {
      int k = A[i].st+A[i].ch;
      dfcnt[MAXN+df[k]]--;
      df[k]++;
      dfcnt[MAXN+df[k]]++;
      dfmx = max(dfmx, df[k]);
    }

    while (A[j].val < A[i].val-M) {
      if (A[j].ch == -1) {
        cnt--;
        for (int k=A[j].st; k<A[j].st+K; k++) {
          dfcnt[MAXN+df[k]]--;
          df[k]++;
          dfcnt[MAXN+df[k]]++;
          dfmx = max(dfmx, df[k]);
        }
      } else {
        int k = A[j].st+A[j].ch;
        dfcnt[MAXN+df[k]]--;
        df[k]--;
        dfcnt[MAXN+df[k]]++;
        if (dfcnt[MAXN+dfmx] == 0) dfmx--;
      }
      j++;
    }

    ans = max({ans, cnt, cnt+dfmx});
  }

  cout << "Case #" << test << endl;
  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T;
  for (int t=1; t<=T; t++) {
    solve(t);
    reset();
  }

  ////////////////////////////////
  return 0;
}
