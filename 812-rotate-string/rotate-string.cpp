class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;

        int n = s.size();

        while(n--) {
            char first = s[0];
            for(int i = 0; i < s.size() - 1; i++) {
                s[i] = s[i + 1];
            }
            s[s.size() - 1] = first;

            if(s == goal) return true;
        }

        return false;
    }
};