
class Solution {
public:
    int calculate(string s) {
        stack<int> st;

        int num = 0;
        char prev = '+';

        for (int i = 0; i < s.size(); i++) {

            if (isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }

            // Process number when we reach an operator
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.size() - 1) {

                if (prev == '+') {
                    st.push(num);
                }
                else if (prev == '-') {
                    st.push(-num);
                }
                else if (prev == '*') {
                    int x = st.top();
                    st.pop();
                    st.push(x * num);
                }
                else if (prev == '/') {
                    int x = st.top();
                    st.pop();
                    st.push(x / num);
                }

                prev = s[i];
                num = 0;
            }
        }

        int ans = 0;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        return ans;
    }
};

