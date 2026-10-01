class Solution {
public:
    int dp[105];
    int func(int idx, vector<int>& nums){
        if(idx<0) return 0;
        if(dp[idx] != -1) return dp[idx];

        int ans = func(idx-1, nums);
        ans = max(ans, func(idx-2, nums)+nums[idx]);
        return dp[idx] = ans;
    }
    int rob(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return func(nums.size()-1, nums);
    }
};