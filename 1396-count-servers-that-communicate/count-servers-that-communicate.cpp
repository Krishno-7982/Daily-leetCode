
class Solution {
public:
    int parent[62505];
    int sz[62505];

    void make(int v){
        parent[v] = v;
        sz[v] = 1;
    }

    int find(int v){
        if(v == parent[v]) return v;
        return parent[v] = find(parent[v]);
    }

    void Union(int a, int b){
        a = find(a);
        b = find(b);

        if(a == b) return;

        if(sz[a] < sz[b]){
            swap(a, b);
        }

        parent[b] = a;
        sz[a] += sz[b];
    }

    int countServers(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> num(n, vector<int>(m, 0));

        int k = 1;

        // Give every server a unique DSU id
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    num[i][j] = k;
                    make(k);
                    k++;
                }
            }
        }

        // Connect servers in the same row
        vector<int> row(n, -1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){

                    if(row[i] == -1){
                        row[i] = num[i][j];
                    }
                    else{
                        Union(row[i], num[i][j]);
                    }
                }
            }
        }

        // Connect servers in the same column
        vector<int> col(m, -1);

        for(int j = 0; j < m; j++){
            for(int i = 0; i < n; i++){
                if(grid[i][j] == 1){

                    if(col[j] == -1){
                        col[j] = num[i][j];
                    }
                    else{
                        Union(col[j], num[i][j]);
                    }
                }
            }
        }

        // Count servers belonging to a component of size > 1
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int id = num[i][j];

                    if(sz[find(id)] > 1){
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};
