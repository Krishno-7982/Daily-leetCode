
class Solution {
public:
    int m, n;

    vector<pair<int,int>> movements = {
        {0,1}, {0,-1}, {1,0}, {-1,0}
    };

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    bool bfs(vector<vector<int>>& grid, int health) {

        queue<tuple<int,int,int>> q;

        vector<vector<int>> visited(
            m, vector<int>(n, -1)
        );

        // Starting cell
        health -= grid[0][0];

        if(health < 1) return false;

        q.push({0, 0, health});
        visited[0][0] = health;

        while(!q.empty()) {

            auto [x, y, currHealth] = q.front();
            q.pop();

            if(x == m-1 && y == n-1) {
                return true;
            }

            for(auto movement : movements) {

                int nx = x + movement.first;
                int ny = y + movement.second;

                if(!isValid(nx, ny)) continue;

                int newHealth = currHealth - grid[nx][ny];

                if(newHealth < 1) continue;

                if(visited[nx][ny] >= newHealth) continue;

                visited[nx][ny] = newHealth;

                q.push({nx, ny, newHealth});
            }
        }

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        m = grid.size();
        n = grid[0].size();

        return bfs(grid, health);
    }
};
