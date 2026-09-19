class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total_sum = accumulate(nums.begin(), nums.end(), 0);
        int left = 0, right = total_sum;
        for(int i=0;i<nums.size();i++){
            if(i>0){
                left += nums[i-1];
            }
            right -= nums[i];
            if(left == right){
                return i;
            }
        }
        return -1;
    }
};