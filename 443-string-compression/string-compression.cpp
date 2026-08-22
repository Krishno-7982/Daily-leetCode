class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0;
        for(int i=0;i<n;){
            char ch = chars[i];
            int j = i;
            while(j<n && chars[j]==ch){
                j++;
            }
            int cnt = j - i;
            chars[write++] = ch;
            if(cnt > 1){
                string num = to_string(cnt);
                for(auto c : num){
                    chars[write++] = c;
                }
            }
            i = j;
        }
        return write;
    }
};