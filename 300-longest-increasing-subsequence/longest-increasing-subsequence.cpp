class Solution {
public:
    int lis(int i, vector<int>& dp, vector<int>& nums){
        if(dp[i]!=-1) return dp[i];
        int ans = 1;
        for(int j=0;j<i;j++){
            if(nums[i]>nums[j]){
                ans = max(ans, lis(j,dp,nums)+1);
            }
        }
        return dp[i]=ans;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max(ans, lis(i,dp,nums));
        }
        return ans;
    }
};