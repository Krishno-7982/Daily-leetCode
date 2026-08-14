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
    vector<vector<int>>order_level(TreeNode* root){
        vector<vector<int>>ans;
        if(root==nullptr) return ans;

        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>lev;
            for(int i=0;i<size;i++){
                TreeNode* curr = q.front();
                q.pop();
                lev.push_back(curr->val);
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right != nullptr){
                    q.push(curr->right);
                }
            }
            ans.push_back(lev);
        }
        return ans;
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>>level = order_level(root);
        vector<int>rsv;
        for(int i=0;i<level.size();i++){
            int x = level[i].size();
            rsv.push_back(level[i][x-1]);
        }
        return rsv;
    }
};