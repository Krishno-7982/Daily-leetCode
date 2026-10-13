
class Solution {
public:
    int pathSum(TreeNode* root, int digit_sum) {
        if (root == nullptr) {
            return 0;
        }

        digit_sum = digit_sum * 10 + root->val;

        if (root->left == nullptr && root->right == nullptr) {
            return digit_sum;
        }

        return pathSum(root->left, digit_sum)
             + pathSum(root->right, digit_sum);
    }

    int sumNumbers(TreeNode* root) {
        return pathSum(root, 0);
    }
};
