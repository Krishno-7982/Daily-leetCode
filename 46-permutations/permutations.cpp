class Solution {
public:

    vector<vector<int>> ans;

    void backtrack(vector<int>& nums, vector<int>& path,
                   vector<bool>& used) {

        // Base case
        if (path.size() == nums.size()) {
            ans.push_back(path);
            return;
        }

        // Try every possible choice
        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            // Choose
            path.push_back(nums[i]);
            used[i] = true;

            // Explore
            backtrack(nums, path, used);

            // Undo
            path.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<int> path;
        vector<bool> used(nums.size(), false);

        backtrack(nums, path, used);

        return ans;
    }
};