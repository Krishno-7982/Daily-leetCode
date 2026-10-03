class Solution {
public:
    vector<pair<int, int>> movements = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bool isValid(int x, int y, int n, int m) {
        return x < n && x >= 0 && y < m && y >= 0;
    }

    void bfs(vector<vector<int>>& grid, int n, int m) {
        queue<pair<int, int>> q;

        // Left and right boundary
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }

            if(grid[i][m-1] == 1) {
                q.push({i, m-1});
                grid[i][m-1] = 0;
            }
        }

        // Top and bottom boundary
        for(int j = 1; j < m-1; j++) {
            if(grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }

            if(grid[n-1][j] == 1) {
                q.push({n-1, j});
                grid[n-1][j] = 0;
            }
        }

        // BFS
        while(!q.empty()) {
            auto v = q.front();
            q.pop();

            for(auto movement : movements) {
                int child_x = v.first + movement.first;
                int child_y = v.second + movement.second;

                if(!isValid(child_x, child_y, n, m))
                    continue;

                if(grid[child_x][child_y] == 1) {
                    q.push({child_x, child_y});
                    grid[child_x][child_y] = 0;
                }
            }
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        bfs(grid, n, m);

        int ct = 0;

        for(int i = 1; i < n-1; i++) {
            for(int j = 1; j < m-1; j++) {
                if(grid[i][j] == 1) {
                    ct++;
                }
            }
        }

        return ct;
    }
};