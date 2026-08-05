class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> lower;
        unordered_set<char> counted;

        for(char c : word) {
            if(islower(c))
                lower.insert(c);
        }

        int ct = 0;

        for(char c : word) {
            if(isupper(c)) {
                char x = tolower(c);

                if(lower.count(x) && !counted.count(x)) {
                    ct++;
                    counted.insert(x);
                }
            }
        }

        return ct;
    }
};