class Solution {
public:
    bool checkString(string s) {
        int n=s.size();
        int idx=n;
        for(int i=0;i<n;i++){
            if(s[i]=='b'){
                idx=i;
                break;
            }
        }
             int idx2=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='a'){
                idx2=i;
                break;
            }
        }
        return idx2<idx;
    }
};