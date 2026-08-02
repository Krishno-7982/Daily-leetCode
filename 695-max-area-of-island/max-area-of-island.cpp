class Solution {
public:
    bool vis[55][55];
    int sum;

    void dfs(int i, int j, vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        if (grid[i][j] == 0)
            return;

        if (vis[i][j])
            return;

        vis[i][j] = true;
        sum++;

        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(vis, false, sizeof(vis));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    sum = 0;
                    dfs(i, j, grid);
                    ans = max(ans, sum);
                }
            }
        }

        return ans;
    }
};