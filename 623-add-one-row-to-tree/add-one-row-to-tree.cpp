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
    TreeNode* func(TreeNode* root, int value, int depth){
        if(depth==1){
            TreeNode* temp = new TreeNode(value);
            
            temp->left = root;
            return temp;

        }
        if(root == nullptr) return nullptr;
        if(depth == 2){
            TreeNode* l = new TreeNode(value);
            TreeNode* r = new TreeNode(value);
            l->left = root->left;
            r->right = root->right;

            root->left = l;
            root->right = r;
            return root;
        }
        func(root->left, value, depth-1);
        func(root->right, value, depth-1);
        return root;
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        return func(root, val, depth);
    }
};