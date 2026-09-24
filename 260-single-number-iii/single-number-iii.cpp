class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long u_nums = 0;
        for(int i=0;i<nums.size();i++){
            u_nums ^= nums[i];
        }
        int mask = u_nums & -u_nums;
        int first_u = 0;
        int second_u = 0;
        for(int i=0;i<nums.size();i++){
            if(mask&nums[i]){
                first_u ^= nums[i];
            }else{
                second_u ^= nums[i];
            }
        }
        return {first_u, second_u};
    }
};