class Solution {
public:
    int maxDifference(string s) {
        vector<int>hsh(26,0);
        for(int i=0;i<s.size();i++){
            hsh[s[i]-'a']++;
        }
        int minEven = INT_MAX;
        int maxOdd = INT_MIN;
        for(int i=0;i<26;i++){
            if(hsh[i]==0)continue;
            else if(hsh[i]%2!=0){
                maxOdd = max(maxOdd,hsh[i]);
            }else{
                minEven = min(minEven,hsh[i]);
            }
        }
        return maxOdd-minEven;
    }
};