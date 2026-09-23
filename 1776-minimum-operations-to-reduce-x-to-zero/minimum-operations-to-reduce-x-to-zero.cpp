
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = accumulate(nums.begin(), nums.end(), 0);
        int target = total - x;

        // We need to remove everything if target < 0
        if (target < 0) return -1;

        // If target == 0, we need to remove all elements
        if (target == 0) return n;

        int left = 0;
        int sum = 0;
        int longest = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            while (sum > target && left <= right) {
                sum -= nums[left];
                left++;
            }

            if (sum == target) {
                longest = max(longest, right - left + 1);
            }
        }

        if (longest == -1) return -1;

        return n - longest;
    }
};
