class Solution {
public:
    int passwordStrength(string password) {
        int sum = 0;
        set<char>st;
        for(auto c : password){
            st.insert(c);
        }
        // unordered_set<char>st = {'!','@','#','$'};
        for(auto ch : st){
            if(isalpha(ch)){
                if(islower(ch)){
                    sum++;
                }else{
                    sum+=2;
                }
            }else if(isdigit(ch)){
                sum += 3;
            }else{
                sum += 5;
            }
        }
        return sum;
    }
};