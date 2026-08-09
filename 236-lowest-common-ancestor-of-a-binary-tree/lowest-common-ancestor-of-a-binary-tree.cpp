class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void dfs(TreeNode* root, TreeNode* par = NULL) {
        if (root == NULL)
            return;

        parent[root] = par;

        dfs(root->left, root);
        dfs(root->right, root);
    }

    vector<TreeNode*> path(TreeNode* v) {
        vector<TreeNode*> ans;

        while (v != NULL) {
            ans.push_back(v);
            v = parent[v];
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root);

        vector<TreeNode*> path_p = path(p);
        vector<TreeNode*> path_q = path(q);

        int minLen = min(path_p.size(), path_q.size());

        TreeNode* lca = NULL;

        for (int i = 0; i < minLen; i++) {
            if (path_p[i] == path_q[i]) {
                lca = path_p[i];
            } 
            else {
                break;
            }
        }

        return lca;
    }
};