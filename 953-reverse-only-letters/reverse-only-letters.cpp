class Solution {
public:
    string reverseOnlyLetters(string s) {
        string r;
        int j = s.size() - 1;

        for(int i = 0; i < s.size(); i++) {
            if(!isalpha(s[i])) {
                r.push_back(s[i]);
            }
            else {
                while(j >= 0 && !isalpha(s[j])) {
                    j--;
                }

                r.push_back(s[j]);
                j--;
            }
        }

        return r;
    }
};