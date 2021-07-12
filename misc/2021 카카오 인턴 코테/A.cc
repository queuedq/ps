#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using lld = long long;
using pii = pair<int, int>;
using pll = pair<lld, lld>;

string table[10] = {
    "zero", "one", "two", "three", "four",
    "five", "six", "seven", "eight", "nine",
};

int get_digit(string s, int i, int len) {
    if (0 <= s[i]-'0' && s[i]-'0' <= 9) return s[i]-'0';

    for (int j=0; j<10; j++) {
        if (s.compare(i, len, table[j]) == 0) return j;
    }
    return -1;
}

int solution(string s) {
    int answer = 0;

    for (int i=0; i<s.size();) {
        int digit = -1, len = 0;
        while (digit == -1) {
            len++;
            digit = get_digit(s, i, len);
        }

        answer *= 10;
        answer += digit;
        i += len;
    }

    return answer;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ////////////////////////////////

    while (true) {
        string s;
        cin >> s;
        cout << solution(s) << endl;
    }

    ////////////////////////////////
    return 0;
}
