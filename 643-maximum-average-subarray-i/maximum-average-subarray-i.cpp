class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        vector<int>pf(nums.size()+1,0);
        for(int i=0;i<nums.size();i++){
            pf[i+1] = pf[i]+nums[i];
        }
        int i=1, j = k;
        double maxVal = (pf[k] - pf[0]) / (double)k;

        while(j<pf.size()){
            maxVal = max(maxVal, (pf[j]-pf[i-1])/(double)k);
            i++;
            j++;
        }
        return maxVal;
    }
};