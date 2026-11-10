
class Solution {
public:
    int dp[100005];

    int func(int i, vector<int>& costs) {

        if(i == 0) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        if(i-1 >= 0) {
            ans = min(ans, func(i-1, costs) + costs[i-1] + 1);
        }

        if(i-2 >= 0) {
            ans = min(ans, func(i-2, costs) + costs[i-1] + 4);
        }

        if(i-3 >= 0) {
            ans = min(ans, func(i-3, costs) + costs[i-1] + 9);
        }

        return dp[i] = ans;
    }

    int climbStairs(int n, vector<int>& costs) {

        memset(dp, -1, sizeof(dp));

        return func(n, costs);
    }
};
