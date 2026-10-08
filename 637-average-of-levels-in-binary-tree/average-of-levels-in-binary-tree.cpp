class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> v;
        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()) {
            int sz = q.size();
            double sum = 0.0;

            int count = sz;

            while(sz--) {
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left != nullptr) {
                    q.push(temp->left);
                }

                if(temp->right != nullptr) {
                    q.push(temp->right);
                }
            }

            v.push_back(sum / count);
        }

        return v;
    }
};