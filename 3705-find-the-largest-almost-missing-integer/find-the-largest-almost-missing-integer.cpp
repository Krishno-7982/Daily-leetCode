class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int, int> mp;

        // Count frequency of every number
        for (int x : nums) {
            mp[x]++;
        }

        // Case 1: k == 1
        if (k == 1) {
            int ans = -1;

            for (auto &[x, cnt] : mp) {
                if (cnt == 1) {
                    ans = max(ans, x);
                }
            }

            return ans;
        }

        // Case 2: k == n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // Case 3: 1 < k < n
        int ans = -1;

        if (mp[nums[0]] == 1) {
            ans = max(ans, nums[0]);
        }

        if (mp[nums[n - 1]] == 1) {
            ans = max(ans, nums[n - 1]);
        }

        return ans;
    }
};