class Solution {
public:
    vector<int> lev;

    void bfs(TreeNode* root) {
        if (root == nullptr) return;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int lev_size = q.size();
            int sum = 0;

            for (int i = 0; i < lev_size; i++) {

                TreeNode* node = q.front();
                q.pop();

                sum += node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }

                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }

            // Current level is completely processed
            lev.push_back(sum);
        }
    }

    int maxLevelSum(TreeNode* root) {
        bfs(root);

        return max_element(lev.begin(), lev.end()) - lev.begin() + 1;
    }
};