class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,int>symbols = {{'(',1},{'{',2},{'[',3},{')',-1},{'}',-2},{']',-3}};
        stack<char> st;
        for(auto bracket : s){
            if(symbols[bracket]>0){
                st.push(bracket);
            }else{
                if(st.empty())return false;
                char c = st.top();
                st.pop();
                if(symbols[c] + symbols[bracket] != 0) return false;
            }
        }
        if(st.empty())return true;
        return false;
    }
};