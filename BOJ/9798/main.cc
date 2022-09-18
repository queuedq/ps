#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 101010;
int N, idx[MN], P[MN], L[MN], R[MN];
pii A[MN];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ////////////////////////////////

  cin >> N;
  for (int i=1; i<=N; i++) cin >> A[i].first >> A[i].second;
  iota(idx+1, idx+N+1, 1);
  sort(idx+1, idx+N+1, [](int a, int b) { return A[a] < A[b]; });

  vector<int> st;
  for (int k=1; k<=N; k++) {
    int i = idx[k];
    int last = 0;
    while (sz(st) && A[st.back()].second > A[i].second) {
      last = st.back(); st.pop_back();
    }
    L[i] = last; P[last] = i;
    st.push_back(i);
  }

  st.clear();
  for (int k=N; k>=1; k--) {
    int i = idx[k];
    int last = 0;
    while (sz(st) && A[st.back()].second > A[i].second) {
      last = st.back(); st.pop_back();
    }
    R[i] = last; P[last] = i;
    st.push_back(i);
  }

  cout << "YES" << endl;
  for (int i=1; i<=N; i++) {
    cout << P[i] << " " << L[i] << " " << R[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
