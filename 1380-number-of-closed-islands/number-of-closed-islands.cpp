class Solution {
public:
    int n, m;
    vector<pair<int, int>>movements = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };
    bool isValid(int x, int y){
        return x>=0 && y>=0 && x<n && y<m;
    }
    void dfs(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& visited){
        
        visited[x][y] = 1;
        for(auto movement : movements){
            int nx = x + movement.first;
            int ny = y + movement.second;
            if(!isValid(nx, ny))continue;
            if(!visited[nx][ny] && grid[nx][ny] == 0)
            dfs(nx, ny, grid, visited);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>visited(n, vector<int>(m, 0));
        for(int j = 0;j<m;j++){
            if(grid[0][j] == 0){
                dfs(0, j, grid, visited);
            }
            if(grid[n-1][j] == 0){
                dfs(n-1, j, grid, visited);
            }
            
        }
        for(int i = 1;i<n-1;i++){
            if(grid[i][0] == 0){
                dfs(i, 0, grid, visited);
            }
            if(grid[i][m-1] == 0){
                dfs(i, m-1, grid, visited);
            }            
        }
        int ct = 0;
        for(int i=1;i<n-1;i++){
            for(int j = 1;j<m-1;j++){
                if(grid[i][j] == 0 && visited[i][j]==0){
                    dfs(i, j, grid, visited);
                    ct++;
                }
            }
        }
        return ct;
    }
};