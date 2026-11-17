class Solution {
public:
    vector<int> ans;
    int prev = INT_MIN;
    int count = 0;
    int maxCount = 0;

    void inorder(TreeNode* root) {
        if(root == NULL) return;

        inorder(root->left);

        if(root->val == prev) {
            count++;
        }
        else {
            count = 1;
        }

        if(count > maxCount) {
            maxCount = count;
            ans.clear();
            ans.push_back(root->val);
        }
        else if(count == maxCount) {
            ans.push_back(root->val);
        }

        prev = root->val;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;
    }
};