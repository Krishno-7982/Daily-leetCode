class Solution {
public:

    vector<pair<int, int>> movements = {
        {0, 1}, {0, -1},
        {1, 0}, {-1, 0},
        {1, 1}, {1, -1},
        {-1, 1}, {-1, -1}
    };

    bool isValid(int x, int y, int n,
                 vector<vector<int>>& grid) {

        return x >= 0 && y >= 0 &&
               x < n && y < n &&
               grid[x][y] != 1;
    }

    void bfs(int i, int j, int n,
             vector<vector<int>>& grid,
             vector<vector<int>>& lev,
             vector<vector<int>>& vis) {

        queue<pair<int, int>> q;

        q.push({i, j});

        vis[i][j] = 1;
        lev[i][j] = 1;

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(auto movement : movements) {

                int nx = movement.first + x;
                int ny = movement.second + y;

                if(!isValid(nx, ny, n, grid))
                    continue;

                if(vis[nx][ny])
                    continue;

                vis[nx][ny] = 1;

                lev[nx][ny] = lev[x][y] + 1;

                q.push({nx, ny});
            }
        }
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n = grid.size();

        
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<int>> lev(
            n, vector<int>(n, 0)
        );

        vector<vector<int>> vis(
            n, vector<int>(n, 0)
        );

        bfs(0, 0, n, grid, lev, vis);

        if(lev[n-1][n-1] == 0)
            return -1;

        return lev[n-1][n-1];
    }
};