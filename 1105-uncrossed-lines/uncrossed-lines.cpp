class Solution {
public:
    int dp[505][505];

    int func(int i, int j, vector<int>& nums1, vector<int>& nums2) {

        if(i < 0 || j < 0)
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;

        // Don't take nums1[i]
        ans = max(ans, func(i-1, j, nums1, nums2));

        // Don't take nums2[j]
        ans = max(ans, func(i, j-1, nums1, nums2));

        // Take both if they are equal
        if(nums1[i] == nums2[j]) {
            ans = max(ans,
                     func(i-1, j-1, nums1, nums2) + 1);
        }

        return dp[i][j] = ans;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        memset(dp, -1, sizeof(dp));

        return func(nums1.size()-1,
                    nums2.size()-1,
                    nums1, nums2);
    }
};