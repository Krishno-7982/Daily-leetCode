class Solution {
public:
    string removeOuterParentheses(string s) {
        string r = "";
        int depth = 0;

        for(char c : s) {
            if(c == '(') {
                if(depth > 0) {
                    r += c;
                }
                depth++;
            }
            else {
                depth--;
                if(depth > 0) {
                    r += c;
                }
            }
        }

        return r;
    }
};