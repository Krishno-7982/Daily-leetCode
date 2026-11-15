class Solution {
public:
    int countConsistent(vector<int>& nums) {
        int n = nums.size();
        int ct = 0;

        for(int i = 0; i < n; i++) {
            int val = nums[i];
            int min_val = nums[i];

            for(int j = i; j < n; j++) {
                val &= nums[j];
                min_val = min(min_val, nums[j]);

                if(val == min_val) {
                    ct++;
                }
            }
        }

        return ct;
    }
};