#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    for (int r=0; r<s.size(); r++) {
        vector<char> st;
        bool ok = true;
        for (int i=r; i<s.size()+r; i++) {
            int j = i%s.size();
            if (s[j] == ')') {
                if (st.size() == 0 || st.back() != '(') ok = false;
                else st.pop_back();
            } else if (s[j] == '}') {
                if (st.size() == 0 || st.back() != '{') ok = false;
                else st.pop_back();
            } else if (s[j] == ']') {
                if (st.size() == 0 || st.back() != '[') ok = false;
                else st.pop_back();
            } else {
                st.push_back(s[j]);
            }
        }
        if (ok && st.size() == 0) answer++;
    }
    return answer;
}
