class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>right_max(n);
        int curr_max = nums[n-1];
        for(int i=n-1;i>=0;i--){
            if(nums[i]>=curr_max){
                curr_max = nums[i];
                
            }
            right_max[i] = curr_max;
        }
        int  i = 0, j = 0;
        int ramp = 0;
        while(j<n){
            if(nums[i] <= right_max[j]){
                ramp = max(ramp, j-i);
                j++;
            }else{
                i++;
            }
        }
        return ramp;
    }
};