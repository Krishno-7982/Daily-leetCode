class Solution {
public:
    void dfs(int i, vector<vector<int>>& isConnected, vector<int>& vis,int n){
        vis[i] = 1;
        for(int j=0;j<n;j++){
            if(!vis[j]  && isConnected[i][j]==1){
                dfs(j, isConnected, vis, n);
                vis[j] = 1;
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ct = 0;
        vector<int>vis(n, 0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i, isConnected, vis, n);
                ct++;
            }
        }
        return ct;
    }
    
};