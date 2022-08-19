#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

// COLORS: https://stackoverflow.com/a/30304782
#define RST  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

#define FRED(x) KRED << x << RST
#define FGRN(x) KGRN << x << RST
#define FYEL(x) KYEL << x << RST
#define FBLU(x) KBLU << x << RST
#define FMAG(x) KMAG << x << RST
#define FCYN(x) KCYN << x << RST
#define FWHT(x) KWHT << x << RST

#define BOLD(x) "\x1B[1m" << x << RST
#define UNDL(x) "\x1B[4m" << x << RST
// END

////////////////////////////////////////////////////////////////
int N;
vector<int> A, B;

void merge() {
  B.clear();
  int i=0, j=N/2;
  while (i<N/2 || j<N) {
    if (j == N) B.push_back(A[i++]);
    else if (i == N/2) B.push_back(A[j++]);
    else if (A[i] < A[j]) B.push_back(A[i++]);
    else B.push_back(A[j++]);
  }
}

void print() {
  int mx = 0;
  for (int i=0; i<N/2; i++) {
    if (A[i] > mx) { cout << FCYN(A[i]) << " "; mx = A[i]; }
    else cout << A[i] << " ";
  }
  cout << "/ ";
  
  mx = 0;
  for (int i=N/2; i<N; i++) {
    if (A[i] > mx) { cout << FCYN(A[i]) << " "; mx = A[i]; }
    else cout << A[i] << " ";
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int seed = 0;
  cin >> N >> seed; // example: 24 5
  A.resize(N);
  if (seed == 0) {
    for (int i=0; i<N; i++) cin >> A[i];
  } else {
    for (int i=0; i<N; i++) A[i] = i+1;
    shuffle(all(A), default_random_engine(seed));
  }

  int t;
  for (t=0; t<10000; t++) {
    cout << "[" << t << "]" << endl;
    print();

    merge();
    if (A == B) break;
    A = B;
  }
  cout << t << endl;

  ////////////////////////////////
  return 0;
}
