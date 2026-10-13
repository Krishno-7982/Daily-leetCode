class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        queue<int>q1, q2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                nums[i]*=-1;
            }
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        int n = nums.size();
        int i = n-1;
        while(i>=n/2){
            sum += (nums[i]*nums[i]);
            i--;
        }
        while(i>=0){
            sum -= (nums[i]*nums[i]);
            i--;
        }

        return sum;
    }
};