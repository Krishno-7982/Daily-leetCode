class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char, int>mp;
        char ch = 'a';
        for(int i=26;i>=1;i--){
            mp[ch++] = i;
        }
        int sum = 0;
        for(int i=0;i<s.size();i++){
            sum += (mp[s[i]] * (i+1));
        }
        return sum;
    }
};