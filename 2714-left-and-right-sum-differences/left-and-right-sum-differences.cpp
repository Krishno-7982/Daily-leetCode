class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int left_sum = 0;
        int total_sum = accumulate(nums.begin(), nums.end(),0);
        vector<int>ans;
        for(int i = 0;i<nums.size();i++){
            int right_sum = total_sum - nums[i]- left_sum;
            ans.push_back(abs(right_sum-left_sum));
            left_sum +=nums[i];
        }
        return ans;
    }
};