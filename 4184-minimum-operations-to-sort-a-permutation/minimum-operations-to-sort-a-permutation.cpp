class Solution {
public:
    int check(vector<int>& nums) {
        int n = nums.size();
        int idx = min_element(nums.begin(), nums.end()) - nums.begin();

        for (int i = 0; i < n; i++) {
            if (nums[(idx + i) % n] != i)
                return -1;
        }

        return idx;
    }

    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;

        // Case 1: Rotations only, or two reversals
        int r = check(nums);

        if (r != -1) {
            ans = min(r, n - r + 2);
        }

        // Case 2: One reversal and rotations
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());

        r = check(rev);

        if (r != -1) {
            ans = min(ans, min(r + 1, n - r + 1));
        }

        return ans == INT_MAX ? -1 : ans;
    }
};