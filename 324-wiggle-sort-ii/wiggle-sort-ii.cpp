class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        // Step 1: Sort the array
        sort(nums.begin(), nums.end());

        // Step 2: Reverse the first half
        if (n % 2 == 0) {
            reverse(nums.begin(), nums.begin() + n / 2);
        } else {
            reverse(nums.begin(), nums.begin() + n / 2 + 1);
        }

        // Step 3: Fill the answer array alternately
        int i = 0;
        int j = n - 1;

        for (int k = 0; k < n; k++) {
            if (k % 2 == 0) {
                ans[k] = nums[i++];
            } else {
                ans[k] = nums[j--];
            }
        }

        // Step 4: Copy the result back to nums
        for (int i = 0; i < n; i++) {
            nums[i] = ans[i];
        }
    }
};