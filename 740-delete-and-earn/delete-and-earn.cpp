class Solution {
public:
   
    int deleteAndEarn(vector<int>& nums) {
        int maxi = *(max_element(nums.begin(), nums.end()));
        vector<int>points(maxi+1, 0);
        for(auto x : nums){
            points[x] += x;
        }
        vector<int>dp(maxi+1, 0);
        dp[1] = points[1];
        for(int i=2;i<=maxi;i++){
            dp[i] = max(dp[i-1], dp[i-2]+points[i]);
        }
        return dp[maxi];
    }
};