class Solution {
public:
    int n, m;
    long long sum = 0;

    vector<pair<int, int>> movements = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    void dfs(int x, int y, vector<vector<int>>& grid,
             vector<vector<int>>& visited) {

        visited[x][y] = 1;
        sum += grid[x][y];

        for (auto movement : movements) {
            int nx = x + movement.first;
            int ny = y + movement.second;

            if (!isValid(nx, ny)) continue;
            if (visited[nx][ny] || grid[nx][ny] == 0) continue;

            dfs(nx, ny, grid, visited);
        }
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty()) return 0;

        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] != 0) {
                    sum = 0;

                    dfs(i, j, grid, visited);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};