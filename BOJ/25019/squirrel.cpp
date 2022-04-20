#include "squirrel.h"
#include <bits/stdc++.h>
#define endl "\n"
#define all(x) (x).begin(), (x).end()
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

////////////////////////////////////////////////////////////////
const int MN = 5e5+5;
lld N, S[MN], E[MN];

lld fly(vector<int> D, vector<int> H, vector<int> W, int L, int R) {
    // Preprocessing
    // turn into intervals
    N = D.size();
    for (int i=0; i<N; i++) {
      S[i] = D[i];
      E[i] = D[i] + H[i];
    }

    // cut interval ends
    E[N-1] = D[N-1] + R;
    for (int i=N-2; i>=0; i--) {
      E[i] = min(E[i], E[i+1]);
    }

    // cut interval starts
    L = min((lld)L, E[0]);
    for (int i=0; i<N; i++) {
      S[i] = max(S[i], (lld)L);
    }

    // now S, E are increasing

    // disconnected
    for (int i=0; i<N-1; i++) {
      if (E[i] < S[i+1]) return -1;
    }

    S[N] = E[N-1]; // for easier impl

    // Main logic
    lld x = S[0], ans = 0;
    set<pll> ws; // (W[k], k) of alive intervals

    // jth ~ ith intervals alive at x
    for (int i=0, j=0; i<=N; i++) {
      // dead intervals
      while (E[j] < S[i]) {
        ans += (E[j] - x) * ws.begin()->first;
        x = E[j];
        ws.erase({W[j], j});
        j++;
      }

      ans += (S[i] - x) * ws.begin()->first;
      x = S[i];
      ws.insert({W[i], i});
    }

    return ans;
}
