
class Solution {
public:
    int m, n;
    int min_xor = INT_MAX;

    vector<pair<int, int>> movements = {{1, 0}, {0, 1}};

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    void dfs(int x, int y, int currXor,
             vector<vector<int>>& grid,
             vector<vector<vector<int>>>& visited) {

        currXor ^= grid[x][y];

        if (visited[x][y][currXor]) return;
        visited[x][y][currXor] = 1;

        if (x == m - 1 && y == n - 1) {
            min_xor = min(min_xor, currXor);
            return;
        }

        for (auto movement : movements) {
            int nx = x + movement.first;
            int ny = y + movement.second;

            if (!isValid(nx, ny)) continue;

            dfs(nx, ny, currXor, grid, visited);
        }
    }

    int minCost(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        min_xor = INT_MAX;

        vector<vector<vector<int>>> visited(
            m, vector<vector<int>>(n, vector<int>(1024, 0))
        );

        dfs(0, 0, 0, grid, visited);

        return min_xor;
    }
};
