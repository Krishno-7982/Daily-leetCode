
class Solution {
public:
    int ans = 0;

    vector<vector<pair<int, int>>> g;
    int vis[50005];

    void dfs(int node, int parent) {
        vis[node] = 1;

        for (auto nei : g[node]) {
            if (vis[nei.first]) continue;

            if (nei.second == 1) {
                ans++;
            }

            dfs(nei.first, node);
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        g.clear();
        g.resize(n);
        ans = 0;
        memset(vis, 0, sizeof(vis));

        for (auto& connection : connections) {
            int x = connection[0];
            int y = connection[1];

            g[x].push_back({y, 1});
            g[y].push_back({x, 0});
        }

        dfs(0, -1);
        return ans;
    }
};
