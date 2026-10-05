class Solution {
public:
    int func(int i, vector<int>& nums) {
        int next = nums[i];

        if (nums[i] == -1)
            return 0;

        nums[i] = -1;

        return 1 + func(next, nums);
    }

    int arrayNesting(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] != -1) {
                ans = max(ans, func(i, nums));
            }
        }

        return ans;
    }
};