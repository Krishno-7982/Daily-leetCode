class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& visited, int k) {
        queue<int> q;
        q.push(k);
        visited[k] = 1;

        while(!q.empty()) {
            int v = q.front();
            q.pop(); 

            for(auto child : adj[v]) {
                if(!visited[child]) {
                    q.push(child);
                    visited[child] = 1;
                }
            }
        }
    }
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto edge : invocations){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }
        vector<int>visited(n, 0);
        bfs(adj, visited, k);
        for(auto &it : invocations){
            int u = it[0];
            int v = it[1];
            if(!visited[u] && visited[v]){
                vector<int>ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};