#include <bits/stdc++.h>

using namespace std;

#define ioinit() ios::sync_with_stdio(false), cin.tie(nullptr);
#define INF INT_MAX
#define LINF LONG_MAX
#define x first
#define y second
#define MOD 1000000007

typedef long long lld;
typedef pair<int, int> pii;

int N;
string A[1000005], S;
map<string, int> prefixes;
vector<int> D;

int main() {
    ioinit();
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        for (int j = 0; j < A[i].size(); j++) {
            string pre = A[i].substr(0, j+1);
            if (prefixes.count(pre) == 0)
                prefixes.insert({pre, 1});
            else {
                int k = prefixes.find(pre)->y;
                prefixes.erase(pre);
                prefixes.insert({pre, k+1});
            }
        }
    }

    cin >> S;

    D.push_back(1);

    for (int end = 1; end <= S.size(); end++) {
        int cnt = 0;
        for (int start = max(0, end-300); start < end; start++) {
            int mul = 0;
            string pre = S.substr(start, end-start);
            if (prefixes.count(pre))
                mul += prefixes.find(pre)->y;
            cnt += (D[start]*mul) % MOD;
        }
        D.push_back(cnt % MOD);
    }

    cout << D[D.size()-1];

    return 0;
}
