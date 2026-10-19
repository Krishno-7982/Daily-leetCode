
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int lastInvalid = -1;
        int lastValid = -1;
        int ct = 0;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] > right) {
                lastInvalid = j;
            }

            if (nums[j] >= left && nums[j] <= right) {
                lastValid = j;
            }

            ct += max(0, lastValid - lastInvalid);
        }

        return ct;
    }
};
