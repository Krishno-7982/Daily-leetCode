class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;
        for(int i=0;i<nums.size()-1;i++){
            int avg = accumulate(nums.begin() + i + 1, nums.end(), 0)
          / (n - i - 1);
            if(nums[i]>avg){
                ct++;
            }
        }
        return ct;
    }
};