class Solution {
public:

    vector<pair<int,int>> movements = {
        {0,1},
        {0,-1},
        {1,0},
        {-1,0}
    };

    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    vector<vector<int>> bfs(vector<vector<int>>& mat) {

        queue<pair<int,int>> q;

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));

        // Put all 0s into the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(mat[i][j] == 0) {
                    q.push({i,j});
                    dist[i][j] = 0;
                }
            }
        }

        // Multi-source BFS
        while(!q.empty()) {

            auto v = q.front();
            q.pop();

            int v_x = v.first;
            int v_y = v.second;

            for(auto movement : movements) {

                int nx = movement.first + v_x;
                int ny = movement.second + v_y;

                if(isValid(nx, ny, n, m)) {

                    if(dist[nx][ny] == -1) {

                        dist[nx][ny] = dist[v_x][v_y] + 1;

                        q.push({nx, ny});
                    }
                }
            }
        }

        return dist;
    }

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs(mat);
    }
};