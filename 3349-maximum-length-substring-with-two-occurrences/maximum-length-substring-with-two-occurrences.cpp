class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0, maxlength = 0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            while(mp[s[i]]>2){
                mp[s[left]]--;
                left++;
               
            }
            maxlength=max(maxlength, i-left+1);
        }
        return maxlength;
    }
};