class Solution {
public:

    int lev[110][110];

    vector<pair<int,int>> movements = {
        {1,0},
        {-1,0},
        {0,1},
        {0,-1}
    };

    bool isValid(int i, int j, int n, int m,
                 vector<vector<char>>& maze) {

        return i >= 0 && i < n &&
               j >= 0 && j < m &&
               maze[i][j] == '.';
    }

    int bfs(vector<vector<char>>& maze,
            int i, int j,
            vector<vector<int>>& vis,
            int n, int m) {

        queue<pair<int,int>> q;

        q.push({i,j});
        vis[i][j] = 1;
        lev[i][j] = 0;

        while(!q.empty()) {

            auto curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            for(auto movement : movements) {

                int nx = x + movement.first;
                int ny = y + movement.second;

                if(!isValid(nx, ny, n, m, maze))
                    continue;

                if(vis[nx][ny])
                    continue;

                
                vis[nx][ny] = 1;

                lev[nx][ny] = lev[x][y] + 1;

                
                if(nx == 0 || nx == n-1 ||
                   ny == 0 || ny == m-1) {

                    return lev[nx][ny];
                }

                q.push({nx, ny});
            }
        }

        return -1;
    }

    int nearestExit(vector<vector<char>>& maze,
                    vector<int>& entrance) {

        int n = maze.size();
        int m = maze[0].size();

        vector<vector<int>> vis(
            n, vector<int>(m, 0)
        );

        return bfs(
            maze,
            entrance[0],
            entrance[1],
            vis,
            n,
            m
        );
    }
};