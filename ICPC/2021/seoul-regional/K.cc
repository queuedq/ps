#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

template<class T>
ostream& operator <<(ostream& os, vector<T> vec) {
  os << "[";
  for (int i=0; i<(int)vec.size()-1; i++) os << vec[i] << ", ";
  if (!vec.empty()) os << vec.back();
  os << "]";
  return os;
}

////////////////////////////////////////////////////////////////
const int MN = 1e6+5;
int M, N, P[MN], S[MN], px, sx;
int pi[MN];

struct fenwick_tree {
  vector<lld> F;

  fenwick_tree(int sz) { F.resize(sz+1); }

  void add(int i, lld x) {
    for (; i<F.size(); i+=i&-i) F[i] += x;
  }

  void ins(int i) { add(i, 1); }
  void del(int i) { add(i, -1); }

  lld sum(int i) { // [1, i]
    lld s = 0;
    for (; i>0; i-=i&-i) s += F[i];
    return s;
  }

  void print() {
    for (int i=1; i<F.size(); i++) cout << sum(i)-sum(i-1) << " "; cout << endl;
  }
};

void failure() {
  int j = 0;
  fenwick_tree F1(px), F2(px);

  for (int i=1; i<M; i++) {
    while (j > 0) {
      if (F1.sum(P[j]-1) == F2.sum(P[i]-1) && F1.sum(P[j]) == F2.sum(P[i])) break;
      int tmp = pi[j-1];
      while (j > tmp) {
        F1.del(P[j-1]); F2.del(P[i-j]);
        j--;
      }
    }
    if (F1.sum(P[j]-1) == F2.sum(P[i]-1) && F1.sum(P[j]) == F2.sum(P[i])) {
      F1.ins(P[j]); F2.ins(P[i]);
      j++;
      pi[i] = j;
    } else pi[i] = 0;
  }
}

vector<int> matches() {
  vector<int> ans;

  int j = 0;
  fenwick_tree F1(px), F2(sx);

  for (int i=0; i<N; i++) {
    while (j > 0) {
      if (F1.sum(P[j]-1) == F2.sum(S[i]-1) && F1.sum(P[j]) == F2.sum(S[i])) break;
      int tmp = pi[j-1];
      while (j > tmp) {
        F1.del(P[j-1]); F2.del(S[i-j]);
        j--;
      }
    }
    if (F1.sum(P[j]-1) == F2.sum(S[i]-1) && F1.sum(P[j]) == F2.sum(S[i])) {
      F1.ins(P[j]); F2.ins(S[i]);
      j++;

      if (j == M) {
        ans.push_back(i-M+1);

        int tmp = pi[j-1];
        while (j > tmp) {
          F1.del(P[j-1]); F2.del(S[i-j+1]);
          j--;
        }
      }
    }
    // cout << i << " " << j << endl;
    // F1.print();
    // F2.print();
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  cin >> M >> N;

  vector<int> xs;
  for (int i=0; i<M; i++) { cin >> P[i]; xs.push_back(P[i]); }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  px = xs.size();
  for (int i=0; i<M; i++) {
    P[i] = lower_bound(all(xs), P[i]) - xs.begin() + 1; // 1-based
  }

  xs.clear();
  for (int i=0; i<N; i++) { cin >> S[i]; xs.push_back(S[i]); }
  sort(all(xs));
  xs.erase(unique(all(xs)), xs.end());
  sx = xs.size();
  for (int i=0; i<N; i++) {
    S[i] = lower_bound(all(xs), S[i]) - xs.begin() + 1; // 1-based
  }

  // for (int i=0; i<M; i++) cout << P[i] << " "; cout << endl;
  // for (int i=0; i<N; i++) cout << S[i] << " "; cout << endl;

  ////////////////////////////////

  failure();
  // for (int i=0; i<M; i++) cout << pi[i] << " "; cout << endl;
  auto ans = matches();
  if (ans.size() == 0) cout << 0;
  else for (auto a: ans) cout << a+1 << " ";

  ////////////////////////////////
  return 0;
}
