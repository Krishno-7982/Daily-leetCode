class Solution {
public:
    const int N = 310;
    bool vis[310][310];

    void dfs(int i, int j, vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Boundary check
        if (i < 0 || j < 0 || i >= n || j >= m)
            return;

        // If water or already visited, stop
        if (grid[i][j] == '0' || vis[i][j])
            return;

        // Mark current cell as visited
        vis[i][j] = true;

        // Visit all four directions
        dfs(i - 1, j, grid); // Up
        dfs(i + 1, j, grid); // Down
        dfs(i, j - 1, grid); // Left
        dfs(i, j + 1, grid); // Right
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        memset(vis, false, sizeof(vis));

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    dfs(i, j, grid);
                    count++;
                }
            }
        }

        return count;
    }
};