class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<vector<int>>adj(n);
        vector<int>indegree(n, 0);
        for(auto node : richer){
            int u = node[0];
            int v = node[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i] = i;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int u = q.front();q.pop();
            for(auto v : adj[u]){
                if(quiet[ans[u]]<quiet[ans[v]]){
                    ans[v] = ans[u];
                }
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return ans;
    }
};