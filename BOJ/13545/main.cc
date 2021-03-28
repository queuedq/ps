#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long lld;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////

#define MAX_N 100000
#define MAX_M 100000
#define PAD 3

typedef struct Query {
  int l, r, index;
} Query;

typedef struct Interval {
  int l, r;
} Interval;

int N, M, sqrtN;
int A[MAX_N], S[MAX_N];
Query Q[MAX_M];

list<int> SS[MAX_N * 2 + PAD * 2];
int lengths[MAX_N + 1000], decomp[1000];
int ans[MAX_M];

bool mo_cmp(Query a, Query b) {
  if (a.l / sqrtN < b.l / sqrtN) {
    return true;
  } else if (a.l / sqrtN == b.l / sqrtN) {
    return a.r < b.r;
  } else {
    return false;
  }
}

list<int>& invS(int s) {
  return SS[s + MAX_N + PAD];
}

void insert(Interval a) {
  lengths[a.r - a.l]++;
  decomp[(a.r - a.l) / sqrtN]++;
}

void remove(Interval a) {
  lengths[a.r - a.l]--;
  decomp[(a.r - a.l) / sqrtN]--;
}

////////

void input() {
  cin >> N;
  sqrtN = floor(sqrt(N));
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    sum += A[i];
    S[i + 1] = sum;
  }

  cin >> M;
  for (int i = 0; i < M; i++) {
    int l, r;
    cin >> l >> r;
    Q[i] = {l - 1, r, i};
  }
  sort(Q, Q + M, mo_cmp);
}

void processQueries() {
  int pl = 0, pr = 0;
  invS(0).push_back(0);

  for (int i = 0; i < M; i++) {
    // R -->
    while (pr < Q[i].r) {
      pr++;
      list<int> &idx = invS(S[pr]);

      if (idx.size() >= 2) {
        int l = idx.front(), r = idx.back();
        remove({l, r});
        insert({l, pr});
      } else if (idx.size() == 1) {
        int l = idx.front();
        insert({l, pr});
      }

      idx.push_back(pr);
    }

    // <-- L
    while (pl > Q[i].l) {
      pl--;
      list<int> &idx = invS(S[pl]);

      if (idx.size() >= 2) {
        int l = idx.front(), r = idx.back();
        remove({l, r});
        insert({pl, r});
      } else if (idx.size() == 1) {
        int r = idx.back();
        insert({pl, r});
      }

      idx.push_front(pl);
    }

    // <-- R
    while (pr > Q[i].r) {
      list<int> &idx = invS(S[pr]);

      // assert(idx.back() == pr);
      idx.pop_back();

      if (idx.size() >= 2) {
        int l = idx.front(), r = idx.back();
        remove({l, pr});
        insert({l, r});
      } else if (idx.size() == 1) {
        int l = idx.front();
        remove({l, pr});
      }

      pr--;
    }

    // L -->
    while (pl < Q[i].l) {
      list<int>& idx = invS(S[pl]);

      // assert(idx.front() == pl);
      idx.pop_front();

      if (idx.size() >= 2) {
        int l = idx.front(), r = idx.back();
        remove({pl, r});
        insert({l, r});
      } else if (idx.size() == 1) {
        int r = idx.back();
        remove({pl, r});
      }

      pl++;
    }

    // cout << "pl, pr: " << pl << " " << pr << endl;

    // Find max length
    int maxD = sqrtN + 1;
    while (decomp[maxD] == 0 && maxD >= 0) { maxD--; }
    if (maxD == -1) {
      ans[Q[i].index] = 0;
    } else {
      int longest = (maxD + 1) * sqrtN;
      while (lengths[longest] == 0 && longest >= maxD * sqrtN) { longest--; }
      ans[Q[i].index] = longest;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ////////////////////////////////

  input();

  // cout << "======= Queries ========" << endl;
  // for (int i = 0; i < M; i++) {
  //   cout << Q[i].first << " " << Q[i].second << endl;
  // }
  // cout << "========================" << endl;

  processQueries();

  for (int i = 0; i < M; i++) {
    cout << ans[i] << endl;
  }

  ////////////////////////////////
  return 0;
}
