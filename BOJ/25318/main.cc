#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int parse_date(string date) {
  int y = stoi(date.substr(0, 4));
  int m = stoi(date.substr(5, 2));
  int d = stoi(date.substr(8, 2));
  for (int i=2019; i<y; i++) d += (i == 2020) ? 366 : 365;
  for (int i=1; i<m; i++) d += (y == 2020 && i == 2) ? 29 : months[i];
  return d;
}

int parse_time(string time) {
  int h = stoi(time.substr(0, 2));
  int m = stoi(time.substr(3, 2));
  int s = stoi(time.substr(6, 2));
  return h * 60 * 60 + m * 60 + s;
}

double parse_datetime(string date, string time) {
  return parse_date(date) + (double)parse_time(time) / (60 * 60 * 24);
}

const int MN = 505050;
int N, L[MN];
double T[MN];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  int N; cin >> N;
  if (N == 0) { cout << 0 << endl; return 0; }

  for (int i=1; i<=N; i++) {
    string date, time; cin >> date >> time >> L[i];
    T[i] = parse_datetime(date, time);
  }

  double sum = 0, psum = 0;
  for (int i=1; i<=N; i++) {
    double P = max(pow(0.5, (T[N]-T[i])/365), pow(0.9, (N-i)));
    sum += L[i] * P;
    psum += P;
  }

  cout << (int)round(sum/psum) << endl;

  ////////////////////////////////
  return 0;
}
