class Solution {
public:

    int vis[105][105];

    vector<pair<int,int>> movements = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };

    bool is_valid(int x, int y, int n) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }

    void dfs(int x, int y, vector<vector<int>>& grid, int n,
             queue<pair<int,int>>& q) {

        if (!is_valid(x, y, n)) return;
        if (vis[x][y]) return;
        if (grid[x][y] == 0) return;

        vis[x][y] = 1;
        q.push({x, y});

        for (auto movement : movements) {
            int nx = x + movement.first;
            int ny = y + movement.second;

            dfs(nx, ny, grid, n, q);
        }
    }

    int bfs(vector<vector<int>>& grid, int n,
            queue<pair<int,int>>& q) {

        int level = 0;

        while (!q.empty()) {

            int sz = q.size();

            while (sz--) {

                auto [x, y] = q.front();
                q.pop();

                for (auto movement : movements) {

                    int nx = x + movement.first;
                    int ny = y + movement.second;

                    if (!is_valid(nx, ny, n))
                        continue;

                    if (vis[nx][ny])
                        continue;

                    // We reached the second island
                    if (grid[nx][ny] == 1)
                        return level;

                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }

            level++;
        }

        return -1;
    }

    int shortestBridge(vector<vector<int>>& grid) {

        int n = grid.size();

        memset(vis, 0, sizeof(vis));

        queue<pair<int,int>> q;

        // Find first island
        bool found = false;

        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) {

                    dfs(i, j, grid, n, q);

                    found = true;
                    break;
                }
            }
        }

        return bfs(grid, n, q);
    }
};