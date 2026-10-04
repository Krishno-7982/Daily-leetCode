class Solution {
public:
    bool checkValidString(string s) {
        stack<int> s1, s2;

        for(int i = 0; i < s.size(); i++) {
            if(s[i] == '(') {
                s1.push(i);
            }
            else if(s[i] == '*') {
                s2.push(i);
            }
            else {
                // First try to match ')' with '('
                if(!s1.empty()) {
                    s1.pop();
                }
                // Otherwise use '*' as '('
                else if(!s2.empty()) {
                    s2.pop();
                }
                else {
                    return false;
                }
            }
        }

        // Now unmatched '(' must be matched by '*' acting as ')'
        while(!s1.empty() && !s2.empty()) {
            if(s1.top() < s2.top()) {
                s1.pop();
                s2.pop();
            }
            else {
                // '*' occurs before '('
                // It cannot act as ')' for this '('
                return false;
            }
        }

        return s1.empty();
    }
};