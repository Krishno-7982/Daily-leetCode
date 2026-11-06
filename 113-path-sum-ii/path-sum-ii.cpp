class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& paths,
             vector<int>& path, int currSum, int targetSum) {

        if(root == nullptr) return;

        currSum += root->val;
        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr) {
            if(currSum == targetSum) {
                paths.push_back(path);
            }
        }

        dfs(root->left, paths, path, currSum, targetSum);
        dfs(root->right, paths, path, currSum, targetSum);

        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> paths;
        vector<int> path;

        dfs(root, paths, path, 0, targetSum);

        return paths;
    }
};