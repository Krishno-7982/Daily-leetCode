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
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;

        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr){
                    return depth;
                }
                if(node->left!=nullptr){
                    q.push(node->left);
                
                }
                if(node->right !=nullptr){
                    q.push(node->right);
                }
            }
            depth++;
            
        }
        return depth;
    }
};