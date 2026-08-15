class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int left = 0;

        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] >= nums[i + 1]) {
                left = i + 1;
            }

            ans = max(ans, i - left + 2);
        }

        return ans;
    }
};