class Solution {
public:
    bool checkOnesSegment(string s) {
        int ct = 1;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                ct++;
            }
        }
        return ct==1;
    }
};