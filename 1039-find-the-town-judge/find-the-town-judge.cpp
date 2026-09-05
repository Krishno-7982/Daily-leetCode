class Solution {
public:
    
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>>g(n+1);
        vector<int>indegree(n+1,0);
        for(auto &v : trust){
            int a = v[0];
            int b = v[1];
            g[a].push_back(b);
            indegree[b]++;
        }
        //graph[i].size() gives the outdegree of i(people);
        for(int i=1;i<=n;i++){
            if(g[i].size()==0 && indegree[i]==n-1){
                return i;
            }
        }
        return -1;
    }
    
};