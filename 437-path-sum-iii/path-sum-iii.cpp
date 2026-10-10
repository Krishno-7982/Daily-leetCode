/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, long long sum, int targetSum){
        if(root == nullptr) return;
        sum += root->val;
        if(sum == targetSum){
            ans++;
        }
        dfs(root->left, sum, targetSum);
        dfs(root->right, sum, targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) return 0;
        dfs(root, 0, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }
};