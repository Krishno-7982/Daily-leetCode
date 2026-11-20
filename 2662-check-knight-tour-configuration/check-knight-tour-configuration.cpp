
class Solution {
public:
    int n;

    vector<pair<int, int>> movements = {
        {2, 1}, {2, -1}, {-2, 1}, {-2, -1},
        {1, 2}, {-1, 2}, {1, -2}, {-1, -2}
    };

    bool isValid(int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < n;
    }

    bool bfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited) {

        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = 1;

        int num = 1;

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            // All numbers have been visited
            if(num == n * n) return true;

            for(auto movement : movements) {

                int nx = x + movement.first;
                int ny = y + movement.second;

                if(!isValid(nx, ny)) continue;

                if(visited[nx][ny]) continue;

                // Only visit the next required number
                if(grid[nx][ny] == num) {

                    visited[nx][ny] = 1;
                    q.push({nx, ny});

                    num++;
                    break;
                }
            }
        }

        return num == n * n;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {

        n = grid.size();

        if(grid[0][0] != 0) return false;

        vector<vector<int>> visited(
            n, vector<int>(n, 0)
        );

        return bfs(grid, visited);
    }
};
