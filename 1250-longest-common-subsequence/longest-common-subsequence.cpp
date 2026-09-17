class Solution {
public:
    int dp[1005][1005];

    int func(int i, int j, string &text1, string &text2) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Remove one character from text1
        ans = max(ans, func(i - 1, j, text1, text2));

        // Remove one character from text2
        ans = max(ans, func(i, j - 1, text1, text2));

        // If characters match
        ans = max(ans,
                func(i - 1, j - 1, text1, text2)
                + (text1[i] == text2[j]));

        return dp[i][j] = ans;
    }

    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return func(text1.size() - 1, text2.size() - 1, text1, text2);
    }
};