class Solution {
public:
    vector<pair<int, int>> movements = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}
    };

    bool isValid(int x, int y, int n, int m) {
        return x >= 0 && y >= 0 && x < n && y < m;
    }

    int bfs(vector<vector<int>>& grid, int n, int m) {
        queue<pair<int, int>> q;
        int fresh = 0;
        int steps = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            while (sz--) {
                auto v = q.front();
                q.pop();

                for (auto movement : movements) {
                    int x = v.first + movement.first;
                    int y = v.second + movement.second;

                    if (!isValid(x, y, n, m)) continue;

                    if (grid[x][y] == 1) {
                        grid[x][y] = 2;
                        fresh--;
                        q.push({x, y});
                    }
                }
            }

            steps++;
        }

        return fresh == 0 ? steps : -1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        return bfs(grid, n, m);
    }
};