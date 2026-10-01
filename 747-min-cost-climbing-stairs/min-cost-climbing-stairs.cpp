class Solution {
public:
    int func(int i, vector<int>& cost, vector<int>& dp) {
        if(i == 0 || i == 1)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int oneStep = func(i-1, cost, dp) + cost[i-1];
        int twoStep = func(i-2, cost, dp) + cost[i-2];

        return dp[i] = min(oneStep, twoStep);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n+1, -1);

        return func(n, cost, dp);
    }
};