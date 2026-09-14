
class Solution {
public:
    int dp[205][20005];

    bool func(int idx, int sum, vector<int>& nums) {
        if (sum == 0) {
            return true;
        }

        if (idx < 0) {
            return false;
        }

        if (dp[idx][sum] != -1) {
            return dp[idx][sum];
        }

        // Don't take nums[idx]
        bool isPossible = func(idx - 1, sum, nums);

        // Take nums[idx]
        if (sum - nums[idx] >= 0) {
            isPossible |= func(idx - 1, sum - nums[idx], nums);
        }

        return dp[idx][sum] = isPossible;
    }

    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum % 2 != 0) {
            return false;
        }

        sum /= 2;

        return func(nums.size() - 1, sum, nums);
    }
};

