
class Solution {
public:
    int dp[105];

    int func(int idx, int start, vector<int>& nums) {
        if(idx < start) return 0;

        if(dp[idx] != -1) return dp[idx];

        int ans = func(idx - 1, start, nums);

        ans = max(ans, func(idx - 2, start, nums) + nums[idx]);

        return dp[idx] = ans;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        memset(dp, -1, sizeof(dp));
        int case1 = func(n - 2, 0, nums);

        memset(dp, -1, sizeof(dp));
        int case2 = func(n - 1, 1, nums);

        return max(case1, case2);
    }
};
