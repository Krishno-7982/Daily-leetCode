class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<string, int>mp;
        for(int i=0;i<words.size();i++){
            mp[words[i]]++;
            
        }
        int ct = 0;
        for(int i=0;i<words.size();i++){
            mp[words[i]] = 0;
            reverse(words[i].begin(), words[i].end());
            string s = words[i];
            if(mp[s]>0){
                ct++;
                mp[s] = 0;
            }
        }
        return ct;
    }
};