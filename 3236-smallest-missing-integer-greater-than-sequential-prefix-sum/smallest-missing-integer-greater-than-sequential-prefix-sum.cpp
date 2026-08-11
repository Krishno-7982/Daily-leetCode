class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int i = 0;

        // Find the longest consecutive prefix
        while (i + 1 < nums.size() && nums[i + 1] == nums[i] + 1) {
            i++;
        }

        // Calculate sum of the prefix
        int sum = accumulate(nums.begin(), nums.begin() + i + 1, 0);

        // Store ALL elements
        unordered_set<int> st(nums.begin(), nums.end());

        // Find smallest integer >= sum which is not present
        while (st.count(sum)) {
            sum++;
        }

        return sum;
    }
};