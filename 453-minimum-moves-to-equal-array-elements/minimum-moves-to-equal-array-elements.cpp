class Solution {
public:
    int minMoves(vector<int>& nums) {
       int ans = 0;
       int n = nums.size();
       sort(nums.begin(), nums.end());
       for(int i=n-1;i>0;i--){
        ans += nums[i]-nums[0];
       }
       return ans; 
    }
};