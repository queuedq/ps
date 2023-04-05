#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int N = 100;
const int M = 10000;
int P, A[N][M], tmp[M];
pii correct[M];

double predict(double x, double b0, double b1) {
  return 1 / (1 + exp(-(b0 + b1*x)));
}

// For debug purposes
double cost(vector<double> &X, vector<double> &Y, double b0, double b1) {
  double ret = 0;
  for (int i=0; i<X.size(); i++) {
    double yh = predict(X[i], b0, b1);
    ret += - (Y[i] * log(yh) - (1-Y[i]) * log(1-yh)) / X.size();
  }
  return ret;
}

pair<double, double> fit(vector<double> &X, vector<double> &Y) {
  double rate = 20., b0 = 0, b1 = 0;
  for (int epoch = 0; epoch < 20; epoch++) {
    for (int i=0; i<X.size(); i++) {
      double yh = predict(X[i], b0, b1);
      b0 -= rate * (yh - Y[i]) / X.size();
      b1 -= rate * X[i] * (yh - Y[i]) / X.size();
    }
  }
  return {b0, b1};
}

void solve(int test) {
  for (int j=0; j<M; j++) correct[j] = {0, j};

  for (int i=0; i<N; i++) {
    string S; cin >> S;
    for (int j=0; j<M; j++) {
      A[i][j] = S[j] - '0';
      correct[j].first += A[i][j];
    }
  }

  sort(correct, correct+M);

  for (int i=0; i<N; i++) {
    for (int j=0; j<M; j++) tmp[j] = A[i][j];
    for (int j=0; j<M; j++) A[i][j] = tmp[correct[j].second];
  }

  vector<double> X;
  for (int i=0; i<M; i++) X.push_back(i*6./(M-1) - 3);

  int mni = 0; double mn = 10;
  for (int i=0; i<N; i++) {
    vector<double> Y;
    for (int j=0; j<M; j++) Y.push_back(A[i][j]);
    auto [b0, b1] = fit(X, Y);
    if (b1 < mn) { mni = i; mn = b1; }
    // cout << i << " " << cost(X, Y, b0, b1) << " " << b0 << " " << b1 << endl;
  }
  
  printf("Case #%d: %d\n", test, mni+1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int T; cin >> T >> P;
  for (int t=1; t<=T; t++) {
    solve(t);
  }

  ////////////////////////////////
  return 0;
}
