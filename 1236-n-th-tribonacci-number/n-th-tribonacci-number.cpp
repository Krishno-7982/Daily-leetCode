class Solution {
public:
    static constexpr int N = 40;
    long long dp[N];

    long long func(int n) {
        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = func(n - 1) + func(n - 2) + func(n - 3);
    }

    int tribonacci(int n) {
        memset(dp, -1, sizeof(dp));

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        return func(n);
    }
};