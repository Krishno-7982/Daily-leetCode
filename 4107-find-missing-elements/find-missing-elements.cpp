class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;

        int i = *min_element(nums.begin(), nums.end());
        int j = *max_element(nums.begin(), nums.end());

        unordered_set<int> st;
        for (int val : nums) {
            st.insert(val);
        }

        while (i <= j) {
            if (st.find(i) == st.end()) {  
                ans.push_back(i);
            }
            i++;
        }

        return ans;
    }
};