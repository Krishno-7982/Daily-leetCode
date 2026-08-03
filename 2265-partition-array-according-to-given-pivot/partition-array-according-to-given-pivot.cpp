class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int ctless = 0, ctequal = 0;

        for (auto val : nums) {
            if (val < pivot)
                ctless++;
            else if (val == pivot)
                ctequal++;
        }

        vector<int> ans(nums.size());

        int i = 0;
        int j = ctless;
        int k = ctless + ctequal;

        for (auto val : nums) {
            if (val < pivot)
                ans[i++] = val;
            else if (val == pivot)
                ans[j++] = val;
            else
                ans[k++] = val;
        }

        return ans;
    }
};