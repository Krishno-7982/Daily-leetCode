class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int>st;
        for(int i=0;i<nums.size();i++){
            string s = to_string(nums[i]);
            reverse(s.begin(), s.end());
            st.insert(nums[i]);
            st.insert(stoi(s));
        }
        return st.size();
    }
};