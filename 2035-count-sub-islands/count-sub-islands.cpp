
class Solution {
public:
    int m, n;
    vector<vector<int>> visited;

    vector<pair<int, int>> movements = {
        {1, 0}, {-1, 0}, {0, 1}, {0, -1}
    };

    bool isValid(int x, int y) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

    void dfs(int i, int j, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2, bool &isSubIsland) {

        visited[i][j] = 1;

        if(grid1[i][j] == 0)
            isSubIsland = false;

        for(auto movement : movements) {

            int ni = i + movement.first;
            int nj = j + movement.second;

            if(isValid(ni, nj) &&
               !visited[ni][nj] &&
               grid2[ni][nj] == 1) {

                dfs(ni, nj, grid1, grid2, isSubIsland);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {

        m = grid1.size();
        n = grid1[0].size();

        visited.assign(m, vector<int>(n, 0));

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(!visited[i][j] && grid2[i][j] == 1) {

                    bool isSubIsland = true;

                    dfs(i, j, grid1, grid2, isSubIsland);

                    if(isSubIsland)
                        ans++;
                }
            }
        }

        return ans;
    }
};
