class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        vector<bool> c(26, false);

        for(auto ch : allowed){
            c[ch - 'a'] = true;
        }

        int ct = 0;

        for(int i = 0; i < words.size(); i++){
            int f = 0;

            for(int j = 0; j < words[i].size(); j++){
                if(!c[words[i][j] - 'a']){
                    f = 1;
                    break;
                }
            }

            if(f == 0)
                ct++;
        }

        return ct;
    }
};