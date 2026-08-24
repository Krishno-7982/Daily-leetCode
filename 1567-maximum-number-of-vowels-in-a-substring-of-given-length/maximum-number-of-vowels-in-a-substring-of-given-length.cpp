class Solution {
public:
    int maxVowels(string s, int k) {
       
        queue<char>q;
        int ctvowels=0;
        int maxVowels = 0;
        for(int i=0;i<s.size();i++){
            q.push(s[i]);
            if(s[i]=='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                ctvowels++;
            }
            while(q.size()>k){
                char ch = q.front();
                q.pop();
                if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
                    ctvowels--;
                }
            }
            maxVowels = max(maxVowels, ctvowels);
        }
        return maxVowels;
    }
};