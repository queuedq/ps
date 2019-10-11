#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////
int N, K, primes[100];
priority_queue<int, vector<int>, greater<int>> numbers;

void input() {
  cin >> K >> N;
  for (int i = 0; i < K; i++) {
    cin >> primes[i];
  }
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  for (int i = 0; i < K; i++) {
    numbers.push(primes[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    int current = numbers.top();
    // cout << current << endl;
    numbers.pop();

    int max_factor = 0;
    for (int j = 0; j < K; j++) {
      if (current % primes[j] == 0) {
        max_factor = j;
      }
    }
    for (int j = max_factor; j < K; j++) {
      lld to_push = (lld)current * primes[j];
      if (to_push < INT_MAX) {
        numbers.push((int)to_push);
      }
    }
  }

  cout << numbers.top();

  ////////////////////////////////
  return 0;
}
