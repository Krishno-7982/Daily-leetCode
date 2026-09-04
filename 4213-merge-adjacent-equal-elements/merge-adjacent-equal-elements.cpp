class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        stack<long long>st;
        
        for(int i=0;i<nums.size();i++){
            st.push(nums[i]);
            while(st.size()>=2){
                long long x = st.top();
                st.pop();

                long long y = st.top();

                if (x == y) {
                    st.pop();
                    st.push(x + y);
                } else {
                    st.push(x);
                    break;
                }
            }
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};